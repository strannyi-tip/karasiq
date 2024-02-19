//
// Created by strannyi_tip on 22.11.23.
//

#ifndef CHATVIEW_HPP
#define CHATVIEW_HPP


#include <QGridLayout>

#include "Graphics/ChatBodyWidget.hpp"
#include "Graphics/ChatContactsWidget.hpp"
#include "Graphics/CSSableWidget.hpp"
#include "Graphics/ContactSearchWidget.hpp"

namespace View
{
    class ChatView final: public Graphics::CSSableWidget
    {
        Q_OBJECT
    public:
        explicit ChatView(QWidget *parent = nullptr);
        [[nodiscard]] Graphics::ChatOptionsWidget *getOptions() const;
    private:
        QGridLayout *grid_layout;
        Graphics::ChatContactsWidget *contacts;
        Graphics::ChatBodyWidget *body;
        Graphics::ChatOptionsWidget *options;
    public slots:
        void slotExtendedStatusIndexChanged(const int &index);
        void slotOnlineStatusChanged(const int &index);
        void slotOnlineStatusChangeAccept(const int &index);
        void slotUpdateContactsList();
        void slotSendMessageAccept(const QString &message);
    signals:
        void signalExtendedStatusIndexChanged(const int&);
        void signalOnlineStatusChanged(const int&);
        void signalOnlineStatusChangeRequest(const int&);
        void signalUpdateContactsList();
        void signalSendMessageRequest(const QString &message);
    };
}

#endif //CHATVIEW_HPP
