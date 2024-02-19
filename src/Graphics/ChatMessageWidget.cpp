//
// Created by strannyi_tip on 05.11.23.
//
#include <QDateTime>
#include "Graphics/ChatMessageWidget.hpp"
#include "Component/FontDatabase.hpp"

Graphics::ChatMessageWidget::ChatMessageWidget(const Entity::MessageEntity &message, QWidget *parent):
grid_layout(new QGridLayout),
nickname_lbl(new QLabel),
text_lbl(new QLabel),
datetime_lbl(new QLabel)
{
    entity = message;
    setObjectName("message");
    nickname_lbl->setObjectName("message_nickname");
    text_lbl->setObjectName("message_text");
    datetime_lbl->setObjectName("message_datetime");

    auto nickname = entity.nickname;
    auto datetime = QDateTime::fromTime_t(QString::fromStdString(entity.datetime).toInt());

    datetime_lbl->setText(datetime.toString("[dd.MM.yyyy hh:mm:ss]:"));
    nickname_lbl->setText(QString::fromStdString(nickname));
    text_lbl->setText(QString::fromStdString(entity.text));

    grid_layout->addWidget(datetime_lbl, 0, 0, 1, 1);
    grid_layout->addWidget(nickname_lbl, 0, 1, 1, 1);
    grid_layout->addWidget(text_lbl, 1, 0, 1, 1);

    setLayout(grid_layout);
}

