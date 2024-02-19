//
// Created by strannyi_tip on 30.10.23.
//

#ifndef IMIN_CONTACTFINDDATAENTITY_HPP
#define IMIN_CONTACTFINDDATAENTITY_HPP

#include <string>

namespace Entity
{
    struct ContactFindDataEntity {
        std::string nickname;
        int age;
        int status_index;
        std::string status_text;
        std::string info_text;
        int prog_lang_index;
        bool is_online;
    };
}

#endif //IMIN_CONTACTFINDDATAENTITY_HPP
