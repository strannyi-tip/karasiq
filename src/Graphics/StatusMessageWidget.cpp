//
// Created by strannyi_tip on 05.11.23.
//
#include <QDebug>
#include "Graphics/StatusMessageWidget.hpp"
#include "Component/FontDatabase.hpp"

Graphics::StatusMessageWidget::StatusMessageWidget(QWidget *parent):
grid_layout(new QGridLayout),
message_lbl(new QLabel),
timer(new QTimer),
index(0)
{
    setObjectName("status_message_widget");
    setFixedHeight(40);
    message_lbl->setObjectName("status_message");
    message_lbl->setAlignment(Qt::AlignLeft);

    setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Fixed);
    setMinimumWidth(700);

    grid_layout->setContentsMargins({5, 5, 5, 0});
    grid_layout->addWidget(message_lbl, 0, 0, 1, 1);

    setLayout(grid_layout);

    timer->start(TIMER_TIMEOUT);
    connect(timer, &QTimer::timeout, this, &Graphics::StatusMessageWidget::slotDoShowMessage);
}

void Graphics::StatusMessageWidget::updateMessage(const QString &message) {
    messages.push_back(message);
}

void Graphics::StatusMessageWidget::slotDoShowMessage() {
    if (messages.empty()) {
        return;
    }
    if (index == messages.size()) {
        index = 0;
        messages.clear();
        return;
    }
    message_lbl->setText(messages[index]);
    index++;
}

