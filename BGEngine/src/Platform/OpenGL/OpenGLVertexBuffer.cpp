//
// Created by Ben Gotts on 03/05/2025.
//

#include "BGPCH.h"
#include "OpenGLVertexBuffer.h"
#include "BGEngine/Renderer/Vertex.h"
#include "glad/glad.h"

namespace BGEngine::Graphics {

    OpenGLVertexBuffer::OpenGLVertexBuffer(unsigned int size) : bufferSize(size) {
        glGenBuffers(1, &vertexBufferID);
        glBindBuffer(GL_ARRAY_BUFFER, vertexBufferID);

        glBufferData(GL_ARRAY_BUFFER, size, nullptr, GL_DYNAMIC_DRAW);
    }

    OpenGLVertexBuffer::OpenGLVertexBuffer(std::vector<Vertex> vertices, unsigned int size) : bufferSize(size) {
        glGenBuffers(1, &vertexBufferID);
        glBindBuffer(GL_ARRAY_BUFFER, vertexBufferID);

        glBufferData(GL_ARRAY_BUFFER, size, &vertices[0], GL_STATIC_DRAW);
    }

    OpenGLVertexBuffer::~OpenGLVertexBuffer() {
        glDeleteBuffers(1, &vertexBufferID);
    }

    void OpenGLVertexBuffer::Bind() const {
        glBindBuffer(GL_ARRAY_BUFFER, vertexBufferID);
    }

    void OpenGLVertexBuffer::Unbind() const {
        glBindBuffer(GL_ARRAY_BUFFER, 0);
    }

    void OpenGLVertexBuffer::SetData(const void* data, uint32_t size) {
        glBindBuffer(GL_ARRAY_BUFFER, vertexBufferID);
        glBufferSubData(GL_ARRAY_BUFFER, 0, size, data);
    }

}