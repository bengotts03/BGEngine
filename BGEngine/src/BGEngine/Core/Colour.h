//
// Created by Ben Gotts on 12/05/2025.
//

#ifndef BGENGINE_COLOUR_H
#define BGENGINE_COLOUR_H

#include "BGPCH.h"

namespace BGEngine::Maths {

    class Colour {
    public:
        Colour() : r(0), g(0), b(0), a(1) {}
        Colour(float red, float green, float blue, float alpha = 1.0f) : r(red), g(green), b(blue), a(alpha) {}

        std::string ToString() const {
            return "Colour(" + std::to_string(r) + ", " + std::to_string(g) + ", " + std::to_string(b) + ", " + std::to_string(a) + ")";
        }

        float r, g, b, a;

        static Colour Red() { return Colour(1.0f, 0.0f, 0.0f); }
        static Colour Green() { return Colour(0.0f, 1.0f, 0.0f); }
        static Colour Blue() { return Colour(0.0f, 0.0f, 1.0f); }
        static Colour White() { return Colour(1.0f, 1.0f, 1.0f); }
        static Colour Black() { return Colour(0.0f, 0.0f, 0.0f); }
        static Colour Yellow() { return Colour(1.0f, 1.0f, 0.0f); }
        static Colour Cyan() { return Colour(0.0f, 1.0f, 1.0f); }
        static Colour Magenta() { return Colour(1.0f, 0.0f, 1.0f); }
        static Colour Grey() { return Colour(0.5f, 0.5f, 0.5f); }
        static Colour Transparent() { return Colour(0.0f, 0.0f, 0.0f, 0.0f); }
    };

} // namespace BGEngine::Maths

#endif //BGENGINE_COLOUR_H
