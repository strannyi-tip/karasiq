//
// Created by strannyi_tip on 05.11.23.
//

#ifndef IMIN_MESSAGEENTITY_HPP
#define IMIN_MESSAGEENTITY_HPP

#include <string>

namespace Entity
{
    struct MessageEntity {
        int id;
        int from_id;
        int to_id;
        std::string text;
        std::string datetime;
        std::string nickname;
    };
}

#endif //IMIN_MESSAGEENTITY_HPP
