//
// Created by strannyi_tip on 30.10.23.
//

#ifndef IMIN_STYLEDBUTTON_HPP
#define IMIN_STYLEDBUTTON_HPP

#include <QPushButton>

namespace Graphics
{
    class StyledButton: public QPushButton
    {
    protected:
        void mousePressEvent(QMouseEvent *e) override;
        void mouseReleaseEvent(QMouseEvent *e) override;
    };
}

#endif //IMIN_STYLEDBUTTON_HPP
