#include <QPaintEvent>
#include <QWidget>
#include <QStyleOption>
#include <QPainter>
#include "Graphics/CSSableWidget.hpp"

//
// Created by strannyi_tip on 10.10.23.
//
void Graphics::CSSableWidget::paintEvent(QPaintEvent *event) {
    QStyleOption o;
    o.initFrom(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &o, &p, this);
}
