//
// Created by strannyi_tip on 31.10.23.
//
#include <QDebug>
#include <QHostAddress>
#include <QAbstractSocket>
#include <QMessageBox>
#include "Core/SocketClient.hpp"
#include "Component/QtMethodLogger.hpp"
#include "Component/EntitySchemaContainer.hpp"
#include "Entity/SystemEntity.hpp"
#include "Component/EntitySchema.hpp"
#include "Core/Connection.hpp"

Core::SocketClient::SocketClient():
socket(new QTcpSocket(this))
{
    connect(socket, &QTcpSocket::connected, this, &Core::SocketClient::slotConnected);
    connect(socket, &QTcpSocket::disconnected, this, &Core::SocketClient::slotDisconnected);
    connect(socket, &QTcpSocket::readyRead, this, &Core::SocketClient::slotReadyRead);
    connect(socket, &QTcpSocket::errorOccurred, this, &Core::SocketClient::slotConnectionError);
    connect(socket, &QTcpSocket::bytesWritten, this, &Core::SocketClient::slotBytesWriten);
}

void Core::SocketClient::slotConnected() {
    emit signalConnected();
}

void Core::SocketClient::slotDisconnected() {
    emit signalDisconnected();
}

void Core::SocketClient::slotReadyRead() {
    emit signalChangeStatusMessage("чтение..");
    QByteArray buffer;
    char byte;
    while (socket->read(&byte, 1)) {
        emit signalBytesReaded(buffer.size());
        buffer.append(byte);
    }
    emit signalDataReadedString(buffer.data());
    emit signalDataReadedArray(buffer);
    emit signalChangeStatusMessage(QString::number(buffer.size()) + " байт прочитано");
    buffer.clear();
}
void Core::SocketClient::slotConnectionError(QAbstractSocket::SocketError error) {
    auto logger = new Component::QtMethodLogger;
    std::string message;
    switch (error) {
        case QAbstractSocket::ConnectionRefusedError:
            message = "В соединении отказано";
            break;
        case QAbstractSocket::RemoteHostClosedError:
            message = "Удаленный хост разорвал соединение";
            break;
        case QAbstractSocket::HostNotFoundError:
            message = "Хост не найден";
            break;
        case QAbstractSocket::SocketAccessError:
            message = "Socket: ошибка доступа";
            break;
        case QAbstractSocket::SocketResourceError:
            message = "Socket resource error";
            break;
        case QAbstractSocket::SocketTimeoutError:
            message = "Socket: время ожидания истекло";
            break;
        case QAbstractSocket::DatagramTooLargeError:
            message = "Datagram: слишком большие данные";
            break;
        case QAbstractSocket::NetworkError:
            message = "Ошибка соединения";
            break;
        case QAbstractSocket::SocketAddressNotAvailableError:
            message = "Socket: адрес недоступен";
            break;
        case QAbstractSocket::UnsupportedSocketOperationError:
            message = "Socket: неподдерживаемая операция";
            break;
        case QAbstractSocket::UnfinishedSocketOperationError:
            message = "Socket: операция не завершена";
            break;
        case QAbstractSocket::ProxyAuthenticationRequiredError:
            message = "Proxy: требуется авторизация";
            break;
        case QAbstractSocket::SslHandshakeFailedError:
            message = "Ssl: рукопожатие провалено";
            break;
        case QAbstractSocket::ProxyConnectionRefusedError:
            message = "Proxy: соединение разорвано";
            break;
        case QAbstractSocket::ProxyConnectionClosedError:
            message = "Proxy: соединение было закрыто";
            break;
        case QAbstractSocket::ProxyConnectionTimeoutError:
            message = "Proxy: истекло время ожидания";
            break;
        case QAbstractSocket::ProxyNotFoundError:
            message = "Proxy: не найдены";
            break;
        case QAbstractSocket::ProxyProtocolError:
            message = "Proxy: ошибка протокола";
            break;
        case QAbstractSocket::OperationError:
            message = "Ошибка операции";
            break;
        case QAbstractSocket::SslInternalError:
            message = "Ssl: внутренняя ошибка";
            break;
        case QAbstractSocket::SslInvalidUserDataError:
            message = "Ssl: некорректные данные пользователя";
            break;
        case QAbstractSocket::TemporaryError:
            message = "Временная ошибка";
            break;
        case QAbstractSocket::UnknownSocketError:
            message = "Socket: неизвестный сокет";
            break;
        case QAbstractSocket::AddressInUseError:
            message = "Socket: адрес уже используется";
            break;
    }
    logger->error(message);
    emit signalChangeStatusMessage(QString::fromStdString(message));
    emit signalConnectionError();
}

void Core::SocketClient::sendData(const QString &text) {
    QByteArray data;
    data.append(text.toUtf8());
    if (!socket->isWritable()) {
        emit signalChangeStatusMessage("для отправки данных необходимо подключиться");

        return;
    }
    socket->write(text.toStdString().c_str());
    data.clear();
    if (!socket->waitForReadyRead(CONNECTION_TIMEOUT)) {
        emit signalChangeStatusMessage("не удалось получить ответ: смотрите лог-файл");

        return;
    } else {
        emit signalChangeStatusMessage("ответ успешно получен");
    }
}

void Core::SocketClient::connectToHost() {
    auto system_schema = Component::EntitySchemaContainer::get(Entity::SystemEntity{});
    if (!system_schema.count<Entity::SystemEntity>()) {
        auto message = "не найдена запись для соединения. восстановлено по умолчанию";
        auto logger = new Component::QtMethodLogger;
        logger->critical(message);
        emit signalChangeStatusMessage(message);
        Component::EntitySchema::push(Entity::SystemEntity{
            1, "127.0.0.1", 44544
        });
    }
    auto system_entity = system_schema.get_pointer<Entity::SystemEntity>(1);
    if (system_entity)
    {
        if (!socket->isWritable()) {
            socket->connectToHost(QHostAddress(QString::fromStdString(system_entity->host)), system_entity->port);
        }
        if (!socket->waitForConnected(CONNECTION_TIMEOUT)) {
            emit signalChangeStatusMessage("не удалось установить соединение");
            emit signalDisconnected();
        } else {
            emit signalChangeStatusMessage("соединение установлено");
        }
    } else
    {
        emit signalChangeStatusMessage("отсутствуют данные для соединения");
    }
}

void Core::SocketClient::disconnect() {
    socket->disconnectFromHost();
    socket->close();
    emit signalChangeStatusMessage("соединение разорвано");
}

void Core::SocketClient::slotBytesWriten(qint64 count) {
    emit signalChangeStatusMessage(QString::number(count) + " байт отправлено");
    emit signalBytesWriten(count);
}

void Core::SocketClient::sendData(const QByteArray &bytes) {
    socket->write(bytes);
}

QByteArray Core::SocketClient::buildMessageByQByteArray(const char &head_byte, const QByteArray &data) {
    QByteArray final_data;
    final_data.append(head_byte);
    final_data.append(data);

    return final_data;
}

QByteArray Core::SocketClient::buildMessageByQString(const char &head_byte, const QString &data) {
    QByteArray final_data;
    final_data.append(head_byte);
    final_data.append(data.toUtf8());

    return final_data;
}

QByteArray Core::SocketClient::buildMessageByEmptyData(const char &head_byte) {
    QByteArray final_data;

    return final_data.append(head_byte);
}

bool Core::SocketClient::isConnected() {
    return socket->isWritable();
}

void Core::SocketClient::getState() {
    const auto message = buildMessageByEmptyData(Core::Connection::GET_STATE);
    socket->write(message);
}

void Core::SocketClient::getContacts() {
    const auto message = buildMessageByEmptyData(Core::Connection::GET_CONTACTS);
    socket->write(message);
}

void Core::SocketClient::getMessages() {
    const auto message = buildMessageByEmptyData(Core::Connection::GET_MESSAGES);
    socket->write(message);
}

void Core::SocketClient::sendMessage(const QString &message) {
    const auto data = buildMessageByQString(Core::Connection::SEND_MESSAGE, message);
    socket->write(data);
}

