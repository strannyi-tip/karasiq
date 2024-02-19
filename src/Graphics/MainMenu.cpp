//
// Created by strannyi_tip on 05.12.23.
//

#include <QDebug>
#include <QGraphicsDropShadowEffect>
#include <QApplication>

#include "Graphics/MainMenu.hpp"

#include "View/SettingsView.hpp"

Graphics::MainMenu::MainMenu(QWidget* parent):
vbox_layout(new QVBoxLayout),
icon_lbl(new QLabel)
{
    setObjectName("main_menu");
    setWindowFlags(Qt::FramelessWindowHint);
    setLayout(vbox_layout);
    setFixedWidth(0);

    vbox_layout->setAlignment(Qt::AlignTop);

    icon_lbl->setObjectName("logo_label");
    icon_lbl->setText("karasiq");
    icon_lbl->setAlignment(Qt::AlignCenter);

    vbox_layout->addWidget(icon_lbl);

    addAnimation("open", {
        220,
        15,
        8,
        Struct::AnimationOrientation::Horizontal
    });
    addAnimation("close", {
            0,
            15,
            8,
            Struct::AnimationOrientation::Horizontal
    });
    auto effect = new QGraphicsDropShadowEffect(this);
    effect->setBlurRadius(0);
    effect->setOffset(0);
    setGraphicsEffect(effect);
}

void Graphics::MainMenu::place(const QPoint& point)
{
    setGeometry({
        point.x(),
        point.y(),
        240,
        600
    });
}

void Graphics::MainMenu::animateOpen() {
    selectAnimation("open");
    animate();
}

void Graphics::MainMenu::animateClose() {
    selectAnimation("close");
    animate();
}

void Graphics::MainMenu::slotExecuteAction(const QString &item_id) {
    if (actions.contains(item_id)) {
        actions[item_id]();
    }
}

Graphics::MainMenu *
Graphics::MainMenu::addItem(MainMenuItem *item, const Graphics::MainMenu::MainMenuAction &action) {
    vbox_layout->addWidget(item, 0, Qt::AlignTop);
    actions[item->getId()] = action;
    items[item->getId()] = item;

    connect(item, &MainMenuItem::signalSelected, this, &MainMenu::slotExecuteAction);
    connect(item, &MainMenuItem::signalMouseEnter, this, &MainMenu::slotItemHovered);

    return this;
}

void Graphics::MainMenu::slotItemHovered(const QString &id) {
    for (const auto &item:items) {
        if (item.first == id) {
            item.second->select();
        } else {
            item.second->unselect();
        }
    }
}
