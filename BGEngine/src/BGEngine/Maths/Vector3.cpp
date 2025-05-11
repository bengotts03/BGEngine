//
// Created by Ben Gotts on 09/05/2025.
//

#include "BGPCH.h"
#include "Vector3.h"

namespace BGEngine::Maths {

    void Vector3::normalize() {
        float len = length();
        if (len > 0) {
            x /= len;
            y /= len;
            z /= len;
        }
    }

    Vector3 Vector3::normalized() const {
        float len = length();

        if (len > 0) {
            return Vector3(x / len, y / len, z / len);
        }

        return *this;
    }

    float Vector3::length() const {
        return sqrt(x * x + y * y + z*z);
    }
}