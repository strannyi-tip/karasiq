//
// Created by strannyi_tip on 23.11.23.
//

#include "Graphics/ChatBodyWidget.hpp"
#include "Component/EntitySchemaContainer.hpp"

Graphics::ChatBodyWidget::ChatBodyWidget(QWidget* parent):
grid_layout(new QGridLayout),
messages(new ChatMessagesAreaWidget),
controls(new ChatControlsAreaWidget)
{
    setParent(parent);
    setObjectName("chat_body");

    grid_layout->setContentsMargins({0,0,0,0});
    grid_layout->setSpacing(5);
    grid_layout->setAlignment(Qt::AlignLeft|Qt::AlignTop);

    grid_layout->addWidget(messages, 0, 0, 1, 1);
    grid_layout->addWidget(controls, 1, 0, 1, 1);

    setLayout(grid_layout);

    connect(this, &ChatBodyWidget::signalOpenDialogRequest, messages, &ChatMessagesAreaWidget::slotOpenDialog);
    connect(controls, &ChatControlsAreaWidget::signalSendMessageRequest, this, &ChatBodyWidget::slotSendMessageRequest);
}

void Graphics::ChatBodyWidget::slotOpenDialogRequest(const int &contact_id) {
    QString name = "undefined";
    auto schema = Component::EntitySchemaContainer::get(Entity::ContactEntity{});
    auto contact = schema.get_pointer<Entity::ContactEntity>(contact_id);
    if (contact) {
        name = QString::fromStdString(contact->name);
    }
    emit signalOpenDialogRequest(contact_id, name);
}

void Graphics::ChatBodyWidget::slotSendMessageRequest(const QString &message) {
    emit signalSendMessageRequest(message);
}
