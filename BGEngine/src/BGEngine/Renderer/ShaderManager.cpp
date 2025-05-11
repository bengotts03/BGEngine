//
// Created by Ben Gotts on 08/05/2025.
//

#include "BGPCH.h"
#include "ShaderManager.h"
#include "Shader.h"

namespace BGEngine::Graphics {
    std::unordered_map<std::string, std::shared_ptr<Shader>> ShaderManager::shaders;

    void ShaderManager::Init() {
        // Initialize OpenGL or any other graphics API here
        BG_ENGINE_LOG_INFO("Shader Manager Initialized");
    }

    void ShaderManager::Shutdown() {
        shaders.clear();

        BG_ENGINE_LOG_INFO("Shader Manager Shutdown");
    }

    std::shared_ptr<Shader> ShaderManager::LoadShader(const std::string &name, const std::string& vertexPath, const std::string& fragmentPath) {
        auto shader = Shader::Create(name, vertexPath, fragmentPath);

        if (!shader) {
            BG_ENGINE_LOG_ERROR("Failed to create shader");
            return nullptr;
        }

        RegisterShader(name, shader);
        return shader;
    }

    std::shared_ptr<Shader> ShaderManager::GetShader(const std::string& name) {
        auto it = shaders.find(name);
        if (it != shaders.end()) {
            return it->second;
        } else {
            BG_ENGINE_LOG_ERROR("Shader not found");
            return nullptr;
        }
    }

    void ShaderManager::RegisterShader(const std::string& name, const std::shared_ptr<Shader>& shader)
    {
        auto it = shaders.find(name);
        if (it != shaders.end())
        {
            BG_ENGINE_LOG_WARN("Shader already exists with name");
            return;
        }

        shaders[name] = shader;
    }

}