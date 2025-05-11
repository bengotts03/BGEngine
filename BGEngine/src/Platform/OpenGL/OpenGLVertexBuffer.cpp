//
// Created by Ben Gotts on 03/05/2025.
//

#include "BGPCH.h"
#include "OpenGLVertexBuffer.h"

#include "glad/glad.h"

namespace BGEngine::Graphics {

    OpenGLVertexBuffer::OpenGLVertexBuffer(float* vertices, unsigned int size){
        glGenBuffers(1, &vertexBufferID);
        glBindBuffer(GL_ARRAY_BUFFER, vertexBufferID);

        glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);
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
}