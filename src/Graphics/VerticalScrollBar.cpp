//
// Created by strannyi_tip on 28.11.23.
//

#include "Graphics/VerticalScrollBar.hpp"

void Graphics::VerticalScrollBar::enterEvent(QEvent* event)
{
    QScrollBar::enterEvent(event);
    old_width = width();
    setFixedWidth(15);
}

void Graphics::VerticalScrollBar::leaveEvent(QEvent* event)
{
    QScrollBar::leaveEvent(event);
    setFixedWidth(old_width);
}
