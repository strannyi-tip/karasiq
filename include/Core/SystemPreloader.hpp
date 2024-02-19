//
// Created by strannyi_tip on 08.12.23.
//

#ifndef KARASIQ_SYSTEMPRELOADER_HPP
#define KARASIQ_SYSTEMPRELOADER_HPP

namespace Core
{
    class SystemPreloader final
    {
    public:
        SystemPreloader()=delete;
        ~SystemPreloader()=delete;
        SystemPreloader(const SystemPreloader&)=delete;
        SystemPreloader&operator=(const SystemPreloader&)=delete;
        static void preload();
    };
}

#endif //KARASIQ_SYSTEMPRELOADER_HPP
