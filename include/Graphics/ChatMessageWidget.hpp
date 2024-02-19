//
// Created by strannyi_tip on 05.11.23.
//

#ifndef IMIN_CHATMESSAGEWIDGET_HPP
#define IMIN_CHATMESSAGEWIDGET_HPP

#include <QGridLayout>
#include <QLabel>
#include "CSSableWidget.hpp"
#include "Entity/MessageEntity.hpp"

namespace Graphics
{
    class ChatMessageWidget: public Graphics::CSSableWidget
    {
    public:
        explicit ChatMessageWidget(const Entity::MessageEntity &message, QWidget *parent = nullptr);
    private:
        QGridLayout *grid_layout;
        QLabel *nickname_lbl;
        QLabel *text_lbl;
        QLabel *datetime_lbl;
        Entity::MessageEntity entity;
    };
}

#endif //IMIN_CHATMESSAGEWIDGET_HPP
