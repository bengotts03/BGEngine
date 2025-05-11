#pragma once

#include "BGEngine/Renderer/RendererAPI.h"

namespace BGEngine::Graphics
{
	class OpenGLRendererAPI : public RendererAPI
	{
	public:
		void Init() override;
		void SetViewport(uint32_t x, uint32_t y, uint32_t width, uint32_t height) override;

		void SetClearColor(float r, float g, float b, float a) override;
		void Clear() override;

		void DrawLine() override;
        void DrawIndexed(std::shared_ptr<VertexArray>& vertexArray) override;
    };
}
