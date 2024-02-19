//
// Created by strannyi_tip on 17.12.23.
//
#include "Graphics/ContactList.hpp"
#include "Component/EntitySchemaContainer.hpp"

Graphics::ContactList::ContactList(QWidget *parent):
grid_layout(new QGridLayout),
vbox_layout(new QVBoxLayout),
scroll(new QScrollArea),
scroll_widget(new QWidget)
{
    setObjectName("contact_list");
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    scroll_widget->setObjectName("contacts_scroll_widget");
    scroll_widget->setLayout(vbox_layout);
    scroll_widget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    scroll->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    vbox_layout->setContentsMargins({0,0,0,20});
    grid_layout->addWidget(scroll, 0, 0, 1, 1);
    grid_layout->setContentsMargins({0,0,0,0});

    setLayout(grid_layout);
}

Graphics::ContactList *Graphics::ContactList::addContact(Graphics::ContactListItem *contact) {
    list[contact->getID()] = contact;

    connect(contact, &Graphics::ContactListItem::signalRemoveRequest, this, &ContactList::slotContactRemove);
    connect(contact, &Graphics::ContactListItem::signalEraseRequest, this, &ContactList::slotContactErase);
    connect(contact, &Graphics::ContactListItem::signalAcceptRequest, this, &ContactList::slotContactAccept);
    connect(contact, &Graphics::ContactListItem::signalInfoRequest, this, &ContactList::slotContactInfo);
    connect(contact, &Graphics::ContactListItem::signalDoubleClicked, this, &ContactList::slotContactDoubleClicked);
    connect(contact, &Graphics::ContactListItem::signalReturnPressed, this, &ContactList::slotContactReturnPressed);
    connect(contact, &Graphics::ContactListItem::signalSelected, this, &ContactList::slotSelectContact);

    return this;
}

void Graphics::ContactList::removeContact(const int &contact_id) {
    if (list.contains(contact_id)) {
        delete list[contact_id];
    }
    updateLayout();
}

void Graphics::ContactList::updateLayout() {
    clearLayout();
    for (const auto &contact: list) {
        vbox_layout->addWidget(contact.second);
    }
    scroll_widget->setLayout(vbox_layout);
    scroll_widget->setFixedHeight((static_cast<int>(list.size())*30));
    scroll->setWidget(scroll_widget);
}

void Graphics::ContactList::clearLayout() {
    QLayoutItem *item;
    while (nullptr != (item = vbox_layout->takeAt(0))) {
        if (nullptr != item->widget()) {
            item->widget()->setParent(nullptr);
            item->widget()->deleteLater();
        }
    }
}

void Graphics::ContactList::slotContactRemove(const int &contact_id) {
    emit signalContactRemoveRequest(contact_id);
}

void Graphics::ContactList::slotContactErase(const int &contact_id) {
    emit signalContactEraseRequest(contact_id);
}

void Graphics::ContactList::slotContactAccept(const int &contact_id) {
    emit signalContactAcceptRequest(contact_id);
}

void Graphics::ContactList::slotContactInfo(const int &contact_id) {
    emit signalContactInfoRequest(contact_id);
}

void Graphics::ContactList::slotContactDoubleClicked(const int &contact_id) {
    emit signalContactDoubleClicked(contact_id);
}

void Graphics::ContactList::slotContactReturnPressed(const int &contact_id) {
    emit signalContactReturnPressed(contact_id);
}

int Graphics::ContactList::count() {
    return static_cast<int>(list.size());
}

void Graphics::ContactList::slotSelectContact(const int &contact_id) {
    for (const auto &contact: list) {
        if (contact.first == contact_id) {
            contact.second->select();
        } else {
            contact.second->unselect();
        }
    }
}

