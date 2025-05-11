#pragma once

#include "BufferLayout.h"

namespace BGEngine::Graphics {
    class VertexBuffer {
    public:
        virtual ~VertexBuffer() = default;

        virtual void Bind() const = 0;
        virtual void Unbind() const = 0;

        virtual const BufferLayout& GetBufferLayout() const = 0;
        virtual void SetBufferLayout(const BufferLayout& layout) = 0;

        static VertexBuffer* Create(float* vertices, uint32_t size);
    };
}

