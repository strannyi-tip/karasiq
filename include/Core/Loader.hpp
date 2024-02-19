//
// Created by strannyi_tip on 22.12.23.
//

#ifndef KARASIQ_LOADER_HPP
#define KARASIQ_LOADER_HPP

#include <nlohmann/json.hpp>
#include "Graphics/CSSableWidget.hpp"
#include "SocketClient.hpp"
#include "Graphics/LoadingProgress.hpp"

namespace Core
{
    class Loader final: public Graphics::CSSableWidget
    {
        Q_OBJECT
    public:
        explicit Loader(QWidget *parent = nullptr);
        void load();
    private:
        SocketClient *client;
        Graphics::LoadingProgress *progress;
        nlohmann::json json;
        QGridLayout *grid_layout;
        QMetaObject::Connection state_read_connection;
        QMetaObject::Connection contacts_read_connection;
        QMetaObject::Connection messages_read_connection;
        QMetaObject::Connection bytes_readed_connection;
        QMetaObject::Connection progress_connection;
        void loadContacts();
        void loadMessages();
    private slots:
        void slotStateReadedString(const QString &state);
        void slotStateReadedArray(const QByteArray &state);
        void slotContactsReadedArray(const QByteArray &contacts);
        void slotContactsReadedProgress(const qint64 &bytes);
        void slotMessagesReadedProgress(const qint64 &bytes);
        void slotMessagesReadedArray(const QByteArray &messages);
        void slotContactsReadedComplete();
        void slotMessagesReadedComplete();
        void slotConnectionError();
        void slotConnected();
    public slots:
        void slotLoading();
    signals:
        void signalDataReadedProgress(const qint64 &bytes);
    };
}

#endif //KARASIQ_LOADER_HPP
