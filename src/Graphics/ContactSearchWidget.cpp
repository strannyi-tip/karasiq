//
// Created by strannyi_tip on 11.12.23.
//
#include "Graphics/ContactSearchWidget.hpp"

Graphics::ContactSearchWidget::ContactSearchWidget(QWidget *parent):
hbox_layout(new QHBoxLayout),
search_input(new QLineEdit),
search_btn(new QToolButton)
{
    setObjectName("contact_search_widget");
    setFixedSize({220, 30});
    search_btn->setIcon(QIcon(":/rsc/icons/search.png"));
    search_btn->setObjectName("search_button");
    search_btn->setFixedSize({30, 30});
    search_input->setObjectName("search_input");
    search_input->setPlaceholderText("поиск контактов");

    hbox_layout->setContentsMargins({5,0,0,5});
    hbox_layout->setSpacing(0);
    hbox_layout->addWidget(search_input);
    hbox_layout->addWidget(search_btn);

    setLayout(hbox_layout);
}

