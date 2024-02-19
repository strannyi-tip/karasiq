//
// Created by strannyi_tip on 27.11.23.
//

#include "Graphics/ChatMessagesAreaWidget.hpp"
#include "View/DialogTabView.hpp"

Graphics::ChatMessagesAreaWidget::ChatMessagesAreaWidget(QWidget* parent):
grid_layout(new QGridLayout),
dialogs(new Graphics::DialogTabs)
{
    setParent(parent);
    setObjectName("chat_messages_area");

    grid_layout->setContentsMargins({5,5,5,5});
    grid_layout->addWidget(dialogs, 0, 0, 1, 1);

    setLayout(grid_layout);
}

void Graphics::ChatMessagesAreaWidget::slotOpenDialog(const int &contact_id, const QString &contact_name) {
    auto view = new View::DialogTabView;
    view->loadFromHistory(contact_id);
    views[contact_id] = view;
    names[contact_id] = contact_name;
    replaceDialog(contact_id);
}

void Graphics::ChatMessagesAreaWidget::replaceDialog(const int &contact_id) {
    int tab;
    if (!opened_tabs.contains(contact_id)) {
        tab = dialogs->addTab(views[contact_id], names[contact_id]);
    } else {
        tab = opened_tabs[contact_id];
    }
    dialogs->setCurrentIndex(tab);
    dialogs->setCurrentWidget(views[contact_id]);
}
