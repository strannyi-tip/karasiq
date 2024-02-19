//
// Created by strannyi_tip on 23.11.23.
//

#ifndef CHATBODY_HPP
#define CHATBODY_HPP

#include <QGridLayout>

#include "ChatControlsAreaWidget.hpp"
#include "ChatMessagesAreaWidget.hpp"
#include "ChatOptionsWidget.hpp"
#include "CSSableWidget.hpp"

namespace Graphics
{
    class ChatBodyWidget final: public Graphics::CSSableWidget
    {
        Q_OBJECT
    public:
        explicit ChatBodyWidget(QWidget *parent = nullptr);
    private:
        QGridLayout *grid_layout;
        ChatMessagesAreaWidget *messages;
        ChatControlsAreaWidget *controls;
    public slots:
        void slotOpenDialogRequest(const int &contact_id);
    private slots:
        void slotSendMessageRequest(const QString &message);
    signals:
        void signalOpenDialogRequest(const int&, const QString&);
        void signalSendMessageRequest(const QString &message);
    };
}

#endif //CHATBODY_HPP
