//
// Created by Ben Gotts on 03/05/2025.
//

#ifndef BGENGINE_OPENGLVERTEXBUFFER_H
#define BGENGINE_OPENGLVERTEXBUFFER_H

#include "BGPCH.h"
#include "BGEngine/Renderer/VertexBuffer.h"

namespace BGEngine::Graphics {
    class OpenGLVertexBuffer : public VertexBuffer {
    private:
        unsigned int vertexBufferID;
        BufferLayout bufferLayout;

        int bufferSize = 0;
    public:
        OpenGLVertexBuffer(unsigned int size);
        OpenGLVertexBuffer(std::vector<Vertex> vertices, unsigned int size);
        ~OpenGLVertexBuffer() override;

        virtual void Bind() const override;
        virtual void Unbind() const override;

        virtual const BufferLayout& GetBufferLayout() const override { return bufferLayout; }
        virtual void SetBufferLayout(const BufferLayout& layout) override { bufferLayout = layout; }

        virtual void SetData(const void* data, uint32_t size) override;
    };
}

#endif //BGENGINE_OPENGLVERTEXBUFFER_H
