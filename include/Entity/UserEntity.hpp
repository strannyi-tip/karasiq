//
// Created by strannyi_tip on 30.10.23.
//

#ifndef IMIN_USERENTITY_HPP
#define IMIN_USERENTITY_HPP

#include <string>

namespace Entity
{
    struct UserEntity {
        int id;
        std::string login;
        std::string password_hash;
        std::string token;
        int info_id;
    };
}

#endif //IMIN_USERENTITY_HPP
