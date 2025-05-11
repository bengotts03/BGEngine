#include "BGPCH.h"
#include "RendererAPI.h"
#include "Platform/OpenGL/OpenGLRendererAPI.h"

namespace BGEngine::Graphics
{
	RendererAPI::GraphicsAPI RendererAPI::graphicsAPI = RendererAPI::GraphicsAPI::OpenGL;

	RendererAPI* RendererAPI::Create()
	{
        if(graphicsAPI == GraphicsAPI::OpenGL)
        {
            return new OpenGLRendererAPI();
        }
        else if(graphicsAPI == GraphicsAPI::None)
        {
            BG_ENGINE_LOG_ERROR("RendererAPI is None!");
            return nullptr;
        }

        return nullptr;
	}
}
