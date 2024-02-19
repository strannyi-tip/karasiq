//
// Created by strannyi_tip on 01.11.23.
//

#ifndef IMIN_SQLITE3SOMEQUERY_HPP
#define IMIN_SQLITE3SOMEQUERY_HPP

#include <string>

namespace Component
{
    class Sqlite3SomeQuery
    {
    public:
        Sqlite3SomeQuery()=delete;
        ~Sqlite3SomeQuery()=delete;
        Sqlite3SomeQuery(const Sqlite3SomeQuery&)=delete;
        Sqlite3SomeQuery&operator=(const Sqlite3SomeQuery&)=delete;
        static void exec(const std::string &query);
    };
}

#endif //IMIN_SQLITE3SOMEQUERY_HPP
