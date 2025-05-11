#pragma once

#include "Renderer.h"

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

        RendererStatistics stats;
    };

	class BG_API Renderer2D {
    public:
        static void Init();
        static void Shutdown();

        static void BeginDraw();
        static void EndDraw();

        static void DrawQuad(const Vector2 position, const Vector2 size, const Vector3 color);
        static void DrawQuad(const Vector2 position, const Vector2 size, const Vector2 rotation, const Vector3 color);
        static void DrawCircle(const Vector2 position, const float radius, const Vector2 color);
        static void DrawLine(const Vector2 start, const Vector2 end, const float thickness, const Vector2 color);
        static void DrawRect(const Vector2 position, const Vector2 size, const Vector2 color);

        static RendererStatistics GetRendererStats() {
            return rendererData->stats;
        }
    private:
        void StartBatch();
        void EndBatch();

        static RendererData* rendererData;
    };
}