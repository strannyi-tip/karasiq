//
// Created by strannyi_tip on 19.12.23.
//
#include "Graphics/SelectHead.hpp"

Graphics::SelectHead::SelectHead(QWidget *parent):
hbox_layout(new QHBoxLayout),
icon_btn(new QToolButton),
arrow_icon(new QToolButton),
text_lbl(new QLabel),
state(State::Closed)
{
    setParent(parent);
    setObjectName("select_head");
    setFixedHeight(30);
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    icon_btn->setObjectName("impersonal");
    arrow_icon->setObjectName("impersonal");
    text_lbl->setObjectName("select_text");
    icon_btn->setFixedSize({26, 26});
    arrow_icon->setFixedSize({26, 26});
    icon_btn->setIconSize({10, 10});
    arrow_icon->setIconSize({10, 10});
    arrow_icon->setIcon(QIcon(":/rsc/icons/arrow-down.png"));

    hbox_layout->addWidget(icon_btn);
    hbox_layout->addWidget(text_lbl);
    hbox_layout->setContentsMargins({0,0,0,0});

    setLayout(hbox_layout);
}

void Graphics::SelectHead::slotChangeSelected(const QString &text, const QIcon &icon) {
    text_lbl->setText(text);
    icon_btn->setIcon(icon);
    updateState(State::Closed);

    emit signalCloseRequest();
}

void Graphics::SelectHead::setIconSize(const QSize &size) {
    icon_btn->setIconSize(size);
}

void Graphics::SelectHead::updateState(const Graphics::SelectHead::State &new_state) {
    state = new_state;
    applayState();
}

void Graphics::SelectHead::applayState() {
    switch (state) {
        case Closed:
            arrow_icon->setIcon(QIcon(":/rsc/icons/arrow-down.png"));
            break;
        case Opened:
            arrow_icon->setIcon(QIcon(":/rsc/icons/arrow-up.png"));
            break;
    }
}

void Graphics::SelectHead::mousePressEvent(QMouseEvent *event) {
    QWidget::mousePressEvent(event);
    switch (state) {
        case Closed:
            toggleState();
            emit signalOpenRequest();
            break;
        case Opened:
            toggleState();
            emit signalCloseRequest();
            break;
    }
}

void Graphics::SelectHead::toggleState() {
    switch (state) {
        case Closed:
            updateState(State::Opened);
            break;
        case Opened:
            updateState(State::Closed);
            break;
    }
}

void Graphics::SelectHead::slotSelectDefault(const QString &text, const QIcon &icon) {
    text_lbl->setText(text);
    icon_btn->setIcon(icon);
}

