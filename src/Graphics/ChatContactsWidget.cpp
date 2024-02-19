//
// Created by strannyi_tip on 22.11.23.
//

#include "Graphics/ChatContactsWidget.hpp"
#include "Graphics/VSpase.hpp"
#include "Component/EntitySchemaContainer.hpp"
#include "Component/EntityFixture.hpp"

Graphics::ChatContactsWidget::ChatContactsWidget(QWidget* parent):
vbox_layout(new QVBoxLayout),
hbox_layout(new QHBoxLayout),
online_list(new DropDownList("в сети", ":/rsc/icons/user.png")),
offline_list(new DropDownList("не в сети", ":/rsc/icons/user.png")),
inbox_list(new DropDownList("запросы", ":/rsc/icons/user.png")),
search_input(new QLineEdit),
search_btn(new QToolButton),
list_group(new Graphics::ListGroup),
contacts_list(new Graphics::ContactList)
{
    setParent(parent);
    setObjectName("chat_contacts");
    setFixedWidth(220);

    search_btn->setIcon(QIcon(":/rsc/icons/search.png"));
    search_btn->setObjectName("search_button");
    search_btn->setFixedSize({30, 30});
    search_input->setObjectName("search_input");
    search_input->setPlaceholderText("поиск контактов");

    hbox_layout->setSpacing(0);
    hbox_layout->addWidget(search_input, 0, Qt::AlignBottom);
    hbox_layout->addWidget(search_btn, 0, Qt::AlignBottom);

    online_list->setName("online_contacts");
    offline_list->setName("offline_contacts");
    inbox_list->setName("inbox_contacts");

    contacts_list->setMinimumHeight(550);
    contacts_list->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    updateList();

    setLayout(vbox_layout);
}

void Graphics::ChatContactsWidget::slotContactDoubleClicked(const int &index) {
    emit signalContactClicked(index);
}

void Graphics::ChatContactsWidget::updateList() {
    Component::EntityFixture::fill(Entity::ContactEntity{}, 50);
    clearLayout();
    auto system_schema = Component::EntitySchemaContainer::get(Entity::SystemEntity{});
    auto system_entity = system_schema.get_pointer<Entity::SystemEntity>(1);
    if (system_entity) {
        auto contact_schema = Component::EntitySchemaContainer::get(Entity::ContactEntity{});
        auto online_contacts = contact_schema.get_all<Entity::ContactEntity>(where(c(&Entity::ContactEntity::is_online)  && c(&Entity::ContactEntity::is_in_list)));
        auto offline_contacts = contact_schema.get_all<Entity::ContactEntity>(where(c(&Entity::ContactEntity::is_online) == false && c(&Entity::ContactEntity::is_in_list)));
        auto inbox_contacts = contact_schema.get_all<Entity::ContactEntity>(where(c(&Entity::ContactEntity::is_in_list) == false));
        if (system_entity->is_group_contacts) {
            auto online_container = new ContactList;
            auto offline_container = new ContactList;
            auto inbox_container = new ContactList;

            for (const auto &contact:online_contacts) {
                auto item = new ContactListItem(contact);
                online_container->addContact(item);
            }
            online_container->updateLayout();
            for (const auto &contact:offline_contacts) {
                auto item = new ContactListItem(contact);
                offline_container->addContact(item);
            }
            offline_container->updateLayout();
            for (const auto &contact:inbox_contacts) {
                auto item = new ContactListItem(contact);
                inbox_container->addContact(item);
            }
            inbox_container->updateLayout();

            online_list->setList(online_container);
            offline_list->setList(offline_container);
            inbox_list->setList(inbox_container);

            list_group
                    ->addList(online_list)
                    ->addList(offline_list)
                    ->addList(inbox_list);

            vbox_layout->addWidget(online_list, 0, Qt::AlignTop);
            vbox_layout->addWidget(offline_list, 0, Qt::AlignTop);
            vbox_layout->addWidget(inbox_list, 0, Qt::AlignTop);

            connect(online_list, &Graphics::DropDownList::signalDoubleClicked, this, &ChatContactsWidget::slotContactDoubleClicked);
            connect(offline_list, &Graphics::DropDownList::signalDoubleClicked, this, &ChatContactsWidget::slotContactDoubleClicked);
            connect(contacts_list, &ContactList::signalContactDoubleClicked, this, &ChatContactsWidget::slotContactDoubleClicked);
        } else {
            for (const auto &contact: online_contacts) {
                auto item = new ContactListItem(contact);
                contacts_list->addContact(item);
            }
            for (const auto &contact: offline_contacts) {
                auto item = new ContactListItem(contact);
                contacts_list->addContact(item);
            }
            for (const auto &contact: inbox_contacts) {
                auto item = new ContactListItem(contact);
                contacts_list->addContact(item);
            }
            contacts_list->updateLayout();
            vbox_layout->addWidget(contacts_list, 0, Qt::AlignTop);
        }
        if (system_entity->is_show_list_counter) {
            online_list->setCounterType(DropDownButton::CounterType::Countable);
            offline_list->setCounterType(DropDownButton::CounterType::Countable);
            inbox_list->setCounterType(DropDownButton::CounterType::Countable);
        } else {
            online_list->setCounterType(DropDownButton::CounterType::Muted);
            offline_list->setCounterType(DropDownButton::CounterType::Muted);
            inbox_list->setCounterType(DropDownButton::CounterType::Muted);
        }
    }

    vbox_layout->update();
}

void Graphics::ChatContactsWidget::slotUpdateList() {
    updateList();
}

void Graphics::ChatContactsWidget::clearLayout() {
    auto item = vbox_layout->takeAt(0);
    if (nullptr != item) {
        item->widget()->setParent(nullptr);
        item->widget()->deleteLater();
    }
    vbox_layout->setSpacing(0);
    vbox_layout->addLayout(hbox_layout, 0);
    vbox_layout->addWidget((new Graphics::VSpase(5)), 0, Qt::AlignTop);
    vbox_layout->setContentsMargins({5,5,5,5});
    vbox_layout->setAlignment(Qt::AlignTop);
}
