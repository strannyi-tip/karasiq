//
// Created by strannyi_tip on 12.12.23.
//
#include "Graphics/TabCloseButton.hpp"

Graphics::TabCloseButton::TabCloseButton(QWidget *parent) : QToolButton(parent) {
    setObjectName("tab_close_btn");
    setIconSize({5, 5});
}

