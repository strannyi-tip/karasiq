//
// Created by strannyi_tip on 06.11.23.
//

#ifndef IMIN_AUTHENTICATOR_HPP
#define IMIN_AUTHENTICATOR_HPP

#include <QObject>
#include "Component/PasswordHasher.hpp"

namespace Component
{
    class AuthenticatorWIdget: public QObject
    {
        Q_OBJECT
    public:
        explicit AuthenticatorWIdget(QObject *parent = nullptr);
        AuthenticatorWIdget *setPair(const std::string &user_login, const std::string &user_password);
        bool authenticate();
        std::string getToken();
    private:
        std::string login;
        std::string password;
        std::string token;
    };
}

#endif //IMIN_AUTHENTICATOR_HPP
