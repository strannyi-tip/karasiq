//
// Created by strannyi_tip on 05.12.23.
//

#include <sqlite_orm/sqlite_orm.h>
#include "Core/DatabasePreloader.hpp"

#include "Component/EntitySchema.hpp"
#include "Component/EntitySchemaContainer.hpp"
#include "Entity/UserEntity.hpp"

using namespace sqlite_orm;

void Core::DatabasePreloader::preload()
{
    make_storage(Component::EntitySchemaContainer::SYSTEM_DATABASE_FILE,
        make_table("user",
               make_column("id", &Entity::UserEntity::id, primary_key().autoincrement()),
               make_column("login", &Entity::UserEntity::login),
               make_column("password", &Entity::UserEntity::password_hash),
               make_column("token", &Entity::UserEntity::token),
               make_column("info_id", &Entity::UserEntity::info_id)
        ),
        make_table("system",
               make_column("id", &Entity::SystemEntity::id, primary_key().autoincrement()),
               make_column("host", &Entity::SystemEntity::host),
               make_column("port", &Entity::SystemEntity::port),
               make_column("is_group_contacts", &Entity::SystemEntity::is_group_contacts),
               make_column("is_show_list_counter", &Entity::SystemEntity::is_show_list_counter)
        )
    ).sync_schema();
    make_storage(Component::EntitySchemaContainer::HISTORY_DATABASE_FILE,
        make_table("message",
               make_column("id", &Entity::MessageEntity::id, primary_key().autoincrement()),
               make_column("from_id", &Entity::MessageEntity::from_id),
               make_column("to_id", &Entity::MessageEntity::to_id),
               make_column("text", &Entity::MessageEntity::text),
               make_column("datetime", &Entity::MessageEntity::datetime)
        )
    ).sync_schema();
    make_storage(Component::EntitySchemaContainer::CONTACTS_DATABASE_FILE,
        make_table("contacts",
               make_column("id", &Entity::ContactEntity::id, primary_key().autoincrement()),
               make_column("name", &Entity::ContactEntity::name),
               make_column("icon", &Entity::ContactEntity::icon),
               make_column("is_online", &Entity::ContactEntity::is_online),
               make_column("is_inm_list", &Entity::ContactEntity::is_in_list)
        )
    ).sync_schema();
}
