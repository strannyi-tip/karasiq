//
// Created by strannyi_tip on 22.12.23.
//

#ifndef KARASIQ_SEQUENTLYIDGENERATOR_HPP
#define KARASIQ_SEQUENTLYIDGENERATOR_HPP

namespace Component
{
    class SequentlyIDGenerator final
    {
    public:
        SequentlyIDGenerator(const SequentlyIDGenerator&)=delete;
        SequentlyIDGenerator&operator=(const SequentlyIDGenerator&)=delete;
        int generate(bool start_of_zero = false);
        static SequentlyIDGenerator *init();
    private:
        inline static SequentlyIDGenerator *instance = nullptr;
        SequentlyIDGenerator()=default;
        ~SequentlyIDGenerator()=default;
        int id = 0;
    };
}

#endif //KARASIQ_SEQUENTLYIDGENERATOR_HPP
