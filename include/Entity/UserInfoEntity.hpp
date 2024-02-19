//
// Created by strannyi_tip on 10.11.23.
//

#ifndef IMIN_USERINFOENTITY_HPP
#define IMIN_USERINFOENTITY_HPP

#include <string>

namespace Entity
{
    struct UserInfoEntity
    {
        int id;
        int extended_status_id;
        std::string extended_status_text;
        std::string nickname;
        bool is_online;
        int prog_lang_index;
        std::string info_text;
        int age;
        int user_id;
        std::string icon_file;
    };
}

#endif //IMIN_USERINFOENTITY_HPP
