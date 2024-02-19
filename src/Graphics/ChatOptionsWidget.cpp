//
// Created by strannyi_tip on 24.11.23.
//

#include <QDebug>
#include "Graphics/ChatOptionsWidget.hpp"
#include "Component/EntitySchemaContainer.hpp"

Graphics::ChatOptionsWidget::ChatOptionsWidget(QWidget* parent):
hbox_layout(new QHBoxLayout),
online_status_cb(new Select),
extended_status(new Select)
{
    setParent(parent);
    setFixedHeight(30);
    setObjectName("chat_options");

    online_status_cb->addItem(new SelectItem("не в сети", QIcon(":/rsc/icons/status/offline_round.png")));
    online_status_cb->addItem(new SelectItem("в сети", QIcon(":/rsc/icons/status/online_round.png")));

    for (const auto &[id, icon, text]:statuses) {
        extended_status->addItem(new SelectItem(QString::fromStdString(text), QIcon(QString::fromStdString(icon))));
    }

    hbox_layout->setAlignment(Qt::AlignTop|Qt::AlignLeft);
    hbox_layout->addWidget(online_status_cb);
    hbox_layout->addWidget(extended_status);
    hbox_layout->setContentsMargins({5,0,0,0});

    connect(online_status_cb, &Select::signalItemIdChanged, this, &ChatOptionsWidget::slotOnlineStatusChanged);
    connect(this, &ChatOptionsWidget::signalOnlineStatusChanged, online_status_cb, &Select::slotSelectItem);

    setLayout(hbox_layout);
}

void Graphics::ChatOptionsWidget::slotOnlineStatusChanged(const int& index)
{
    emit signalOnlineStatusChanged(index);
}

void Graphics::ChatOptionsWidget::slotExtendedStatusIndexChanged(const int& index)
{
    emit signalExtendedStatusIndexChanged(index);
}

void Graphics::ChatOptionsWidget::slotOnlineStatusChangeAccept(const int& index)
{
    emit signalOnlineStatusChanged(index);
}
