#pragma once

#include "Renderer.h"
#include "ShaderManager.h"
#include "BGEngine/Components/CameraComponent.h"
#include "BGEngine/Core/Colour.h"
#include "BGEngine/Maths/Vector2.h"
#include "BGEngine/Maths/Vector3.h"

using namespace BGEngine::Maths;

namespace BGEngine::Graphics
{
    struct RendererStatistics{
        int DrawCalls = 0;
        int QuadCount = 0;
    };

    struct RendererData{
        std::shared_ptr<VertexArray> quadVertexArray;
        std::shared_ptr<VertexBuffer> quadVertexBuffer;
        std::shared_ptr<IndexBuffer> quadIndexBuffer;
        std::shared_ptr<Shader> quadShader;

        int QuadIndexCount;
        Vertex* QuadBuffer;
        Vertex* QuadBufferPointer;

        glm::mat4 ViewProjection;

        RendererStatistics stats;
    };

	class BG_API Renderer2D {
    public:
        static void Init();
        static void Shutdown();

        static void BeginDraw(Components::CameraComponent& camera);
        static void EndDraw();
        static void Flush();

        static void DrawQuad(const Vector2 position, const Vector2 size, const Colour colour);
        static void DrawQuad(const Vector2 position, const Vector2 size, const Vector2 rotation, const Colour colour);
        static void DrawCircle(const Vector2 position, const float radius, const Colour colour);
        static void DrawLine(const Vector2 start, const Vector2 end, const float thickness, const Colour colour);
        static void DrawRect(const Vector2 position, const Vector2 size, const Colour colour);

        static RendererStatistics GetRendererStats() {
            return rendererData->stats;
        }
    private:
        static void StartBatch();
        static void EndBatch();

        static RendererData* rendererData;
    };
}