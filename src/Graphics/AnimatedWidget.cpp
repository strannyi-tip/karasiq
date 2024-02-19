//
// Created by strannyi_tip on 27.12.23.
//

#include <QDebug>

#include "Graphics/AnimatedWidget.hpp"

Graphics::AnimatedWidget::AnimatedWidget(QWidget *parent):
        selected_animation({}),
        current_size(0),
        width_plus_timer(new QTimer),
        width_minus_timer(new QTimer),
        height_plus_timer(new QTimer),
        height_minus_timer(new QTimer)
{
    connect(width_plus_timer, &QTimer::timeout, this, &AnimatedWidget::slotWidthPlusAnimate);
    connect(width_minus_timer, &QTimer::timeout, this, &AnimatedWidget::slotWidthMinusAnimate);
    connect(height_plus_timer, &QTimer::timeout, this, &AnimatedWidget::slotHeightPlusAnimate);
    connect(height_minus_timer, &QTimer::timeout, this, &AnimatedWidget::slotHeightMinusAnimate);
}

void Graphics::AnimatedWidget::slotWidthPlusAnimate() {
    width_minus_timer->stop();
    if (current_size >= selected_animation.stop) {
        width_plus_timer->stop();
    }
    current_size += selected_animation.step;
    setFixedWidth(current_size);
}

void Graphics::AnimatedWidget::slotWidthMinusAnimate() {
    width_plus_timer->stop();
    if (current_size <= selected_animation.stop) {
        width_minus_timer->stop();
    }
    current_size -= selected_animation.step;
    zeroSafeCheck();
    setFixedWidth(current_size);
}

void Graphics::AnimatedWidget::slotHeightPlusAnimate() {
    height_minus_timer->stop();
    if (current_size >= selected_animation.stop) {
        height_plus_timer->stop();
    }
    current_size += selected_animation.step;
    setFixedHeight(current_size);
}

void Graphics::AnimatedWidget::slotHeightMinusAnimate() {
    height_plus_timer->stop();
    if (current_size <= 0) {
        height_minus_timer->stop();
    }
    if (current_size <= selected_animation.stop) {
        height_minus_timer->stop();
    }
    current_size -= selected_animation.step;
    zeroSafeCheck();
    setFixedHeight(current_size);
}

Graphics::AnimatedWidget *Graphics::AnimatedWidget::addAnimation(const QString &name, const Struct::Animation &anim) {
    animations[name] = anim;

    return this;
}

Graphics::AnimatedWidget *Graphics::AnimatedWidget::selectAnimation(const QString &name) {
    if (animations.contains(name)) {
        selected_animation = animations[name];
    }

    return this;
}

void Graphics::AnimatedWidget::animate() {
    switch (selected_animation.orientation) {
        case Struct::Horizontal:
            if (width() < selected_animation.stop) {
                width_plus_timer->start(selected_animation.speed);
            } else {
                width_minus_timer->start(selected_animation.speed);
            }
            break;
        case Struct::Vertical:
            if (height() < selected_animation.stop) {
                height_plus_timer->start(selected_animation.speed);
            } else {
                height_minus_timer->start(selected_animation.speed);
            }
            break;
    }
}

void Graphics::AnimatedWidget::zeroSafeCheck() {
    if (current_size < 0) {
        current_size = 0;
    }
}

