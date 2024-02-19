//
// Created by strannyi_tip on 17.12.23.
//

#ifndef KARASIQ_CONTACTLIST_HPP
#define KARASIQ_CONTACTLIST_HPP

#include <QScrollArea>
#include "CSSableWidget.hpp"
#include "ContactListItem.hpp"
#include "Interface/Countable.hpp"

namespace Graphics
{
class ContactList final: public CSSableWidget, Interface::Countable
    {
        Q_OBJECT
    public:
        explicit ContactList(QWidget *parent = nullptr);
        ContactList *addContact(ContactListItem *contact);
        int count() override;
        void updateLayout();
private:
    std::map<int, ContactListItem*> list;
    QGridLayout *grid_layout;
    QVBoxLayout *vbox_layout;
    QScrollArea *scroll;
    QWidget *scroll_widget;
    void removeContact(const int &contact_id);
        void clearLayout();
    private slots:
        void slotContactDoubleClicked(const int &contact_id);
        void slotContactReturnPressed(const int &contact_id);
        void slotSelectContact(const int &contact_id);
    public slots:
        void slotContactRemove(const int &contact_id);
        void slotContactErase(const int &contact_id);
        void slotContactAccept(const int &contact_id);
        void slotContactInfo(const int &contact_id);
    signals:
        void signalContactRemoveRequest(const int&);
        void signalContactEraseRequest(const int&);
        void signalContactAcceptRequest(const int&);
        void signalContactInfoRequest(const int&);
        void signalContactDoubleClicked(const int&);
        void signalContactReturnPressed(const int&);
    };
}

#endif //KARASIQ_CONTACTLIST_HPP
