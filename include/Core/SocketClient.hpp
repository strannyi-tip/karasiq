//
// Created by strannyi_tip on 31.10.23.
//

#ifndef IMIN_SOCKETCLIENT_HPP
#define IMIN_SOCKETCLIENT_HPP

#include <QObject>
#include <QTcpSocket>

namespace Core
{
    class SocketClient: public QObject
    {
        Q_OBJECT
    public:
        explicit SocketClient();
        void sendData(const QString &text);
        void sendData(const QByteArray &bytes);
        void connectToHost();
        void disconnect();
        QByteArray buildMessageByQByteArray(const char &head_byte, const QByteArray &data = {});
        QByteArray buildMessageByQString(const char &head_byte, const QString &data = {});
        QByteArray buildMessageByEmptyData(const char &head_byte);
        bool isConnected();
        void getState();
        void getContacts();
        void getMessages();
        void sendMessage(const QString &message);
    private:
        const char DELIMITER = 0x00;
        //static inline const QString ADDRESS = "85.209.9.97";
        static inline const int PORT = 44544;
        static inline const int CONNECTION_TIMEOUT = 5000;
        QTcpSocket *socket;
    public slots:
        void slotConnected();
        void slotDisconnected();
        void slotReadyRead();
        void slotConnectionError(QAbstractSocket::SocketError error);
        void slotBytesWriten(qint64 count);
    signals:
        void signalDataReadedString(const QString &data);
        void signalDataReadedArray(const QByteArray &data);
        void signalBytesReaded(const qint64 &count);
        void signalConnected();
        void signalDisconnected();
        void signalChangeStatusMessage(const QString &message);
        void signalBytesWriten(qint64);
        void signalConnectionError();
    };
}

#endif //IMIN_SOCKETCLIENT_HPP
