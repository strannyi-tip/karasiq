//
// Created by strannyi_tip on 30.10.23.
//

#include "Graphics/StyledButton.hpp"

void Graphics::StyledButton::mousePressEvent(QMouseEvent *e) {
    setStyleSheet("background-color: #0d3938;");
    QAbstractButton::mousePressEvent(e);
}

void Graphics::StyledButton::mouseReleaseEvent(QMouseEvent *e) {
    setStyleSheet("background-color: #144342;");
    QAbstractButton::mouseReleaseEvent(e);
}
