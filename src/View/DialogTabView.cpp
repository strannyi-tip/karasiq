//
// Created by strannyi_tip on 12.12.23.
//
#include "View/DialogTabView.hpp"
#include "Component/EntitySchemaContainer.hpp"
#include "Component/ChatMessageFactory.hpp"

View::DialogTabView::DialogTabView(QWidget *parent):
grid_layout(new QGridLayout),
vbox_layout(new QVBoxLayout),
no_messages_lbl(new QLabel),
scroll(new QScrollArea)
{
    setObjectName("dialog_view");
    no_messages_lbl->setObjectName("label");
    no_messages_lbl->setText("История сообщений пуста");
    no_messages_lbl->setAlignment(Qt::AlignCenter);

    grid_layout->setContentsMargins({0,0,0,0});
    scroll->setLayout(vbox_layout);
    grid_layout->addWidget(scroll);
    setLayout(grid_layout);
}

void View::DialogTabView::loadFromHistory(const int &contact_id) {
    auto schema = Component::EntitySchemaContainer::get(Entity::MessageEntity{});
    auto messages = schema.get_all<Entity::MessageEntity>(where(c(&Entity::MessageEntity::from_id) == contact_id || c(&Entity::MessageEntity::to_id) == contact_id));
    if (messages.empty()) {
        clearLayout();
        vbox_layout->addWidget(no_messages_lbl);
    } else {
        clearLayout();
        for (const auto &message:messages) {
            auto message_widget = Component::ChatMessageFactory::create(message);
            vbox_layout->addWidget(message_widget);
        }
    }
    vbox_layout->update();
}

void View::DialogTabView::slotUpdateDialog(const Entity::MessageEntity &entity) {
    auto message_widget = Component::ChatMessageFactory::create(entity);
    vbox_layout->addWidget(message_widget);
    vbox_layout->update();
}

void View::DialogTabView::clearLayout() {
    QLayoutItem *item;
    while ((item = vbox_layout->takeAt(0)) != nullptr) {
        if (item->widget() != nullptr) {
            item->widget()->setParent(nullptr);
            item->widget()->deleteLater();
        }
    }
}

