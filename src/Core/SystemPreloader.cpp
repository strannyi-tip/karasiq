//
// Created by strannyi_tip on 08.12.23.
//

#include "Core/SystemPreloader.hpp"
#include "Component/EntitySchemaContainer.hpp"
#include "Component/EntitySchema.hpp"

void Core::SystemPreloader::preload() {
    auto system_schema = Component::EntitySchemaContainer::get(Entity::SystemEntity{});
    auto entity = system_schema.get_pointer<Entity::SystemEntity>(1);
    if (!entity) {
        Component::EntitySchema::push(Entity::SystemEntity{
                -1, "127.0.0.1", 44544, true
        });
    }
}

