//
// Created by Ben Gotts on 08/05/2025.
//

#ifndef BGENGINE_SHADERMANAGER_H
#define BGENGINE_SHADERMANAGER_H

#include "BGPCH.h"

namespace BGEngine::Graphics
{
    class Shader;

    class ShaderManager
    {
    public:
        static void Init();
        static void Shutdown();

        static std::shared_ptr<Shader> LoadShader(const std::string& name, const std::string& vertexPath, const std::string& fragmentPath);
        static std::shared_ptr<Shader> GetShader(const std::string& name);
    private:
        static std::unordered_map<std::string, std::shared_ptr<Shader>> shaders;

        static void RegisterShader(const std::string& name, const std::shared_ptr<Shader>& shader);
    };
}

#endif //BGENGINE_SHADERMANAGER_H
