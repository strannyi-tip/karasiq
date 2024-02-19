//
// Created by strannyi_tip on 06.12.23.
//

#include <QDebug>

#include "Graphics/DropDownBody.hpp"

Graphics::DropDownBody::DropDownBody(QWidget *parent):
grid_layout(new QGridLayout),
list(nullptr)
{
    setObjectName("drop_down_body");
    setLayout(grid_layout);
}

void Graphics::DropDownBody::setList(Graphics::ListWidget *new_list) {
    list = new_list;
    clearLayout();
    setWidget(new_list);
}

void Graphics::DropDownBody::clearLayout() {
    auto item = grid_layout->takeAt(0);
    if (nullptr != item) {
        item->widget()->setParent(nullptr);
        item->widget()->deleteLater();
    }
}

void Graphics::DropDownBody::slotItemDoubleClickedModel(const QModelIndex &index) {
    emit signalItemDoubleClicked(index.row());
}

void Graphics::DropDownBody::setList(Graphics::ContactList *new_list) {
    list = new_list;
    clearLayout();
    setWidget(new_list);
}

void Graphics::DropDownBody::setWidget(Graphics::ListWidget *no_void_widget) {
    auto widget = static_cast<Graphics::ListWidget*>(no_void_widget);
    grid_layout->addWidget(widget, 0, 0, 1, 1);
    connect(widget, &ListWidget::doubleClicked, this, &DropDownBody::slotItemDoubleClickedModel);
}

void Graphics::DropDownBody::setWidget(Graphics::ContactList *no_void_widget) {
    auto widget = static_cast<Graphics::ContactList*>(no_void_widget);
    grid_layout->addWidget(widget, 0, 0, 1, 1);
    connect(widget, &ContactList::signalContactDoubleClicked, this, &DropDownBody::slotItemDoubleClickedID);
    connect(widget, &ContactList::signalContactReturnPressed, this, &DropDownBody::slotItemReturnPressed);
}

void Graphics::DropDownBody::slotItemDoubleClickedID(const int &id) {
    emit signalItemDoubleClicked(id);
}

void Graphics::DropDownBody::slotItemReturnPressed(const int &id) {
    emit signalItemReturnPressed(id);
}


