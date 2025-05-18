#include "BGPCH.h"
#include "Renderer2D.h"
#include "ShaderManager.h"
#include "Vertex.h"
#include "BGEngine/Core/Colour.h"
#include "BGEngine/Maths/Vector3.h"
#include <glm/gtc/matrix_transform.hpp>
#include "BGEngine/Core/Application.h"
#include "BGEngine/Renderer/RenderCommand.h"

#define MAX_QUAD_COUNT 1000
#define MAX_VERTEX_COUNT (MAX_QUAD_COUNT * 4)
#define MAX_INDEX_COUNT (MAX_QUAD_COUNT * 6)

namespace BGEngine::Graphics {

    RendererData* Renderer2D::rendererData = nullptr;

    void Renderer2D::Init() {
        BG_ENGINE_LOG_INFO("2D Renderer Initialized");

        rendererData = new RendererData();
        rendererData->QuadBuffer = new Vertex[MAX_VERTEX_COUNT];

        rendererData->quadVertexArray.reset(VertexArray::Create());
        rendererData->quadVertexBuffer.reset(VertexBuffer::Create(MAX_VERTEX_COUNT * sizeof(Vertex)));
        rendererData->quadVertexBuffer->SetBufferLayout(BufferLayout({
                {"aPos",   ShaderDataType::Float3},
                {"aColor", ShaderDataType::Float3}
        }));
        rendererData->quadVertexArray->AddVertexBuffer(rendererData->quadVertexBuffer);

        uint32_t* quadIndices = new uint32_t[MAX_INDEX_COUNT];
        uint32_t offset = 0;
        for (uint32_t i = 0; i < MAX_INDEX_COUNT; i += 6) {
            quadIndices[i + 0] = offset + 0;
            quadIndices[i + 1] = offset + 1;
            quadIndices[i + 2] = offset + 2;

            quadIndices[i + 3] = offset + 2;
            quadIndices[i + 4] = offset + 3;
            quadIndices[i + 5] = offset + 0;

            offset += 4;
        }

        rendererData->quadIndexBuffer.reset(IndexBuffer::Create(quadIndices, MAX_INDEX_COUNT));
        rendererData->quadVertexArray->SetIndexBuffer(rendererData->quadIndexBuffer);

        rendererData->quadShader = ShaderManager::LoadShader("BasicShader", "../../ExampleGame/assets/shaders/basic.vert", "../../ExampleGame/assets/shaders/basic.frag");

        delete[] quadIndices;
    }

    void Renderer2D::Shutdown() {
        BG_ENGINE_LOG_INFO("2D Renderer Shutdown");

        delete[] rendererData->QuadBuffer;
        delete rendererData->QuadBufferPointer;
        delete rendererData;
        rendererData = nullptr;
    }

    void Renderer2D::BeginDraw(Components::CameraComponent& camera) {
        rendererData->stats.QuadCount = 0;
        rendererData->stats.DrawCalls = 0;

        StartBatch();
    }

    void Renderer2D::EndDraw() {
        Flush();
    }

    void Renderer2D::StartBatch() {
        rendererData->QuadIndexCount = 0;
        rendererData->QuadBufferPointer = rendererData->QuadBuffer;
    }

    void Renderer2D::Flush() {
        uint32_t size = (uint32_t)((uint8_t*)rendererData->QuadBufferPointer - (uint8_t*)rendererData->QuadBuffer);
        rendererData->quadVertexBuffer->SetData(rendererData->QuadBuffer, size);

        auto transform = glm::mat4(1.0f);

        rendererData->quadShader->Bind();
        rendererData->quadShader->SetFloat4("transform", transform);
        rendererData->quadShader->SetFloat4("viewProjection", Application::Get().GetMainCamera()->GetViewProjectionMatrix());

        RenderCommand::DrawIndexed(rendererData->quadVertexArray, rendererData->QuadIndexCount);
        rendererData->stats.DrawCalls++;
    }

    void Renderer2D::EndBatch() {
        Flush();
        StartBatch();
    }

    /*
    void Renderer2D::DrawQuad(const Vector2 position, const Vector2 size, const Colour colour) {
        auto cSize = Vector2(size.getX(), size.getY() * Application::Get().GetWindow().GetAspectRatio());

        std::vector<Vertex> vertices = {
                {Maths::Vector3(0.5f, 0.5f, 0.0f),
                        Maths::Vector3(colour.r, colour.g, colour.b)}, // Top Right
                {Maths::Vector3(-0.5f, 0.5f, 0.0f),
                        Maths::Vector3(colour.r, colour.g, colour.b)}, // Top Left
                {Maths::Vector3(-0.5f, -0.5f, 0.0f),
                        Maths::Vector3(colour.r, colour.g, colour.b)}, // Bottom Left
                {Maths::Vector3(0.5f, -0.5f, 0.0f),
                        Maths::Vector3(colour.r, colour.g, colour.b)}, // Bottom Right
        };
        unsigned int indices[] = {
            0, 1, 3,
            1, 2, 3
        };

        std::shared_ptr<VertexArray> vertexArray;
        vertexArray.reset(VertexArray::Create());

        std::shared_ptr<VertexBuffer> vertexBuffer;
        vertexBuffer.reset(VertexBuffer::Create(vertices, vertices.size() * sizeof(Vertex)));
        vertexBuffer->SetBufferLayout(BufferLayout({
            { "aPos", ShaderDataType::Float3 },
            { "aColor", ShaderDataType::Float3 }
        }));
        vertexArray->AddVertexBuffer(vertexBuffer);

        std::shared_ptr<IndexBuffer> indexBuffer;
        indexBuffer.reset(IndexBuffer::Create(indices, sizeof(indices)));
        vertexArray->SetIndexBuffer(indexBuffer);

        vertexArray->Bind();

        rendererData->stats.DrawCalls++;
        rendererData->stats.QuadCount++;

        auto transform = glm::mat4(1.0f);
        transform = glm::translate(transform, glm::vec3(position.getX(), position.getY(), 0.0f));
        transform = glm::scale(transform, glm::vec3(cSize.getX(), cSize.getY(), 1.0f));
        Renderer::Submit(ShaderManager::GetShader("BasicShader"), vertexArray, transform);
    }
    */
    void Renderer2D::DrawQuad(const Vector2 position, const Vector2 size, const Colour colour) {
        if (rendererData->QuadIndexCount + 6 > MAX_INDEX_COUNT) {
            EndBatch();
        }

        auto cSize = Vector2(size.getX(), size.getY() * Application::Get().GetWindow().GetAspectRatio());
        Vertex vertices[] = {
                {Maths::Vector3(0.5f, 0.5f, 0.0f),
                        Maths::Vector3(colour.r, colour.g, colour.b)}, // Top Right
                {Maths::Vector3(-0.5f, 0.5f, 0.0f),
                        Maths::Vector3(colour.r, colour.g, colour.b)}, // Top Left
                {Maths::Vector3(-0.5f, -0.5f, 0.0f),
                        Maths::Vector3(colour.r, colour.g, colour.b)}, // Bottom Left
                {Maths::Vector3(0.5f, -0.5f, 0.0f),
                        Maths::Vector3(colour.r, colour.g, colour.b)}, // Bottom Right
        };
        auto transform = glm::mat4(1.0f);
        transform = glm::translate(transform, glm::vec3(position.getX(), position.getY(), 0.0f));
        transform = glm::scale(transform, glm::vec3(cSize.getX(), cSize.getY(), 1.0f));

        for (int i = 0; i < 4; i++) {
            glm::vec4 posVec = glm::vec4(vertices[i].position.getX(), vertices[i].position.getY(), vertices[i].position.getZ(), 1.0f);
            glm::vec4 transformedPos = transform * posVec;
            
            rendererData->QuadBufferPointer->position = Maths::Vector3(transformedPos.x, transformedPos.y, transformedPos.z);
            rendererData->QuadBufferPointer->color = vertices[i].color;
            rendererData->QuadBufferPointer++;
        }

        rendererData->QuadIndexCount += 6;
        rendererData->stats.QuadCount++;
    }

    void Renderer2D::DrawCircle(const Vector2 position, const float radius, const Colour colour) {

    }

    void Renderer2D::DrawLine(const Vector2 start, const Vector2 end, const float thickness, const Colour colour) {

    }
}