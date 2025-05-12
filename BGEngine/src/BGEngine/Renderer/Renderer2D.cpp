#include "BGPCH.h"
#include "Renderer2D.h"
#include "ShaderManager.h"
#include "Vertex.h"
#include "BGEngine/Core/Colour.h"
#include "BGEngine/Maths/Vector3.h"
#include <glm/gtc/matrix_transform.hpp>

namespace BGEngine::Graphics {

    RendererData* Renderer2D::rendererData = nullptr;

    void Renderer2D::Init() {
        // Initialize 2D renderer resources here
        BG_ENGINE_LOG_INFO("2D Renderer Initialized");

        rendererData = new RendererData();
    }

    void Renderer2D::Shutdown() {
        // Cleanup 2D renderer resources here
        BG_ENGINE_LOG_INFO("2D Renderer Shutdown");
    }

    void Renderer2D::BeginDraw() {
        rendererData->stats.DrawCalls = 0;
        rendererData->stats.QuadCount = 0;
    }

    void Renderer2D::EndDraw() {

    }

    void Renderer2D::StartBatch() {

    }

    void Renderer2D::EndBatch() {

    }

    void Renderer2D::DrawQuad(const Vector2 position, const Vector2 size, const Colour colour) {
        float vertices[] = {
        0.5f, 0.5f, 0.0f, colour.r, colour.g, colour.b, // TOP RIGHT
        -0.5f, 0.5f, 0.0f, colour.r, colour.g, colour.b, // TOP LEFT
        -0.5f, -0.5f, 0.0f, colour.r, colour.g, colour.b, // BOTTOM LEFT
        0.5f, -0.5f, 0.0f, colour.r, colour.g, colour.b  // BOTTOM RIGHT
        };
        /* TODO: Switch to a vertex data type
        Vertex verticesV[] = {
            { Maths::Vector3(0.5f, 0.5f, 0.0f), Maths::Vector3(0.5f, 0.5f, 0.0f) },
            { Maths::Vector3(-0.5f, 0.5f, 0.0f), Maths::Vector3(0.5f, 0.5f, 0.0f) },
            { Maths::Vector3(-0.5f, -0.5f, 0.0f), Maths::Vector3(0.5f, 0.5f, 0.0f) },
            { Maths::Vector3(0.5f, -0.5f, 0.0f), Maths::Vector3(0.5f, 0.5f, 0.0f) },
        };*/
        unsigned int indices[] = {
                0, 1, 3,
                1, 2, 3
        };

        std::shared_ptr<VertexArray> vertexArray;
        vertexArray.reset(VertexArray::Create());

        std::shared_ptr<VertexBuffer> vertexBuffer;
        vertexBuffer.reset(VertexBuffer::Create(vertices, sizeof(vertices)));
        vertexBuffer->SetBufferLayout(BufferLayout({
            { "aPos", ShaderDataType::Float3 },
            { "aColor", ShaderDataType::Float3 }
        }));
        vertexArray->AddVertexBuffer(vertexBuffer);

        std::shared_ptr<IndexBuffer> indexBuffer;
        indexBuffer.reset(IndexBuffer::Create(indices, sizeof(indices)));
        vertexArray->SetIndexBuffer(indexBuffer);

        vertexArray->Bind();

        rendererData->stats.QuadCount++;
        rendererData->stats.DrawCalls++; // TODO: Move to increase in a new batch

        auto transform = glm::mat4(1.0f);
        transform = glm::translate(transform, glm::vec3(position.getX(), position.getY(), 0.0f));
        transform = glm::scale(transform, glm::vec3(size.getX(), size.getY(), 1.0f));
        Renderer::Submit(ShaderManager::GetShader("BasicShader"), vertexArray, transform);
    }
}