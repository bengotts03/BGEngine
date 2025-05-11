#include "BGPCH.h"
#include "Shader.h"

#include "RendererAPI.h"
#include "Platform/OpenGL/OpenGLShader.h"

namespace BGEngine::Graphics{
    std::shared_ptr<Shader> Shader::Create(const std::string &name, const std::string &vertexPath, const std::string &fragmentPath) {
        if(RendererAPI::GetAPI() == RendererAPI::GraphicsAPI::None){
            BG_ENGINE_LOG_ERROR("RendererAPI::None is currently not supported!");
            return nullptr;
        }
        if(RendererAPI::GetAPI() == RendererAPI::GraphicsAPI::OpenGL){
            return std::make_shared<OpenGLShader>(name, vertexPath, fragmentPath);
        }

        return nullptr;
    }
}