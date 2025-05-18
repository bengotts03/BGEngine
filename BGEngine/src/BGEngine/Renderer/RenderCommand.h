//
// Created by Ben Gotts on 02/05/2025.
//

#ifndef BGENGINE_RENDERCOMMAND_H
#define BGENGINE_RENDERCOMMAND_H

#include "RendererAPI.h"
#include "VertexArray.h"

namespace BGEngine::Graphics {
    class RenderCommand {
    public:
        static void Init();
        static void SetViewport(unsigned int x, unsigned int y, unsigned int width, unsigned int height);

        static void SetClearColor(float r, float g, float b, float a);
        static void Clear();

        static void DrawLine();
        static void DrawIndexed(std::shared_ptr<VertexArray>& vertexArray, uint32_t indexCount);
    private:
        static RendererAPI* rendererAPI;
    };
}

#endif //BGENGINE_RENDERCOMMAND_H
