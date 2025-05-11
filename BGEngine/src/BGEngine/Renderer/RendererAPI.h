#pragma once

#include "BGPCH.h"
#include "VertexArray.h"

namespace BGEngine::Graphics
{
    class VertexArray;
}

namespace BGEngine::Graphics
{
	class RendererAPI
	{
    public:
        enum class GraphicsAPI
		{
			None = 0,
			OpenGL = 1
		};
	public:
		virtual void Init() = 0;
		virtual void SetViewport(uint32_t x, uint32_t y, uint32_t width, uint32_t height) = 0;

		virtual void SetClearColor(float r, float g, float b, float a) = 0;
		virtual void Clear() = 0;

		virtual void DrawLine() = 0;
		virtual void DrawIndexed(std::shared_ptr<VertexArray>& vertices) = 0;

		inline static GraphicsAPI GetAPI() { return graphicsAPI; }
		static RendererAPI* Create();
	private:
		static GraphicsAPI graphicsAPI;
	};
}