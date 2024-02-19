//
// Created by strannyi_tip on 06.11.23.
//

#ifndef IMIN_CHATMESSAGEFACTORY_HPP
#define IMIN_CHATMESSAGEFACTORY_HPP

#include "Graphics/ChatMessageWidget.hpp"
#include "Entity/MessageEntity.hpp"

namespace Component
{
    class ChatMessageFactory
    {
    public:
        ChatMessageFactory()=delete;
        ~ChatMessageFactory()=delete;
        ChatMessageFactory(const ChatMessageFactory&)=delete;
        ChatMessageFactory&operator=(const ChatMessageFactory&)=delete;
        static Graphics::ChatMessageWidget *create(const Entity::MessageEntity &entity);
    };
}

#endif //IMIN_CHATMESSAGEFACTORY_HPP
