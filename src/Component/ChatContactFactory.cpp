//
// Created by strannyi_tip on 29.10.23.
//
#include <sqlite_orm/sqlite_orm.h>
#include "Component/ChatContactFactory.hpp"
#include "Entity/ContactEntity.hpp"

QListWidgetItem *Component::ChatContactFactory::create(const Entity::ContactEntity &entity) {
    return new QListWidgetItem(QIcon(QString::fromStdString(entity.icon)), QString::fromStdString(entity.name).toLower());
}

