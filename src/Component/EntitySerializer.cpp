//
// Created by strannyi_tip on 30.10.23.
//
#include "Component/EntitySerializer.hpp"


json Component::EntitySerializer::as_json(const Entity::ContactFindDataEntity &entity) {
    return json {
            {"login", entity.nickname},
            {"age", entity.age},
            {"status_index", entity.status_index},
            {"status_text", entity.status_text},
            {"info_text", entity.info_text},
            {"prog_lang_index", entity.prog_lang_index},
    };
}

json Component::EntitySerializer::as_json(const Entity::ContactAddDataEntity &entity) {
    return json {
            {"id", entity.id},
            {"login", entity.nickname},
    };
}
