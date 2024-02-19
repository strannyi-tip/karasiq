//
// Created by strannyi_tip on 28.11.23.
//

#ifndef VERTICALSCROLLBAR_HPP
#define VERTICALSCROLLBAR_HPP

#include <QScrollBar>
#include "ChatBodyWidget.hpp"

namespace Graphics
{
    class VerticalScrollBar final: public QScrollBar
    {
    private:
        int old_width = 0;
    protected:
        void enterEvent(QEvent* event) override;
        void leaveEvent(QEvent* event) override;
    };
}

#endif //VERTICALSCROLLBAR_HPP
