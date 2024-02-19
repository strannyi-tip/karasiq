//
// Created by strannyi_tip on 12.12.23.
//

#ifndef KARASIQ_TABCLOSEBUTTON_HPP
#define KARASIQ_TABCLOSEBUTTON_HPP

#include <QToolButton>
#include <QWidget>

namespace Graphics
{
    class TabCloseButton final: public QToolButton
    {
    public:
        explicit TabCloseButton(QWidget *parent = nullptr);
    };
}

#endif //KARASIQ_TABCLOSEBUTTON_HPP
