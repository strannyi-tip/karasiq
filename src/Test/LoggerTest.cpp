//
// Created by strannyi_tip on 03.11.23.
//

#include <QDebug>
#include "Test/LoggerTest.hpp"

void Test::LoggerTest::test() {
    class AbstractLoggerTest: public Component::AbstractLogger
    {
    protected:
        void write(Level level, const std::string &message) override {

        }
    public:
        void test() {
            assert("LOG" == AbstractLoggerTest::levelToString(Level::LOG));
            assert("INFO" == AbstractLoggerTest::levelToString(Level::INFO));
            assert("WARNING" == AbstractLoggerTest::levelToString(Level::WARNING));
            assert("ERROR" == AbstractLoggerTest::levelToString(Level::ERROR));
            assert("CRITICAL" == AbstractLoggerTest::levelToString(Level::CRITICAL));

            assert("[26.08.1993][INFO]:Test logger message." == AbstractLoggerTest::buildMessage("INFO", "Test logger message.", "26.08.1993"));
        }
    };

    (new AbstractLoggerTest())->test();
}

