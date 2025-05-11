//
// Created by Ben Gotts on 03/05/2025.
//

#include "BGPCH.h"
#include "glad/glad.h"

#include "IndexBuffer.h"
#include "BGEngine/Renderer/Renderer.h"
#include "Platform/OpenGL/OpenGLIndexBuffer.h"

namespace BGEngine::Graphics {
    IndexBuffer* IndexBuffer::Create(unsigned int* indices, uint32_t count) {
        if(Renderer::GetAPI() == RendererAPI::GraphicsAPI::None) {
            //BG_CORE_ASSERT(false, "RendererAPI::None is not supported!");
            return nullptr;
        }
        if(Renderer::GetAPI() == RendererAPI::GraphicsAPI::OpenGL) {
            return new OpenGLIndexBuffer(indices, count);
        }

        return nullptr;
    }
}