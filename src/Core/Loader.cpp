//
// Created by strannyi_tip on 22.12.23.
//

#include <QDebug>
#include <QApplication>
#include <QScreen>

#include "Core/Loader.hpp"
#include "Core/MainWindow.hpp"

Core::Loader::Loader(QWidget *parent):
client(new SocketClient),
progress(new Graphics::LoadingProgress("Подключение..")),
grid_layout(new QGridLayout)
{
    setObjectName("loader");
    auto screen = qApp->screens()[0]->size();
    setGeometry({
        screen.width()/2 - 120,
        screen.height()/2 - 150,
        240,
        300
    });
    setWindowFlags(Qt::Window | Qt::FramelessWindowHint | Qt::CustomizeWindowHint);

    grid_layout->addWidget(progress, 0, 0, 1, 1);

    setLayout(grid_layout);
    connect(client, &SocketClient::signalConnectionError, this, &Loader::slotConnectionError);
}

void Core::Loader::load() {
    loadContacts();
}

void Core::Loader::loadContacts() {
    connect(client, &SocketClient::signalConnected, this, &Loader::slotConnected);
    if (!client->isConnected()) {
        client->connectToHost();
    }
    state_read_connection = connect(client, &SocketClient::signalDataReadedArray, this, &Loader::slotStateReadedArray);
    client->getState();
}

void Core::Loader::loadMessages() {
    progress->resetProgress();
    progress
            ->setTitle("Загрузка сообщений")
            ->setMinimum(0)
            ->setMaximum(json["messages"]);

    bytes_readed_connection = connect(client, &SocketClient::signalBytesReaded, progress, &Graphics::LoadingProgress::slotProgress);
    messages_read_connection = connect(client, &SocketClient::signalDataReadedArray, this,
                                       &Loader::slotMessagesReadedArray);
    client->getMessages();
    progress_connection = connect(progress, &Graphics::LoadingProgress::signalComplete, this, &Loader::slotMessagesReadedComplete);
}

void Core::Loader::slotStateReadedString(const QString &state) {
    json = nlohmann::json::parse(state.toStdString());
}

void Core::Loader::slotStateReadedArray(const QByteArray &state) {
    disconnect(state_read_connection);
    json = nlohmann::json::parse(state.toStdString());
    progress
            ->setTitle("Загрузка контактов")
            ->setMinimum(0)
            ->setMaximum(json["contacts"]);

    bytes_readed_connection = connect(client, &SocketClient::signalBytesReaded, progress, &Graphics::LoadingProgress::slotProgress);
    contacts_read_connection = connect(client, &SocketClient::signalDataReadedArray, this, &Loader::slotContactsReadedArray);
    progress_connection = connect(progress, &Graphics::LoadingProgress::signalComplete, this, &Loader::slotContactsReadedComplete);
    client->getContacts();
}

void Core::Loader::slotContactsReadedArray(const QByteArray &contacts) {
    //@TODO create push db logic
}

void Core::Loader::slotContactsReadedProgress(const qint64 &bytes) {
    emit signalDataReadedProgress(bytes);
}

void Core::Loader::slotMessagesReadedProgress(const qint64 &bytes) {
    emit signalDataReadedProgress(bytes);
}

void Core::Loader::slotContactsReadedComplete() {
    disconnect(contacts_read_connection);
    disconnect(bytes_readed_connection);
    disconnect(progress_connection);
    loadMessages();
}

void Core::Loader::slotConnectionError() {
    auto error_label = new QLabel("Ошибка подключения");
    auto exit_button = new QPushButton("Зайду позже");
    exit_button->setObjectName("styled_button");
    error_label->setObjectName("error_label");
    error_label->setAlignment(Qt::AlignCenter);
    grid_layout->addWidget(error_label, 1, 0, 1, 1, Qt::AlignBottom);
    grid_layout->addWidget(exit_button, 2, 0, 1, 1, Qt::AlignBottom);

    connect(exit_button, &QPushButton::clicked, [](){
        qApp->exit(EXIT_SUCCESS);
    });
}

void Core::Loader::slotConnected() {
    progress->setTitle("Подключено");
}

void Core::Loader::slotMessagesReadedArray(const QByteArray &messages) {
    //@TODO create push db logic
}

void Core::Loader::slotMessagesReadedComplete() {
    disconnect(messages_read_connection);
    disconnect(bytes_readed_connection);
    disconnect(progress_connection);
    close();
    Core::MainWindow::init()->show();
}

void Core::Loader::slotLoading() {
    load();
}

