#pragma once

#include "RendererAPI.h"
#include "VertexArray.h"
#include "Shader.h"

namespace BGEngine::Graphics
{
	class Renderer
	{
	public:
		static void Init();
		static void Shutdown();
        static void OnWindowResize(uint32_t x, uint32_t y, uint32_t width, uint32_t height);

		static void BeginDraw();
		static void Submit(std::shared_ptr<Shader> shader, std::shared_ptr<VertexArray> vertices, glm::mat4 transform);
		static void EndDraw();

        static RendererAPI::GraphicsAPI GetAPI() { return RendererAPI::GetAPI(); }
	};
}