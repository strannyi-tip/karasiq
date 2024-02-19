//
// Created by strannyi_tip on 06.12.23.
//

#include <QDebug>
#include "Graphics/DropDownList.hpp"

Graphics::DropDownList::DropDownList(const QString &text, const QString &icon, const Graphics::DropDownButton::CounterType &type,
                                     QWidget *parent) :
    main_grid_layout(new QGridLayout),
    head(new DropDownButton(text, icon, type, this)),
    body(new DropDownBody)
{
    setObjectName("drop_down_list");
    setLayout(main_grid_layout);

    main_grid_layout->addWidget(head, 0, 0, 1, 1);
    main_grid_layout->addWidget(body, 1, 0, 1, 1);
    main_grid_layout->setContentsMargins({0, 0, 0, 0});
    body->setFixedHeight(0);

    setLayout(main_grid_layout);

    connect(this, &DropDownList::signalCounterChanged, head, &DropDownButton::slotChangeCounter);
    connect(head, &DropDownButton::signalToggleList, this, &DropDownList::slotToggleList);
    connect(this, &DropDownList::signalChangeHeadIconState, head, &DropDownButton::slotChangeIconState);
    connect(body, &DropDownBody::signalItemDoubleClicked, this, &DropDownList::slotItemDoubleClicked);
    connect(body, &DropDownBody::signalItemReturnPressed, this, &DropDownList::slotItemReturnPressed);
}

void Graphics::DropDownList::slotToggleList(const Graphics::DropDownButton::IconState &state) {
    switch (state) {
        case DropDownButton::Down:
            closeDrop();
            break;
        case DropDownButton::Up:
            openDrop();
            break;
    }
}

void Graphics::DropDownList::setName(const QString &unique_name) {
    name = unique_name;
}

QString Graphics::DropDownList::getName() {
    return name;
}

void Graphics::DropDownList::closeDrop() {
    emit signalDropClosed(name);
    emit signalChangeHeadIconState(DropDownButton::IconState::Down);
    body->setFixedHeight(0);
}

void Graphics::DropDownList::openDrop() {
    emit signalDropOpened(name);
    emit signalChangeHeadIconState(DropDownButton::IconState::Up);
    body->setFixedHeight(350);
}

void Graphics::DropDownList::slotItemDoubleClicked(const int &index) {
    emit signalDoubleClicked(index);
}

void Graphics::DropDownList::slotItemReturnPressed(const int &index) {
    emit signalDoubleClicked(index);
}

void Graphics::DropDownList::setCounterType(const Graphics::DropDownButton::CounterType &type) {
    head->setCounterType(type);
}
