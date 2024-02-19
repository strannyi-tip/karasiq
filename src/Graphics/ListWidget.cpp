//
// Created by strannyi_tip on 28.11.23.
//

#include "Graphics/ListWidget.hpp"

#include "Graphics/VerticalScrollBar.hpp"

Graphics::ListWidget::ListWidget(QWidget* parent): QListWidget(parent)
{
    setVerticalScrollBar(new VerticalScrollBar);
    setIconSize({6, 6});
    connect(this, &ListWidget::doubleClicked, this, &Graphics::ListWidget::slotDoubleClicked);
}

void Graphics::ListWidget::slotDoubleClicked(const QModelIndex &index) {
    emit signalDoubleClicked(index.row());
}

int Graphics::ListWidget::count() {
    return QListWidget::count();
}
