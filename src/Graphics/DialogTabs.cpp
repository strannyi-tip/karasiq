//
// Created by strannyi_tip on 12.12.23.
//

#include <QLayout>
#include <QPainter>
#include <QTabBar>
#include "Graphics/DialogTabs.hpp"
#include "Graphics/TabCloseButton.hpp"

Graphics::DialogTabs::DialogTabs(QWidget *parent) : QTabWidget(parent)
{
    setObjectName("dialog_tabs");
    setTabsClosable(true);
    tabBar()->setTabButton(0, QTabBar::ButtonPosition::RightSide, new TabCloseButton());
}

void Graphics::DialogTabs::paintEvent(QPaintEvent *event) {
    QTabWidget::paintEvent(event);
    if (!count()) {
        QPainter painter(this);
        painter.drawText(rect(), Qt::AlignCenter, "дважды щелкните по контакту, чтобы открыть диалог");
    }
}

