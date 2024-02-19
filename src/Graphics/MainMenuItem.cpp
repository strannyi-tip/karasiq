//
// Created by strannyi_tip on 27.12.23.
//

#include <QKeyEvent>

#include "Graphics/MainMenuItem.hpp"

Graphics::MainMenuItem::MainMenuItem(const QString &text_id, const QString &text, const QIcon &icon, QWidget *parent):
hbox_layout(new QHBoxLayout),
text_lbl(new QLabel),
icon_btn(new QToolButton),
id(text_id)
{
    setObjectName("main_menu_item");
    setFixedHeight(40);

    text_lbl->setObjectName("label");
    icon_btn->setObjectName("impersonal");
    text_lbl->setText(text);
    icon_btn->setFixedSize({12, 12});
    icon_btn->setIcon(icon);

    hbox_layout->addWidget(icon_btn);
    hbox_layout->addWidget(text_lbl);

    setLayout(hbox_layout);
}

void Graphics::MainMenuItem::mousePressEvent(QMouseEvent *event) {
    QWidget::mousePressEvent(event);

    emit signalSelected(id);
}

void Graphics::MainMenuItem::keyPressEvent(QKeyEvent *event) {
    QWidget::keyPressEvent(event);

    if (event->key() == Qt::Key_Enter || event->key() == Qt::Key_Return) {
        emit signalSelected(id);
    }
}

QString Graphics::MainMenuItem::getId() {
    return id;
}

void Graphics::MainMenuItem::select() {
    setStyleSheet("background-color: rgb(33,36,45);");
}

void Graphics::MainMenuItem::unselect() {
    setStyleSheet("background-color: transparent;");
}

void Graphics::MainMenuItem::enterEvent(QEvent *event) {
    QWidget::enterEvent(event);

    emit signalMouseEnter(id);
}

void Graphics::MainMenuItem::leaveEvent(QEvent *event) {
    QWidget::leaveEvent(event);

    unselect();
}

