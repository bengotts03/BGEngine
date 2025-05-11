//
// Created by Ben Gotts on 02/05/2025.
//

#ifndef BGENGINE_VECTOR2_H
#define BGENGINE_VECTOR2_H

namespace BGEngine::Maths {
    /**
     * @class Vector2
     * @brief Represents a 2D vector with floating-point precision.
     *
     * The Vector2 class supports basic operations for two-dimensional vectors
     * such as addition, subtraction, scalar multiplication and division, as
     * well as utility functions like normalization and length calculation.
     */
    class BG_API Vector2{
    private:
        float x, y;
    public:
        Vector2() : x(0), y(0) {}
        Vector2(float x, float y) : x(x), y(y) {}

        float getX() const { return x; }
        float getY() const { return y; }
        void setX(float x) { this->x = x; }
        void setY(float y) { this->y = y; }
        Vector2 operator+(const Vector2& other) const {
            return Vector2(x + other.x, y + other.y);
        }
        Vector2 operator-(const Vector2& other) const {
            return Vector2(x - other.x, y - other.y);
        }
        Vector2 operator*(float scalar) const {
            return Vector2(x * scalar, y * scalar);
        }
        Vector2 operator/(float scalar) const {
            return Vector2(x / scalar, y / scalar);
        }

        std::string ToString() const {
            return "Vector2(" + std::to_string(x) + ", " + std::to_string(y) + ")";
        }

        void normalize();
        Vector2 normalized() const;
        float length() const;
    };
}


#endif //BGENGINE_VECTOR2_H
