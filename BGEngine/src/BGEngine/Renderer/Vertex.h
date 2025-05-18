//
// Created by Ben Gotts on 09/05/2025.
//

#ifndef BGENGINE_VERTEX_H
#define BGENGINE_VERTEX_H

#include "BGPCH.h"
#include "BGEngine/Maths/Vector3.h"

namespace BGEngine::Graphics {
    struct Vertex {
        Maths::Vector3 position;
        Maths::Vector3 color;

        Vertex() = default;
        Vertex(Maths::Vector3 position, Maths::Vector3 color) {
            this->position = position;
            this->color = color;
        }
    };
}
#endif //BGENGINE_VERTEX_H
