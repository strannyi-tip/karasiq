//
// Created by strannyi_tip on 30.10.23.
//

#ifndef IMIN_ENTITYSERIALIZER_HPP
#define IMIN_ENTITYSERIALIZER_HPP

#include <nlohmann/json.hpp>
#include "Entity/ContactFindDataEntity.hpp"
#include "Entity/ContactAddDataEntity.hpp"

using namespace nlohmann;

namespace Component
{
    class EntitySerializer
    {
    private:
        static json as_json(const Entity::ContactFindDataEntity &entity);
        static json as_json(const Entity::ContactAddDataEntity &entity);
    public:
        EntitySerializer()=delete;
        ~EntitySerializer()=delete;
        EntitySerializer(const EntitySerializer&)=delete;
        EntitySerializer&operator=(const EntitySerializer&)=delete;
        template<typename T>
        static json to_json(T entity) {
            return as_json(entity);
        }
    };
}

#endif //IMIN_ENTITYSERIALIZER_HPP
