//
// Created by strannyi_tip on 23.10.23.
//

#ifndef WORK_CALENDAR_ENTITYSCEMACONTAINER_HPP
#define WORK_CALENDAR_ENTITYSCEMACONTAINER_HPP

#include <string>
#include <sqlite_orm/sqlite_orm.h>
#include "Entity/UserEntity.hpp"
#include "Entity/MessageEntity.hpp"
#include "Entity/SystemEntity.hpp"
#include "Entity/UserInfoEntity.hpp"
#include "Entity/ContactEntity.hpp"
#include "Entity/ExtendedStatusEntity.hpp"
#include "Entity/ProgLangEntity.hpp"

using namespace sqlite_orm;

namespace Component
{
    class EntitySchemaContainer
    {
    public:
        static inline const std::string SYSTEM_DATABASE_FILE = "../karasiq.db";
        static inline const std::string HISTORY_DATABASE_FILE = "../history.db";
        static inline const std::string CONTACTS_DATABASE_FILE = "../contacts.db";
        static auto get(const Entity::UserEntity&) {
            return make_storage(SYSTEM_DATABASE_FILE,
                make_table("user",
                       make_column("id", &Entity::UserEntity::id, primary_key().autoincrement()),
                       make_column("login", &Entity::UserEntity::login),
                       make_column("password", &Entity::UserEntity::password_hash),
                       make_column("token", &Entity::UserEntity::token),
                       make_column("info_id", &Entity::UserEntity::info_id)
                )
            );
        }
        static auto get(const Entity::MessageEntity&) {
            return make_storage(HISTORY_DATABASE_FILE,
                make_table("message",
                       make_column("id", &Entity::MessageEntity::id, primary_key().autoincrement()),
                       make_column("from_id", &Entity::MessageEntity::from_id),
                       make_column("to_id", &Entity::MessageEntity::to_id),
                       make_column("text", &Entity::MessageEntity::text),
                       make_column("datetime", &Entity::MessageEntity::datetime)
                )
            );
        }
        static auto get(const Entity::SystemEntity&) {
            return make_storage(SYSTEM_DATABASE_FILE,
                make_table("system",
                       make_column("id", &Entity::SystemEntity::id, primary_key().autoincrement()),
                       make_column("host", &Entity::SystemEntity::host),
                       make_column("port", &Entity::SystemEntity::port),
                       make_column("is_group_contacts", &Entity::SystemEntity::is_group_contacts),
                       make_column("is_show_list_counter", &Entity::SystemEntity::is_show_list_counter)
                )
            );
        }
        static auto get(const Entity::ContactEntity&) {
            return make_storage(CONTACTS_DATABASE_FILE,
                make_table("contacts",
                       make_column("id", &Entity::ContactEntity::id, primary_key().autoincrement()),
                       make_column("name", &Entity::ContactEntity::name),
                       make_column("icon", &Entity::ContactEntity::icon),
                       make_column("is_online", &Entity::ContactEntity::is_online),
                       make_column("is_inm_list", &Entity::ContactEntity::is_in_list)
                )
            );
        }
    };
}

#endif //WORK_CALENDAR_ENTITYSCEMACONTAINER_HPP
