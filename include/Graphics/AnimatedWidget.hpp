//
// Created by strannyi_tip on 27.12.23.
//

#ifndef KARASIQ_ANIMATEDWIDGET_HPP
#define KARASIQ_ANIMATEDWIDGET_HPP

#include <QTimer>

#include "CSSableWidget.hpp"
#include "Struct/Animation.hpp"

namespace Graphics
{
    class AnimatedWidget: public CSSableWidget
    {
    public:
        explicit AnimatedWidget(QWidget *parent = nullptr);
        AnimatedWidget *addAnimation(const QString &name, const Struct::Animation &anim);
        AnimatedWidget *selectAnimation(const QString &name);
        void animate();
    protected:
        int current_size;
        QTimer *width_plus_timer;
        QTimer *width_minus_timer;
        QTimer *height_plus_timer;
        QTimer *height_minus_timer;
        Struct::Animation selected_animation {};
        std::map<QString, Struct::Animation> animations;
        void zeroSafeCheck();
    protected slots:
        void slotWidthPlusAnimate();
        void slotWidthMinusAnimate();
        void slotHeightPlusAnimate();
        void slotHeightMinusAnimate();
    };
}

#endif //KARASIQ_ANIMATEDWIDGET_HPP
