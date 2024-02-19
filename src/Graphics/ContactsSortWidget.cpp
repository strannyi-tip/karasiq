//
// Created by strannyi_tip on 24.11.23.
//

#include "Graphics/ContactsSortWidget.hpp"

Graphics::ContactsSortWidget::ContactsSortWidget(QWidget* parent):
hbox_layout(new QHBoxLayout),
readed_status_btn(new QToolButton),
name_alpha_btn(new QToolButton),
prog_lang_btn(new QToolButton),
chat_count_btn(new QToolButton)
{
    setParent(parent);
    setObjectName("contacts_sorting");

    readed_status_btn->setObjectName("sort_button");
    name_alpha_btn->setObjectName("sort_button");
    prog_lang_btn->setObjectName("sort_button");
    chat_count_btn->setObjectName("sort_button");

    readed_status_btn->setFixedSize({30, 30});
    name_alpha_btn->setFixedSize({30, 30});
    prog_lang_btn->setFixedSize({30, 30});
    chat_count_btn->setFixedSize({30, 30});


    readed_status_btn->setIcon(QIcon(":/rsc/icons/message.png"));
    name_alpha_btn->setIcon(QIcon(":/rsc/icons/text.png"));
    prog_lang_btn->setIcon(QIcon(":/rsc/icons/prog_lang.png"));
    chat_count_btn->setIcon(QIcon(":/rsc/icons/chats.png"));

    hbox_layout->setSpacing(10);
    hbox_layout->addWidget(readed_status_btn);
    hbox_layout->addWidget(name_alpha_btn);
    hbox_layout->addWidget(prog_lang_btn);
    hbox_layout->addWidget(chat_count_btn);
    hbox_layout->setAlignment(Qt::AlignTop);

    setLayout(hbox_layout);

    connect(readed_status_btn, &QToolButton::clicked, this, &Graphics::ContactsSortWidget::slotReadedStatusClicked);
    connect(name_alpha_btn, &QToolButton::clicked, this, &Graphics::ContactsSortWidget::slotNameAlphaClicked);
    connect(prog_lang_btn, &QToolButton::clicked, this, &Graphics::ContactsSortWidget::slotProgLangClicked);
    connect(chat_count_btn, &QToolButton::clicked, this, &Graphics::ContactsSortWidget::slotChatCountClicked);
}

void Graphics::ContactsSortWidget::slotReadedStatusClicked(bool)
{
    emit signalReadedSortRequest();
}

void Graphics::ContactsSortWidget::slotNameAlphaClicked(bool)
{
    emit signalNameSortRequest();
}

void Graphics::ContactsSortWidget::slotProgLangClicked(bool)
{
    emit signalProgLangSortRequest();
}

void Graphics::ContactsSortWidget::slotChatCountClicked(bool)
{
    emit signalChatCountSortRequest();
}
