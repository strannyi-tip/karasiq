//
// Created by strannyi_tip on 03.11.23.
//

#ifndef IMIN_LOGGERTEST_HPP
#define IMIN_LOGGERTEST_HPP

#include "AbstractTest.hpp"
#include "Component/AbstractLogger.hpp"

namespace Test
{
    class LoggerTest: public Test::AbstractTest
    {
    public:
        void test() override;
    };
}

#endif //IMIN_LOGGERTEST_HPP
