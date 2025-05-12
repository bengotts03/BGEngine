#include "BGPCH.h"
#include "Renderer.h"

#include "RenderCommand.h"
#include "Renderer2D.h"
#include "Shader.h"
#include "BGEngine/Core/Application.h"

namespace BGEngine::Graphics{

    void Renderer::Init()
    {
        // Initialize OpenGL or any other graphics API here
        BG_ENGINE_LOG_INFO("Graphics Initialized");

        RenderCommand::Init();

        // TODO: Needs a better method once we have a Renderer3D as well
        Renderer2D::Init();
    }

    void Renderer::Shutdown()
    {
        // Cleanup resources
        BG_ENGINE_LOG_INFO("Graphics Shutdown");
    }

    void Renderer::OnWindowResize(uint32_t x, uint32_t y, uint32_t width, uint32_t height)
    {
        RenderCommand::SetViewport(x, y, width, height);
    }

    void Renderer::BeginDraw()
    {
        RenderCommand::Clear();
        RenderCommand::SetClearColor(0, 0, 0, 1);

        // TODO: Move this to a better place
        Renderer2D::BeginDraw();
    }

    void Renderer::Submit(std::shared_ptr<Shader> shader, std::shared_ptr<VertexArray> vertexArray, glm::mat4 transform)
    {
        // TODO: Add shader logic
        shader->SetFloat4("model", glm::mat4(1.0f));
        shader->SetFloat4("view", transform);
        shader->SetFloat4("projection", glm::mat4(1.0f));
        shader->Bind();

        vertexArray->Bind();
        RenderCommand::DrawIndexed(vertexArray);
    }

    void Renderer::EndDraw()
    {
    }
}