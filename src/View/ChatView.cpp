//
// Created by strannyi_tip on 22.11.23.
//

#include "View/ChatView.hpp"

View::ChatView::ChatView(QWidget* parent):
grid_layout(new QGridLayout),
contacts(new Graphics::ChatContactsWidget),
body(new Graphics::ChatBodyWidget),
options(new Graphics::ChatOptionsWidget(this))
{
    setParent(parent);
    setObjectName("chat_view");
    const auto vbox_layout = new QVBoxLayout;
    vbox_layout->setContentsMargins({0,5,0,0});
    vbox_layout->addWidget(options);
    vbox_layout->addWidget(body);
    grid_layout->setContentsMargins({0,0,0,0});
    grid_layout->setAlignment(Qt::AlignLeft|Qt::AlignTop);
    grid_layout->addWidget(contacts, 0, 0, 1, 1);
    grid_layout->addLayout(vbox_layout, 0, 1, 1, 1);

    setLayout(grid_layout);

    connect(options, &Graphics::ChatOptionsWidget::signalExtendedStatusIndexChanged, this, &ChatView::slotExtendedStatusIndexChanged);
    connect(options, &Graphics::ChatOptionsWidget::signalOnlineStatusChanged, this, &ChatView::slotOnlineStatusChanged);
    connect(this, &ChatView::signalOnlineStatusChangeRequest, options, &Graphics::ChatOptionsWidget::slotOnlineStatusChangeAccept);
    connect(contacts, &Graphics::ChatContactsWidget::signalContactClicked, body, &Graphics::ChatBodyWidget::slotOpenDialogRequest);
    connect(this, &ChatView::signalUpdateContactsList, contacts, &Graphics::ChatContactsWidget::slotUpdateList);
    connect(body, &Graphics::ChatBodyWidget::signalSendMessageRequest, this, &ChatView::slotSendMessageAccept);
}

Graphics::ChatOptionsWidget* View::ChatView::getOptions() const
{
    return options;
}

void View::ChatView::slotExtendedStatusIndexChanged(const int& index)
{
    emit signalExtendedStatusIndexChanged(index);
}

void View::ChatView::slotOnlineStatusChanged(const int& index)
{
    emit signalOnlineStatusChanged(index);
}

void View::ChatView::slotOnlineStatusChangeAccept(const int& index)
{
    emit signalOnlineStatusChangeRequest(index);
}

void View::ChatView::slotUpdateContactsList() {
    emit signalUpdateContactsList();
}

void View::ChatView::slotSendMessageAccept(const QString &message) {
    emit signalSendMessageRequest(message);
}
