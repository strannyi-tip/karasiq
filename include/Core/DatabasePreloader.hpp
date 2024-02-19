//
// Created by strannyi_tip on 05.12.23.
//

#ifndef DATABASEPRELOADER_HPP
#define DATABASEPRELOADER_HPP

namespace Core
{
    class DatabasePreloader final
    {
    public:
        static void preload();
        DatabasePreloader()=delete;
        ~DatabasePreloader()=delete;
        DatabasePreloader(const DatabasePreloader&)=delete;
        DatabasePreloader&operator=(const DatabasePreloader&)=delete;
    };
}

#endif //DATABASEPRELOADER_HPP
