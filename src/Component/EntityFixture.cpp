//
// Created by strannyi_tip on 10.11.23.
//
#include <vector>
#include <QDateTime>
#include "Component/EntityFixture.hpp"
#include "Component/RandomIDGenerator.hpp"
#include "Entity/ContactEntity.hpp"
#include "Component/PasswordHasher.hpp"
#include "Component/EntitySchemaContainer.hpp"
#include "Component/Sqlite3SomeQuery.hpp"

void Component::EntityFixture::fillEntity(const Entity::ContactEntity &entity, int count, bool clear_table) {
    std::vector<Entity::ContactEntity> contacts;
    contacts.reserve(count);
    for (int i = 1; i < count; i++) {
        contacts.push_back(Entity::ContactEntity {
                -1,
                "Контакт №" + std::to_string(i),
                "",
                rand()%2 == 0,
                rand()%2 == 0
        });
    }
    auto contacts_schema = Component::EntitySchemaContainer::get(Entity::ContactEntity{});

    if (clear_table) {
        contacts_schema.remove_all<Entity::ContactEntity>();
        Component::Sqlite3SomeQuery::exec("UPDATE sqlite_sequence SET seq = 0 WHERE name = 'contact'");
    }

    contacts_schema.insert_range(contacts.begin(), contacts.end());
}

void Component::EntityFixture::fillEntity(const Entity::UserEntity &entity, int count, bool clear_table) {
    std::vector<Entity::UserEntity> users;
    users.reserve(count);
for (int i = 0; i < count; i++) {
        users.push_back(Entity::UserEntity {
                0,
                "user_" + std::to_string(i),
                "12345678",
                Component::PasswordHasher::hash(std::to_string(i)),
                i
        });
    }
    auto user_schema = Component::EntitySchemaContainer::get(Entity::UserEntity{});

    if (clear_table) {
        user_schema.remove_all<Entity::UserEntity>();
        Component::Sqlite3SomeQuery::exec("UPDATE sqlite_sequence SET seq = 0 WHERE name = 'user'");
    }

    user_schema.insert_range(users.begin(), users.end());
}

void Component::EntityFixture::fillEntity(const Entity::MessageEntity&, int count, bool clear_table) {
    std::vector<Entity::MessageEntity> messages;
    messages.reserve(count);
    for (int i = 0; i < count; i++) {
        messages.push_back(Entity::MessageEntity{
            0,
            Component::RandomIDGenerator::range(1, 50),
            Component::RandomIDGenerator::range(1, 50),
            "",
            QDateTime::currentDateTime().toString("dd.mm.yyy H:m:S").toStdString()
        });
    }
    auto messages_schema = Component::EntitySchemaContainer::get(Entity::MessageEntity{});

    if(clear_table) {
        messages_schema.remove_all<Entity::MessageEntity>();
        Component::Sqlite3SomeQuery::exec("UPDATE sqlite_sequence SET seq = 0 WHERE name = 'message'");
    }
    messages_schema.insert_range(messages.begin(), messages.end());
}
