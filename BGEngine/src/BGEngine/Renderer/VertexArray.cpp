#include "BGPCH.h"
#include "VertexArray.h"

#include "Renderer.h"
#include "Platform/OpenGL/OpenGLVertexArray.h"

namespace BGEngine::Graphics{
    VertexArray* VertexArray::Create() {
        if (Renderer::GetAPI() == RendererAPI::GraphicsAPI::None) {
            //BG_CORE_ASSERT(false, "RendererAPI::None is not supported!");
            return nullptr;
        }
        if (Renderer::GetAPI() == RendererAPI::GraphicsAPI::OpenGL) {
            return new OpenGLVertexArray();
        }

        return nullptr;
    }

    VertexArray::~VertexArray() {

    }
}
