//
// Created by strannyi_tip on 23.10.23.
//

#ifndef WORK_CALENDAR_ENTITYSCHEMA_HPP
#define WORK_CALENDAR_ENTITYSCHEMA_HPP

#include "EntitySchemaContainer.hpp"

namespace Component
{
    class EntitySchema
    {
    public:
        template<typename T>
        static int push(const T &entity) {
            return Component::EntitySchemaContainer::get(entity).insert(entity);
        }
        template<typename T>
        static void update(const T &entity) {
            Component::EntitySchemaContainer::get(entity).template update<T>(entity);
        }
        template<typename T>
        static void remove(const T &entity) {
            Component::EntitySchemaContainer::get(entity).template remove<T>(entity.id);
        }
        template<typename T>
        static bool isExists(const T &entity) {
            return nullptr != Component::EntitySchemaContainer::get(entity).template get_pointer<T>(entity.id);
        }
        template<typename T>
        static void pushOrUpdateIfExists(const T &entity) {
            if (!isExists<T>(entity)) {
                push<T>(entity);
            } else {
                update<T>(entity);
            }
        }
    };
}

#endif //WORK_CALENDAR_ENTITYSCHEMA_HPP
