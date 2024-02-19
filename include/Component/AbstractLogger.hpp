//
// Created by strannyi_tip on 03.11.23.
//

#ifndef IMIN_ABSTRACTLOGGER_HPP
#define IMIN_ABSTRACTLOGGER_HPP

#include <string>
#include <qstring.h>

namespace Component
{
    class AbstractLogger
    {
    public:
        enum Level {
            LOG,
            INFO,
            WARNING,
            ERROR,
            CRITICAL
        };
        void log(const std::string &message);
        void info(const std::string &message);
        void warning(const std::string &message);
        void error(const std::string &message);
        void critical(const std::string &message);
    protected:
        inline static const std::string LOG_FILE = "karasiq.log";
        inline static const std::string LOG_PATH = "logs";
        virtual void write(Level, const std::string &message)=0;
        static std::string buildMessage(const std::string &lvl_string, const std::string &message, std::string date);
        static std::string levelToString(Level level);
    };
}

#endif //IMIN_ABSTRACTLOGGER_HPP
