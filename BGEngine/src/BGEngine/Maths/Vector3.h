//
// Created by Ben Gotts on 02/05/2025.
//

#ifndef BGENGINE_VECTOR3_H
#define BGENGINE_VECTOR3_H

#include "BGPCH.h"
#include "Vector2.h"

namespace BGEngine::Maths {
    /**
     * @class Vector3
     * @brief Represents a 3D vector with floating-point precision.
     *
     * The Vector3 class supports basic operations for three-dimensional vectors 
     * such as addition, subtraction, scalar multiplication and division, as
     * well as utility functions like normalization and length calculation.
     */
    class BG_API Vector3{
    private:
        float x, y, z;
    public:
        Vector3() : x(0), y(0), z(0) {}
        Vector3(float x, float y, float z) : x(x), y(y), z(z) {}
        std::string ToString() const {
            return "Vector3(" + std::to_string(x) + ", " + std::to_string(y) + ", " + std::to_string(z) + ")";
        }

        float getX() const { return x; }
        float getY() const { return y; }
        float getZ() const { return z; }
        void setX(float x) { this->x = x; }
        void setY(float y) { this->y = y; }
        void setZ(float z) { this->z = z; }

        Vector3 operator+(const Vector3& other) const {
            return Vector3(x + other.x, y + other.y, z + other.z);
        }
        Vector3 operator-(const Vector3& other) const {
            return Vector3(x - other.x, y - other.y, z - other.z);
        }
        Vector3 operator*(float scalar) const {
            return Vector3(x * scalar, y * scalar, z * scalar);
        }
        Vector3 operator/(float scalar) const {
            return Vector3(x / scalar, y / scalar, z / scalar);
        }

        Vector2 ToVector2() const {
            return Vector2(x, y);
        }

        void normalize();
        Vector3 normalized() const;
        float length() const;
    };
}

#endif //BGENGINE_VECTOR3_H