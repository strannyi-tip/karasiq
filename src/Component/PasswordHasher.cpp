//
// Created by strannyi_tip on 06.11.23.
//
#include <QString>
#include <QCryptographicHash>
#include "Component/PasswordHasher.hpp"

std::string Component::PasswordHasher::hash(const std::string &password) {
    std::hash<std::string> hasher;
    auto salt = QString::number(hasher(password));
    QByteArray buffer (password.c_str());
    buffer.append(salt.toStdString().c_str());

    return QString(QCryptographicHash::hash(buffer, QCryptographicHash::Sha256).toHex()).toStdString();
}

