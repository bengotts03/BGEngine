#pragma once

#include "BufferLayout.h"
#include "Vertex.h"

namespace BGEngine::Graphics {
    class VertexBuffer {
    public:
        virtual ~VertexBuffer() = default;

        virtual void Bind() const = 0;
        virtual void Unbind() const = 0;

        virtual const BufferLayout& GetBufferLayout() const = 0;
        virtual void SetBufferLayout(const BufferLayout& layout) = 0;

        virtual void SetData(const void* data, uint32_t size) = 0;

        static VertexBuffer* Create(uint32_t size);
        static VertexBuffer* Create(std::vector<Vertex> vertices, uint32_t size);
    };
}

