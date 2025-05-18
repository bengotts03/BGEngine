//
// Created by Ben Gotts on 17/05/2025.
//

#ifndef BGENGINE_SPRITE_H
#define BGENGINE_SPRITE_H

#include "BGPCH.h"
#include "BGEngine/Core/Colour.h"

using namespace BGEngine;

namespace BGEngine::Graphics {
    class Sprite {
    public:
        Sprite() = default;
        Sprite(const Colour& colour) : _colour(colour) {}
        ~Sprite() = default;

        void SetColour(const Colour& colour) { _colour = colour; }
        const Colour& GetColour() const { return _colour; }
    private:
        Colour _colour = Colour::White();
    };
}


#endif //BGENGINE_SPRITE_H
