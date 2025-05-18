//
// Created by Ben Gotts on 02/05/2025.
//

#include "RenderCommand.h"

namespace BGEngine::Graphics{

    // Definition of the static member variable
    RendererAPI* RenderCommand::rendererAPI = nullptr;

    void RenderCommand::Init() {
        rendererAPI = RendererAPI::Create();
        rendererAPI->Init();
    }

    void RenderCommand::SetViewport(unsigned int x, unsigned int y, unsigned int width, unsigned int height) {
        rendererAPI->SetViewport(x, y, width, height);
    }

    void RenderCommand::SetClearColor(float r, float g, float b, float a) {
        rendererAPI->SetClearColor(r, g, b, a);
    }

    void RenderCommand::Clear() {
        rendererAPI->Clear();
    }

    void RenderCommand::DrawIndexed(std::shared_ptr<VertexArray>& vertexArray, uint32_t indexCount) {
        rendererAPI->DrawIndexed(vertexArray, indexCount);
    }

    void RenderCommand::DrawLine() {
        rendererAPI->DrawLine();
    }
}