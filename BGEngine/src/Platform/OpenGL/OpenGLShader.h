//
// Created by Ben Gotts on 08/05/2025.
//

#ifndef BGENGINE_OPENGLSHADER_H
#define BGENGINE_OPENGLSHADER_H

#include "BGPCH.h"
#include "BGEngine/Renderer/Shader.h"
#include "BGEngine/Maths/Vector3.h"

namespace BGEngine::Graphics
{
    class OpenGLShader : public Shader
    {
    public:
        OpenGLShader(const std::string& name, const std::string& vertexPath, const std::string& fragmentPath);
        ~OpenGLShader();

        void Bind() const override;
        void Unbind() const override;

        void SetBool(const std::string& name, bool value) const override;
        void SetInt(const std::string& name, int value) const override;
        void SetFloat(const std::string& name, float value) const override;
        void SetFloat2(const std::string& name, Maths::Vector2 value) const override;
        void SetFloat3(const std::string& name, Maths::Vector3 value) const override;
        void SetFloat4(const std::string& name, glm::mat4 value) const override;

        const std::string& GetName() const override { return _name; }
    private:
        void LoadShader(const std::string& vertexPath, const std::string& fragmentPath);
        void CompileShader(unsigned int shaderID, const std::string& shaderCode);
        void CheckCompileErrors(unsigned int shader, const std::string& type);
    private:
        unsigned int _shaderID;
        std::string _name;
    };
}

#endif //BGENGINE_OPENGLSHADER_H
