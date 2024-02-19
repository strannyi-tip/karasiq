//
// Created by strannyi_tip on 06.11.23.
//
#include "Component/Authenticator.hpp"
#include "Component/EntitySchemaContainer.hpp"
#include "Component/AuthTokenCreator.hpp"
#include "Component/EntitySchema.hpp"

Component::AuthenticatorWIdget::AuthenticatorWIdget(QObject *parent) :
QObject(parent),
login(std::string{}),
password(std::string{}),
token(std::string{})
{

}

Component::AuthenticatorWIdget *Component::AuthenticatorWIdget::setPair(const std::string &user_login, const std::string &user_password) {
    login = user_login;
    password = user_password;

    return this;
}

bool Component::AuthenticatorWIdget::authenticate() {
    //@TODO write server authenticate logic
    return false;
}

std::string Component::AuthenticatorWIdget::getToken() {
    return token;
}

