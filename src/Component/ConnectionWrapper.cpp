//
// Created by strannyi_tip on 28.12.23.
//

#include <QMetaObject>

#include "Component/ConnectionWrapper.hpp"

bool Component::ConnectionWrapper::removeConnection(const QMetaObject::Connection &connection) {
    return disconnect(connection);
}
