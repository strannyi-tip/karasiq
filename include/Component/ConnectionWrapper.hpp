//
// Created by strannyi_tip on 28.12.23.
//

#ifndef KARASIQ_CONNECTIONWRAPPER_HPP
#define KARASIQ_CONNECTIONWRAPPER_HPP

#include <QObject>
#include "Core/Loader.hpp"
#include "Graphics/AuthenticatorWidget.hpp"

namespace Component
{
    class ConnectionWrapper final: public QObject
    {
        Q_OBJECT
        static bool removeConnection(const QMetaObject::Connection &connection);
    };
}

#endif //KARASIQ_CONNECTIONWRAPPER_HPP
