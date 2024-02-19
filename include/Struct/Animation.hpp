//
// Created by strannyi_tip on 27.12.23.
//

#ifndef KARASIQ_ANIMATION_HPP
#define KARASIQ_ANIMATION_HPP

namespace Struct
{
    typedef enum {
        Horizontal,
        Vertical
    } AnimationOrientation;

    typedef enum {
        Geometry,
        Size
    } AnimationMode;

    struct Animation {
        int stop;
        int step;
        int speed;
        AnimationOrientation orientation;
        AnimationMode mode;
    };
}

#endif //KARASIQ_ANIMATION_HPP
