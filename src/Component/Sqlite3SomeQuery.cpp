//
// Created by strannyi_tip on 01.11.23.
//
#include <sqlite3.h>
#include "Component/Sqlite3SomeQuery.hpp"
#include "Component/EntitySchemaContainer.hpp"

void Component::Sqlite3SomeQuery::exec(const std::string &query) {
    sqlite3 *db;
    char *zErrMsg = nullptr;
    sqlite3_open(Component::EntitySchemaContainer::SYSTEM_DATABASE_FILE.c_str(), &db);
    sqlite3_exec(db, query.c_str(), [](void *NotUsed, int argc, char **argv, char **azColName){return 0;}, 0, &zErrMsg);
    sqlite3_close(db);
}

