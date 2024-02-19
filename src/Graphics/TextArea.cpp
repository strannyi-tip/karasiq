#include <QDragMoveEvent>
#include <QTextEdit>
#include "Graphics/TextArea.hpp"

//
// Created by strannyi_tip on 27.10.23.
//
void Graphics::TextArea::focusInEvent(QFocusEvent *e) {
    QTextEdit::focusInEvent(e);
    emit signalFocusIn();
}

void Graphics::TextArea::focusOutEvent(QFocusEvent *e) {
    QTextEdit::focusOutEvent(e);
    emit signalFocusOut();
}

void Graphics::TextArea::keyPressEvent(QKeyEvent *e) {
    QTextEdit::keyPressEvent(e);
    if (e->key() == Qt::Key_Return || e->key() == Qt::Key_Enter) {
        clear();
        emit signalReturnPressed(toPlainText());
    }
}
