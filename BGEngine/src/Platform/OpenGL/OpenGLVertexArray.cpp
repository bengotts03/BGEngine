//
// Created by Ben Gotts on 07/05/2025.
//

#include "glad/glad.h"

#include "OpenGLVertexArray.h"

namespace BGEngine::Graphics {

    static GLenum ShaderDataTypeToGLType(ShaderDataType type) {
        switch (type) {
            case ShaderDataType::Float:   return GL_FLOAT;
            case ShaderDataType::Float2:  return GL_FLOAT;
            case ShaderDataType::Float3:  return GL_FLOAT;
            case ShaderDataType::Float4:  return GL_FLOAT;
            case ShaderDataType::Mat3:    return GL_FLOAT;
            case ShaderDataType::Mat4:    return GL_FLOAT;
            case ShaderDataType::Int:     return GL_INT;
            case ShaderDataType::Int2:    return GL_INT;
            case ShaderDataType::Int3:    return GL_INT;
            case ShaderDataType::Int4:    return GL_INT;
            case ShaderDataType::Bool:    return GL_BOOL;
        }
        return 0;
    }

    OpenGLVertexArray::OpenGLVertexArray() {
        glGenVertexArrays(1, &vertexArrayID);
    }

    OpenGLVertexArray::~OpenGLVertexArray() {
        glDeleteVertexArrays(1, &vertexArrayID);
    }

    void OpenGLVertexArray::Bind() const {
        glBindVertexArray(vertexArrayID);
    }

    void OpenGLVertexArray::Unbind() const {
        glBindVertexArray(0);
    }

    void OpenGLVertexArray::AddVertexBuffer(const std::shared_ptr<VertexBuffer>& vertexBuffer) {
        this->Bind();
        vertexBuffer->Bind();

        uint32_t index = 0;

        // Goes through each element in the buffer layout and dynamically sets the vertex array using the buffer layouts stride and offset
        // This will work for any number of vertex buffer data provided (vertex positions, normals, colours, ect.)
        const BufferLayout& layout = vertexBuffer->GetBufferLayout();
        for (const auto& element : layout)
        {
            glEnableVertexAttribArray(index);
            glVertexAttribPointer(index, element.GetElementCount(), ShaderDataTypeToGLType(element.type), GL_FALSE,
                                  layout.GetStride(), (const void*) element.offset);
            index++;
        }

        vertexBuffers.push_back(vertexBuffer);
    }

    void OpenGLVertexArray::SetIndexBuffer(const std::shared_ptr<IndexBuffer>& indexBuffer) {
        Bind();
        indexBuffer->Bind();

        this->indexBuffer = indexBuffer;
    }
}