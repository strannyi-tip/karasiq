//
// Created by strannyi_tip on 10.11.23.
//

#ifndef IMIN_ENTITYFIXTURE_HPP
#define IMIN_ENTITYFIXTURE_HPP

#include "Entity/ContactEntity.hpp"
#include "Entity/UserEntity.hpp"
#include "Entity/MessageEntity.hpp"

namespace Component
{
    class EntityFixture
    {
    public:
        EntityFixture()=delete;
        ~EntityFixture()=delete;
        EntityFixture(const EntityFixture&)=delete;
        EntityFixture&operator=(const EntityFixture&)=delete;

        template<typename T>
        static void fill(const T &entity, int count, bool clear_table = true) {
            fillEntity(entity, count, clear_table);
        }
    private:
        static void fillEntity(const Entity::ContactEntity &entity, int count, bool clear_table = true);
        static void fillEntity(const Entity::UserEntity &entity, int count, bool clear_table = true);
        static void fillEntity(const Entity::MessageEntity &entity, int count, bool clear_table = true);
    };
}

#endif //IMIN_ENTITYFIXTURE_HPP
