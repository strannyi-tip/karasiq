//
// Created by strannyi_tip on 03.11.23.
//

#ifndef IMIN_QTMETHODLOGGER_HPP
#define IMIN_QTMETHODLOGGER_HPP

#include <string>
#include "AbstractLogger.hpp"

namespace Component
{
    class QtMethodLogger: public Component::AbstractLogger
    {
    protected:
        void write(Level level, const std::string &message) override;
    };
}

#endif //IMIN_QTMETHODLOGGER_HPP
