//
// Created by strannyi_tip on 06.11.23.
//

#ifndef IMIN_PASSWORDHASHER_HPP
#define IMIN_PASSWORDHASHER_HPP

#include <string>

namespace Component
{
    class PasswordHasher
    {
    public:
        PasswordHasher()=delete;
        ~PasswordHasher()=delete;
        PasswordHasher(const PasswordHasher&)=delete;
        PasswordHasher&operator=(const PasswordHasher&)=delete;
        static std::string hash(const std::string &password);
    };
}

#endif //IMIN_PASSWORDHASHER_HPP
