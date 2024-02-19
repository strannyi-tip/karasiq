//
// Created by strannyi_tip on 07.11.23.
//

#ifndef IMIN_VSPACE_HPP
#define IMIN_VSPACE_HPP

#include "CSSableWidget.hpp"

namespace Graphics
{
    class VSpase: public Graphics::CSSableWidget
    {
    public:
        explicit VSpase(int height = 0, QWidget *parent = nullptr);
    };
}

#endif //IMIN_VSPACE_HPP
