#include "BGPCH.h"
#include "RendererAPI.h"

namespace BGEngine::Renderer
{
	RendererAPI::GraphicsAPI RendererAPI::graphicsAPI = RendererAPI::GraphicsAPI::OpenGL;

	RendererAPI* RendererAPI::Create()
	{
		return nullptr;
	}
}
