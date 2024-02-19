//
// Created by strannyi_tip on 15.11.23.
//

#ifndef IMIN_CONTACTENTITY_HPP
#define IMIN_CONTACTENTITY_HPP

#include <string>

namespace Entity
{
    struct ContactEntity {
        int id;
        std::string name;
        std::string icon;
        bool is_online;
        bool is_in_list;
    };
}

#endif //IMIN_CONTACTENTITY_HPP
