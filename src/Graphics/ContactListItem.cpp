//
// Created by strannyi_tip on 17.12.23.
//
#include <QAction>

#include "Graphics/ContactListItem.hpp"

Graphics::ContactListItem::ContactListItem(const Entity::ContactEntity &contact_entity):
grid_layout(new QGridLayout),
name_lbl(new QLabel),
icon_status_btn(new QToolButton),
remove_btn(new QToolButton),
entity(contact_entity)
{
    setObjectName("contact_in_list");
    setFixedSize({205, 30});
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    grid_layout->setContentsMargins({5,5,5,5});
    name_lbl->setText(QString::fromStdString(contact_entity.name));
    name_lbl->setObjectName("label");
    icon_status_btn->setObjectName("impersonal");
    icon_status_btn->setFixedSize({12, 12});
    icon_status_btn->setIconSize({6, 6});
    if (!entity.is_in_list) {
        icon_status_btn->setIcon(QIcon(":/rsc/icons/status/inbox_round.png"));
    } else {
        if (entity.is_online) {
            icon_status_btn->setIcon(QIcon(":/rsc/icons/status/online_round.png"));
        } else {
            icon_status_btn->setIcon(QIcon(":/rsc/icons/status/offline_round.png"));
        }
    }
    remove_btn->setObjectName("styled_button");
    remove_btn->setFixedSize({12, 12});
    remove_btn->setIconSize({10, 10});
    remove_btn->setIcon(QIcon(":/rsc/icons/remove.png"));

    grid_layout->addWidget(icon_status_btn, 0, 0, 1, 1);
    grid_layout->addWidget(name_lbl, 0, 1, 1, 1);
    grid_layout->addWidget(remove_btn, 0, 2, 1, 1);

    setLayout(grid_layout);

    auto remove_action = new QAction("удалить контакт", this);
    auto erase_action = new QAction("очистить историю", this);
    auto accept_action = new QAction("принять запрос", this);
    auto info_action = new QAction("информация", this);

    if (!contact_entity.is_in_list) {
        addAction(accept_action);
    }
    addAction(remove_action);
    addAction(erase_action);
    addAction(info_action);

    connect(remove_action, &QAction::triggered, this, &ContactListItem::slotActionRemove);
    connect(erase_action, &QAction::triggered, this, &ContactListItem::slotActionErase);
    connect(accept_action, &QAction::triggered, this, &ContactListItem::slotActionAccept);
    connect(info_action, &QAction::triggered, this, &ContactListItem::slotActionInfo);
}

void Graphics::ContactListItem::slotActionRemove() {
    emit signalRemoveRequest(entity.id);
}

void Graphics::ContactListItem::slotActionErase() {
    emit signalEraseRequest(entity.id);
}

void Graphics::ContactListItem::slotActionAccept() {
    emit signalAcceptRequest(entity.id);
}

void Graphics::ContactListItem::slotActionInfo() {
    emit signalInfoRequest(entity.id);
}

int Graphics::ContactListItem::getID() const {
    return entity.id;
}

void Graphics::ContactListItem::mouseDoubleClickEvent(QMouseEvent *event) {
    QWidget::mouseDoubleClickEvent(event);
    emit signalDoubleClicked(entity.id);
}

void Graphics::ContactListItem::keyPressEvent(QKeyEvent *event) {
    QWidget::keyPressEvent(event);
    if (event->key() == Qt::Key_Enter || event->key() == Qt::Key_Return) {
        emit signalReturnPressed(entity.id);
    }
}

void Graphics::ContactListItem::mousePressEvent(QMouseEvent *event) {
    QWidget::mousePressEvent(event);
    emit signalSelected(entity.id);
}

void Graphics::ContactListItem::select() {
    setStyleSheet("background-color: rgb(43,46,55);");
}

void Graphics::ContactListItem::unselect() {
    setStyleSheet("background-color: transparent;");
}

