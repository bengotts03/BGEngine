//
// Created by Ben Gotts on 02/05/2025.
//

#include "BGPCH.h"
#include "Vector2.h"

namespace BGEngine::Maths {

    void Vector2::normalize() {
        float len = length();
        if (len > 0) {
            x /= len;
            y /= len;
        }
    }

    Vector2 Vector2::normalized() const {
        float len = length();

        if (len > 0) {
            return Vector2(x / len, y / len);
        }

        return *this;
    }

    float Vector2::length() const {
        return sqrt(x * x + y * y);
    }
}