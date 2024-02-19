//
// Created by strannyi_tip on 29.10.23.
//

#ifndef IMIN_CHATCONTACTFACTORY_HPP
#define IMIN_CHATCONTACTFACTORY_HPP

#include <QListWidgetItem>
#include "Entity/ContactEntity.hpp"

namespace Component
{
    class ChatContactFactory
    {
    public:
        static QListWidgetItem *create(const Entity::ContactEntity &entity);
        ChatContactFactory()=delete;
        ~ChatContactFactory()=delete;
        ChatContactFactory(const ChatContactFactory&)=delete;
        ChatContactFactory& operator=(const ChatContactFactory&)=delete;
    };
}

#endif //IMIN_CHATCONTACTFACTORY_HPP
