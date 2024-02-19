//
// Created by strannyi_tip on 23.12.23.
//

#ifndef KARASIQ_CONNECTION_HPP
#define KARASIQ_CONNECTION_HPP

namespace Core
{
    class Connection final
    {
    public:
        inline static const char GET_STATE = 0x01;
        inline static const char GET_CONTACTS = 0x02;
        inline static const char GET_MESSAGES = 0x03;
        inline static const char SEND_MESSAGE = 0x04;
    };
}

#endif //KARASIQ_CONNECTION_HPP
