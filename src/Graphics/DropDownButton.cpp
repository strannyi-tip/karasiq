//
// Created by strannyi_tip on 06.12.23.
//
#include "Graphics/DropDownButton.hpp"

Graphics::DropDownButton::DropDownButton(const QString &text, const QString &icon, const CounterType &type, QWidget *parent):
grid_layout(new QGridLayout),
title_lbl(new QLabel),
counter_lbl(new QLabel),
icon_btn(new QToolButton),
icon_lbl(new QToolButton),
icon_state(IconState::Down)
{
    setParent(parent);
    setObjectName("drop_down_head");
    setFixedHeight(32);

    title_lbl->setObjectName("drop_down_title");
    counter_lbl->setObjectName("drop_down_counter");
    icon_lbl->setObjectName("impersonal");
    title_lbl->setText(text);
    icon_btn->setObjectName("impersonal");
    icon_btn->setIconSize({12, 12});
    icon_btn->setIcon(QIcon(":/rsc/icons/down-arrow.png"));
    icon_lbl->setIconSize({16, 16});
    icon_lbl->setIcon(QIcon(icon));

    grid_layout->addWidget(icon_lbl, 0, 0, 1, 1);
    grid_layout->addWidget(title_lbl, 0, 1, 1, 1);
    if (CounterType::Countable == type) {
        grid_layout->addWidget(counter_lbl, 0, 2, 1, 1);
        grid_layout->addWidget(icon_btn, 0, 3, 1, 1);
    } else {
        grid_layout->addWidget(icon_btn, 0, 2, 1, 1);
    }

    setLayout(grid_layout);
    updateCounter(0);
}

void Graphics::DropDownButton::updateCounter(const int &count) {
    counter_lbl->setText("[" + QString::number(count) + "]");
}

void Graphics::DropDownButton::slotChangeCounter(const int &count) {
    updateCounter(count);
}

void Graphics::DropDownButton::toggleIcon() {
    switch (icon_state) {
        case Down:
            icon_btn->setIcon(QIcon(":/rsc/icons/down-arrow.png"));
            break;
        case Up:
            icon_btn->setIcon(QIcon(":/rsc/icons/up-arrow.png"));
            break;
    }
}

void Graphics::DropDownButton::mousePressEvent(QMouseEvent *event) {
    QWidget::mousePressEvent(event);
    switch (icon_state) {
        case Down:
            icon_state = IconState::Up;
            break;
        case Up:
            icon_state = IconState::Down;
            break;
    }
    toggleIcon();
    emit signalToggleList(icon_state);
}

void Graphics::DropDownButton::slotChangeIconState(const Graphics::DropDownButton::IconState &state) {
    icon_state = state;
    toggleIcon();
}

void Graphics::DropDownButton::setCounterType(const Graphics::DropDownButton::CounterType &type) {
    switch (type) {
        case Countable:
            counter_lbl->show();
            break;
        case Muted:
            counter_lbl->hide();
            break;
    }
}

