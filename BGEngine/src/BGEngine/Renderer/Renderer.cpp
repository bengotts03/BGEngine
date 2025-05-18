#include "BGPCH.h"
#include "Renderer.h"
#include "RenderCommand.h"
#include "Renderer2D.h"
#include "Shader.h"
#include "BGEngine/Core/Application.h"
#include "BGEngine/Components/CameraComponent.h"

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
    }

    void Renderer::Submit(std::shared_ptr<Shader> shader, std::shared_ptr<VertexArray> vertexArray, glm::mat4 transform)
    {
        shader->SetFloat4("transform", transform);
        auto camera = Application::Get().GetMainCamera();
        shader->SetFloat4("viewProjection", camera->GetViewProjectionMatrix());
        shader->Bind();

        vertexArray->Bind();
        RenderCommand::DrawIndexed(vertexArray, sizeof(vertexArray) * sizeof(Vertex));
    }

    void Renderer::EndDraw()
    {
    }
}