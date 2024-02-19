//
// Created by strannyi_tip on 22.11.23.
//

#include <QDebug>
#include <QApplication>
#include <QMessageBox>

#include "Graphics/MainWidget.hpp"
#include "Core/Connection.hpp"

Graphics::MainWidget::MainWidget(QWidget* parent):
grid_layout(new QGridLayout),
window_panel(new Graphics::WindowPanel),
chat_view(new View::ChatView(this)),
client(new Core::SocketClient),
menu(new MainMenu),
settings(new View::SettingsView)
{
    setParent(parent);
    setObjectName("main_widget");
    grid_layout->setAlignment(Qt::AlignTop|Qt::AlignLeft);
    grid_layout->setContentsMargins({0,0,0,0});
    grid_layout->addWidget(window_panel, 0, 0, 1, 1);
    grid_layout->addWidget(menu, 1, 0, 1, 1);
    grid_layout->addWidget(settings, 1, 0, 1, 1);
    grid_layout->addWidget(chat_view, 1, 0, 1, 1);

    setLayout(grid_layout);

    menu
        ->addItem(new Graphics::MainMenuItem("settings", "настройки", QIcon(":/rsc/icons/menu/settings.png")), [this](){
                settings->animateOpen();
            })
        ->addItem(new Graphics::MainMenuItem("exit", "выход", QIcon(":/rsc/icons/menu/exit.png")), [](){
            QMessageBox quit_question;
            quit_question.setText("выйти из приложения?");
            quit_question.setWindowFlags(Qt::Window | Qt::FramelessWindowHint | Qt::CustomizeWindowHint);
            QPushButton *cancel_button = quit_question.addButton("остаться", QMessageBox::AcceptRole);
            QPushButton *quit_button = quit_question.addButton("зайду в другой раз", QMessageBox::RejectRole);
            quit_button->setStyleSheet("color: #823e2d;");
            cancel_button->setObjectName("styled_button");
            quit_question.exec();
            if (quit_question.clickedButton() == quit_button) {
                qApp->exit(EXIT_SUCCESS);
            }
        })->addItem(new Graphics::MainMenuItem("relogin", "сменить пользователя", QIcon(":/rsc/icons/user.png")), [this](){
            settings->animateClose();
        });


    connect(chat_view, &View::ChatView::signalExtendedStatusIndexChanged, this, &MainWidget::slotExtendedStatusIndexChanged);
    connect(chat_view, &View::ChatView::signalOnlineStatusChanged, this, &MainWidget::slotOnlineStatusChanged);
    connect(this, &MainWidget::signalOnlineStatusChangeRequest, chat_view, &View::ChatView::slotOnlineStatusChangeAccept);
    connect(client, &Core::SocketClient::signalConnected, this, &MainWidget::slotClientConnected);
    connect(client, &Core::SocketClient::signalDisconnected, this, &MainWidget::slotClientDisconnected);
    connect(client, &Core::SocketClient::signalChangeStatusMessage, this, &MainWidget::slotChangeGlobalStatusMessage);
    connect(window_panel, &WindowPanel::signalToggleMenuRequest, this, &MainWidget::slotToggleMenu);
    connect(settings, &View::SettingsView::signalUpdateGlobalStatusMessage, this, &MainWidget::slotChangeGlobalStatusMessage);
    connect(this, &MainWidget::signalUpdateContactsList, chat_view, &View::ChatView::slotUpdateContactsList);
    connect(settings, &View::SettingsView::signalRestartAppRequest, this, &MainWidget::slotRestartAppRequest);
    connect(chat_view, &View::ChatView::signalSendMessageRequest, this, &MainWidget::slotSendMessageAccept);
    connect(client, &Core::SocketClient::signalDataReadedArray, this, &MainWidget::slotServerResponseAccepted);
    connect(this, &MainWidget::signalUpdateStatusMessage, window_panel, &Graphics::WindowPanel::slotChangeStatusMessage);

    emit signalExtendedStatusIndexResponse(3);
    emit signalExtendedStatusTextResponse("This is a extended status.");
}

void Graphics::MainWidget::setParentPosition(const QPoint& point)
{
    //menu->place(point);
}

void Graphics::MainWidget::mousePressEvent(QMouseEvent* event)
{
    CSSableWidget::mousePressEvent(event);
    menu->animateClose();
}

void Graphics::MainWidget::slotExtendedStatusIndexChanged(const int& index)
{

}

void Graphics::MainWidget::slotOnlineStatusChanged(const int& index)
{
    switch (index)
    {
        case 0:
            client->disconnect();
            break;
        case 1:
            client->connectToHost();
            break;
        default:
            break;
    }
}

void Graphics::MainWidget::slotClientConnected()
{
    emit signalOnlineStatusChangeRequest(1);
}

void Graphics::MainWidget::slotClientDisconnected()
{
    emit signalOnlineStatusChangeRequest(0);
}

void Graphics::MainWidget::slotChangeGlobalStatusMessage(const QString& message)
{
    emit signalUpdateStatusMessage(message);
}

void Graphics::MainWidget::slotToggleMenu()
{
    if (!menu->width()) {
        menu->animateOpen();
        settings->animateClose();
    } else {
        menu->animateClose();
    }
}

void Graphics::MainWidget::slotCloseAppRequestAccept()
{
    emit signalCloseAppRequest();
}

void Graphics::MainWidget::slotUpdateContactsList() {
    emit signalUpdateContactsList();
}

void Graphics::MainWidget::slotRestartAppRequest() {
    emit signalRestartAppRequest();
}

void Graphics::MainWidget::slotSendMessageAccept(const QString &message) {
    client->sendMessage(message);
}

void Graphics::MainWidget::slotServerResponseAccepted(const QByteArray &data) {
    if (Core::Connection::SEND_MESSAGE == data[0]) {
        qDebug() << "Входящее сообщение: " << data;
    }
}

