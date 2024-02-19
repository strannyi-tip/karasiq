//
// Created by strannyi_tip on 22.11.23.
//

#ifndef MAINWIDGET_HPP
#define MAINWIDGET_HPP

#include "CSSableWidget.hpp"
#include "StatusMessageWidget.hpp"
#include "WindowPanel.hpp"
#include "Core/SocketClient.hpp"
#include "View/ChatView.hpp"
#include "Graphics/MainMenu.hpp"
#include "View/SettingsView.hpp"

namespace Graphics
{
    class MainWidget final: public Graphics::CSSableWidget
    {
        Q_OBJECT
    public:
        explicit MainWidget(QWidget *parent = nullptr);
        void setParentPosition(const QPoint &point);
    private:
        QGridLayout *grid_layout;
        Graphics::WindowPanel *window_panel;
        View::ChatView *chat_view;
        Core::SocketClient *client;
        MainMenu *menu;
        View::SettingsView *settings;
    protected:
        void mousePressEvent(QMouseEvent* event) override;
    public slots:
        void slotExtendedStatusIndexChanged(const int &index);
        void slotOnlineStatusChanged(const int &index);
        void slotClientConnected();
        void slotClientDisconnected();
        void slotChangeGlobalStatusMessage(const QString &message);
        void slotToggleMenu();
        void slotCloseAppRequestAccept();
        void slotUpdateContactsList();
        void slotRestartAppRequest();
        void slotSendMessageAccept(const QString &message);
        void slotServerResponseAccepted(const QByteArray &data);
    signals:
        void signalExtendedStatusIndexResponse(const int&);
        void signalExtendedStatusTextResponse(const QString&);
        void signalOnlineStatusChangeRequest(const int&);
        void signalCloseAppRequest();
        void signalUpdateContactsList();
        void signalRestartAppRequest();
        void signalUpdateStatusMessage(const QString&);
    };
}

#endif //MAINWIDGET_HPP
