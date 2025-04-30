#pragma once

namespace BGEngine::Renderer
{
	class RendererAPI
	{
		enum class GraphicsAPI
		{
			None = 0,
			OpenGL = 1
		};
	public:
		virtual void Init();
		virtual void SetViewport(uint32_t x, uint32_t y, uint32_t width, uint32_t height);

		virtual void SetClearColor(float r, float g, float b, float a);
		virtual void Clear();

		virtual void DrawLine();

		inline static GraphicsAPI GetAPI() { return graphicsAPI; }
		static RendererAPI* Create();
	private:
		static GraphicsAPI graphicsAPI;
	};
}