//
// Created by strannyi_tip on 29.10.23.
//

#ifndef IMIN_RANDOMIDGENERATOR_HPP
#define IMIN_RANDOMIDGENERATOR_HPP

namespace Component
{
    class RandomIDGenerator
    {
    public:
        explicit RandomIDGenerator()=delete;
        ~RandomIDGenerator()=delete;
        RandomIDGenerator(const RandomIDGenerator&)=delete;
        RandomIDGenerator& operator=(const RandomIDGenerator&)=delete;
        static int generate();
        static int range(int min, int max);
    };
}

#endif //IMIN_RANDOMIDGENERATOR_HPP
