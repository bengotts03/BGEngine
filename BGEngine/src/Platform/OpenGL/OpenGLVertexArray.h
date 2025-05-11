//
// Created by Ben Gotts on 07/05/2025.
//

#ifndef BGENGINE_OPENGLVERTEXARRAY_H
#define BGENGINE_OPENGLVERTEXARRAY_H

#include "BGEngine/Renderer/VertexArray.h"
#include "OpenGLIndexBuffer.h"
#include "OpenGLVertexBuffer.h"

namespace BGEngine::Graphics {
    class OpenGLVertexArray : public VertexArray {
    private:
        unsigned int vertexArrayID;

        std::vector<std::shared_ptr<VertexBuffer>> vertexBuffers;
        std::shared_ptr<IndexBuffer> indexBuffer;
    public:
        OpenGLVertexArray();
        ~OpenGLVertexArray() override;

        virtual void Bind() const override;
        virtual void Unbind() const override;

        virtual void AddVertexBuffer(const std::shared_ptr<VertexBuffer>& vertexBuffer) override;
        virtual void SetIndexBuffer(const std::shared_ptr<IndexBuffer>& indexBuffer) override;
        virtual std::shared_ptr<IndexBuffer> GetIndexBuffer() const override { return indexBuffer; }

        unsigned int GetVertexArray() const { return vertexArrayID; }
    };
}

#endif //BGENGINE_OPENGLVERTEXARRAY_H
