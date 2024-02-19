//
// Created by strannyi_tip on 03.11.23.
//

#include "Component/AbstractLogger.hpp"

void Component::AbstractLogger::log(const std::string &message) {
    write(Level::LOG, message);
}

void Component::AbstractLogger::info(const std::string &message) {
    write(Level::INFO, message);
}

void Component::AbstractLogger::warning(const std::string &message) {
    write(Level::WARNING, message);
}

void Component::AbstractLogger::error(const std::string &message) {
    write(Level::ERROR, message);
}

void Component::AbstractLogger::critical(const std::string &message) {
    write(Level::CRITICAL, message);
}

std::string Component::AbstractLogger::buildMessage(const std::string &lvl_string, const std::string &message, std::string date) {
    return "[" + date + "][" + lvl_string + "]:" + message;
}

std::string Component::AbstractLogger::levelToString(Component::AbstractLogger::Level level) {
    std::string string_level;
    switch (level) {
        case Level::LOG:
            string_level = "LOG";
            break;
        case Level::INFO:
            string_level = "INFO";
            break;
        case Level::WARNING:
            string_level = "WARNING";
            break;
        case Level::ERROR:
            string_level = "ERROR";
            break;
        case Level::CRITICAL:
            string_level = "CRITICAL";
            break;
    }

    return string_level;
}

