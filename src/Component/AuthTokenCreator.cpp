//
// Created by strannyi_tip on 06.11.23.
//
#include <QDateTime>
#include "Component/AuthTokenCreator.hpp"
#include "Component/PasswordHasher.hpp"
#include "Component/RandomIDGenerator.hpp"

std::string Component::AuthTokenCreator::create() {
    auto salt = Component::RandomIDGenerator::generate() + QDateTime::currentMSecsSinceEpoch();

    return Component::PasswordHasher::hash(QString::number(salt).toStdString());
}

