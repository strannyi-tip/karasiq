//
// Created by strannyi_tip on 06.11.23.
//

#ifndef IMIN_AUTHTOKENCREATOR_HPP
#define IMIN_AUTHTOKENCREATOR_HPP

#include <string>

namespace Component
{
    class AuthTokenCreator
    {
    public:
        AuthTokenCreator()=delete;
        ~AuthTokenCreator()=delete;
        AuthTokenCreator(const AuthTokenCreator&)=delete;
        AuthTokenCreator&operator=(const AuthTokenCreator&)=delete;
        static std::string create();
    };
}

#endif //IMIN_AUTHTOKENCREATOR_HPP
