//
// Created by strannyi_tip on 07.11.23.
//

#ifndef IMIN_SYSTEMENTITY_HPP
#define IMIN_SYSTEMENTITY_HPP

#include <string>

namespace Entity
{
    struct SystemEntity
    {
        int id;
        std::string host;
        int port;
        bool is_group_contacts;
        bool is_show_list_counter;
    };
}

#endif //IMIN_SYSTEMENTITY_HPP
