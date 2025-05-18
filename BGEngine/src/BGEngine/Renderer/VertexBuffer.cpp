#include "BGPCH.h"
#include "VertexBuffer.h"

#include "glad/glad.h"
#include "Platform/OpenGL/OpenGLVertexBuffer.h"
#include "Renderer.h"

namespace BGEngine::Graphics {
    VertexBuffer* VertexBuffer::Create(uint32_t size) {
        if(Renderer::GetAPI() == RendererAPI::GraphicsAPI::None) {
            return nullptr;
        }
        if(Renderer::GetAPI() == RendererAPI::GraphicsAPI::OpenGL) {
            return new OpenGLVertexBuffer(size);
        }

        return nullptr;
    }

    VertexBuffer* VertexBuffer::Create(std::vector<Vertex> vertices, uint32_t size) {
        if(Renderer::GetAPI() == RendererAPI::GraphicsAPI::None) {
            return nullptr;
        }
        if(Renderer::GetAPI() == RendererAPI::GraphicsAPI::OpenGL) {
            return new OpenGLVertexBuffer(vertices, size);
        }

        return nullptr;
    }
}