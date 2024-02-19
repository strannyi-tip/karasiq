//
// Created by strannyi_tip on 28.12.23.
//

#ifndef KARASIQ_HSPASE_HPP
#define KARASIQ_HSPASE_HPP

#include "CSSableWidget.hpp"

namespace Graphics
{
    class HSpase final: public CSSableWidget
    {
    public:
        explicit HSpase(int width = 0, QWidget *parent = nullptr);
    };
}

#endif //KARASIQ_HSPASE_HPP
