//
// Created by strannyi_tip on 10.10.23.
//

#ifndef MISANTHROPE_CSSABLEWIDGET_HPP
#define MISANTHROPE_CSSABLEWIDGET_HPP

#include <QWidget>

namespace Graphics
{
    class CSSableWidget: public QWidget
    {
    protected:
        void paintEvent(QPaintEvent *event) override;
    };
}

#endif //MISANTHROPE_CSSABLEWIDGET_HPP
