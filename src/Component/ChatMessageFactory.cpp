//
// Created by strannyi_tip on 06.11.23.
//
#include "Component/ChatMessageFactory.hpp"

Graphics::ChatMessageWidget *Component::ChatMessageFactory::create(const Entity::MessageEntity &entity) {
    return new Graphics::ChatMessageWidget(entity);
}

