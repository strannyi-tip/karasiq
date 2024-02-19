//
// Created by strannyi_tip on 20.12.23.
//

#include "Graphics/SelectBody.hpp"

Graphics::SelectBody::SelectBody(QWidget *parent):
vbox_layout(new QVBoxLayout),
grid_layout(new QGridLayout),
scroll_widget(new QWidget),
scroll(new QScrollArea)
{
    setParent(parent);
    setObjectName("select_body");
    setWindowFlags(Qt::FramelessWindowHint | Qt::NoDropShadowWindowHint);
    setWindowModality(Qt::WindowModality::WindowModal);

    vbox_layout->setContentsMargins({0,0,0,0});
    scroll_widget->setLayout(vbox_layout);
    scroll->setWidget(scroll_widget);

    grid_layout->setContentsMargins({0,0,0,0});
    grid_layout->addWidget(scroll, 0, 0, 1, 1);

    setLayout(grid_layout);
}

Graphics::SelectBody *Graphics::SelectBody::addItem(Graphics::SelectItem *item) {
    items.push_back(item);
    vbox_layout->addWidget(item);
    vbox_layout->update();
    scroll_widget->update();
    scroll->update();

    return this;
}

void Graphics::SelectBody::slotItemMouseEnter(const int &id) {

}

void Graphics::SelectBody::slotItemSelected(const int &id) {
    emit signalItemSelected(id);
}

void Graphics::SelectBody::slotItemSelected(const QString &text) {
    emit signalItemSelected(text);
}

int Graphics::SelectBody::count() {
    return static_cast<int>(items.size());
}

