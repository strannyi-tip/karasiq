//
// Created by strannyi_tip on 19.12.23.
//

#include <QDebug>
#include <QWidgetAction>

#include "Graphics/Select.hpp"

Graphics::Select::Select(QWidget *parent):
        grid_layout(new QGridLayout),
        head(new SelectHead),
        body_growth_timer(new QTimer),
        body_decrease_timer(new QTimer),
        body_height(0),
        is_first_item(true),
        menu(new QMenu(this))
{
    setObjectName("select");
    setParent(parent);
    setFixedWidth(140);
    grid_layout->addWidget(head, 0, 0, 1, 1);
    grid_layout->setContentsMargins({0,0,0,0});

    menu->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);
    menu->setMaximumHeight(550);

    setLayout(grid_layout);

    connect(head, &SelectHead::signalOpenRequest, this, &Select::slotOpenAccept);
    connect(head, &SelectHead::signalCloseRequest, this, &Select::slotCloseAccept);
    connect(this, &Select::signalSetHeadDefault, head, &SelectHead::slotSelectDefault);
    connect(this, &Select::signalItemChanged, head, &SelectHead::slotChangeSelected);
}

Graphics::Select *Graphics::Select::addItem(Graphics::SelectItem *item) {
    items[item->getID()] = item;
    auto action = new QAction(item->getText());
    action->setIcon(item->getIcon());
    connect(action, &QAction::triggered, [item, this](){
        emit signalItemChanged(item->getText(), item->getIcon());
        emit signalItemIdChanged(item->getID());
    });
    menu->addAction(action);
    if (is_first_item) {
        is_first_item = false;

        emit signalSetHeadDefault(item->getText(), item->getIcon());
    }

    return this;
}

void Graphics::Select::slotOpenAccept() {
    menu->setFixedWidth(width());
    menu->exec(head->mapToGlobal({0, 30}));
}

void Graphics::Select::slotCloseAccept() {
    menu->hide();
}

void Graphics::Select::slotSelectItem(const int &index) {
    if (items.contains(index)) {
        const auto item = items[index];

        emit signalItemChanged(item->getText(), item->getIcon());
    }
}

