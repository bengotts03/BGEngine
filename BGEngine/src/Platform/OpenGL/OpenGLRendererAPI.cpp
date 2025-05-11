#include "BGPCH.h"
#include "OpenGLRendererAPI.h"
#include "glad/glad.h"

namespace BGEngine::Graphics
{
    void OpenGLRendererAPI::Init()
    {
        BG_ENGINE_LOG_INFO("OpenGL Graphics API Initialized");
    }

    void OpenGLRendererAPI::SetViewport(uint32_t x, uint32_t y, uint32_t width, uint32_t height)
    {
        glViewport(x, y, width, height);
    }

    void OpenGLRendererAPI::SetClearColor(float r, float g, float b, float a)
    {
        glClearColor(r, g, b, a);
    }

    void OpenGLRendererAPI::Clear()
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }

    void OpenGLRendererAPI::DrawLine()
    {
        glDrawArrays(GL_LINES, 0, 2);
    }

    void OpenGLRendererAPI::DrawIndexed(std::shared_ptr<VertexArray>& vertexArray)
    {
        vertexArray->Bind();
        int count = vertexArray->GetIndexBuffer()->GetCount();
        glDrawElements(GL_TRIANGLES, count, GL_UNSIGNED_INT, 0);
    }
}