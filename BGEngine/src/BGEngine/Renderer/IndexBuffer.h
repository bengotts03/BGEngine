//
// Created by Ben Gotts on 03/05/2025.
//

#ifndef BGENGINE_INDEXBUFFER_H
#define BGENGINE_INDEXBUFFER_H

#include "BGPCH.h"
#include "BGEngine/Renderer/RendererAPI.h"

namespace BGEngine::Graphics {
    class IndexBuffer {
    public:
        virtual ~IndexBuffer() = default;

        virtual void Bind() const = 0;
        virtual void Unbind() const = 0;

        virtual uint32_t GetCount() const = 0;

        static IndexBuffer* Create(unsigned int* indices, uint32_t count);
    };
}

#endif //BGENGINE_INDEXBUFFER_H
