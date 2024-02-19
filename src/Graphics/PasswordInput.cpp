//
// Created by strannyi_tip on 06.11.23.
//
#include "Graphics/PasswordInput.hpp"

Graphics::PasswordInput::PasswordInput(QWidget *parent):
grid_layout(new QGridLayout),
visible_input(new QLineEdit),
visibility_btn(new QToolButton),
is_visible(false)
{
    setObjectName("password_input_widget");
    visible_input->setObjectName("input");
    visibility_btn->setObjectName("styled_button");
    updateVisibilityIcon();
    visible_input->setEchoMode(QLineEdit::Password);

    visibility_btn->setFixedSize({30, 30});

    grid_layout->addWidget(visible_input, 0, 0, 1, 1);
    grid_layout->addWidget(visibility_btn, 0, 1, 1, 1);

    grid_layout->setContentsMargins({0,0,0,0});

    setLayout(grid_layout);

    connect(visible_input, &QLineEdit::textChanged, this, &Graphics::PasswordInput::slotInputDataChanged);
    connect(visibility_btn, &QToolButton::clicked, this, &Graphics::PasswordInput::slotToggleVisibility);
}

void Graphics::PasswordInput::keyPressEvent(QKeyEvent *event) {
    QWidget::keyPressEvent(event);
    if (visible_input->hasFocus() && (event->key() == Qt::Key_Enter || event->key() == Qt::Key_Return)) {
        emit signalInputEnterPressed(visible_input->text());
    }
}

void Graphics::PasswordInput::slotInputDataChanged(const QString &data) {
    emit signalInputDataChanged(visible_input->text());
}

void Graphics::PasswordInput::slotToggleVisibility(bool) {
    updateVisibilityIcon();
    if (!is_visible) {
        visible_input->setEchoMode(QLineEdit::Password);
    } else {
        visible_input->setEchoMode(QLineEdit::Normal);
    }
    is_visible = !is_visible;
}

void Graphics::PasswordInput::updateVisibilityIcon() {
    visibility_btn->setIcon(QIcon(is_visible ? VISIBLE_ICON : INVISIBLE_ICON));
}

QString Graphics::PasswordInput::text() {
    return visible_input->text();
}

void Graphics::PasswordInput::clear() {
    visible_input->clear();
    visible_input->clearFocus();
}

void Graphics::PasswordInput::setText(const QString &text) {
    visible_input->setText(text);
}

