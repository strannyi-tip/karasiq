#include <QMouseEvent>
#include <QLabel>
#include "Graphics/ClickableLabel.hpp"


Graphics::ClickableLabel::ClickableLabel(const QString &text, QWidget *parent): QLabel(text, parent)
{

}

//
// Created by strannyi_tip on 30.12.23.
//
void Graphics::ClickableLabel::mousePressEvent(QMouseEvent *event) {
    QLabel::mousePressEvent(event);

    emit signalClicked();
}
