//
// Created by Ben Gotts on 08/05/2025.
//

#include "BGPCH.h"
#include "OpenGLShader.h"
#include "glad/glad.h"
#include <fstream>
#include <sstream>
#include "glm/glm.hpp"

namespace BGEngine::Graphics{

    OpenGLShader::OpenGLShader(const std::string& name, const std::string& vertexPath, const std::string& fragmentPath)
        : _name(name)
    {
        BG_ENGINE_LOG_INFO("Creating Shader");
        LoadShader(vertexPath, fragmentPath);
    }

    OpenGLShader::~OpenGLShader()
    {
        glDeleteProgram(_shaderID);
    }

    void OpenGLShader::LoadShader(const std::string& vertexPath, const std::string& fragmentPath)
    {
        // Load vertex shader
        std::ifstream vertexFile(vertexPath);
        if (!vertexFile.is_open()) {
            BG_ENGINE_LOG_ERROR("Failed to open vertex shader file");
            return;
        }

        std::stringstream vertexStream;
        vertexStream << vertexFile.rdbuf();
        std::string vertexCode = vertexStream.str();
        vertexFile.close();

        if (vertexCode.empty()) {
            BG_ENGINE_LOG_ERROR("Vertex shader file is empty");
            return;
        }

        // Load fragment shader
        std::ifstream fragmentFile(fragmentPath);
        if (!fragmentFile.is_open()) {
            BG_ENGINE_LOG_ERROR("Failed to open fragment shader file");
            return;
        }

        std::stringstream fragmentStream;
        fragmentStream << fragmentFile.rdbuf();
        std::string fragmentCode = fragmentStream.str();
        fragmentFile.close();

        if (fragmentCode.empty()) {
            BG_ENGINE_LOG_ERROR("Fragment shader file is empty");
            return;
        }

        unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
        CompileShader(vertexShader, vertexCode);

        unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
        CompileShader(fragmentShader, fragmentCode);

        // Link shaders
        _shaderID = glCreateProgram();
        glAttachShader(_shaderID, vertexShader);
        glAttachShader(_shaderID, fragmentShader);
        glLinkProgram(_shaderID);
        CheckCompileErrors(_shaderID, "PROGRAM");

        // Delete shaders as they're linked into our program now and no longer necessary
        glDeleteShader(vertexShader);
        glDeleteShader(fragmentShader);
    }

    void OpenGLShader::CompileShader(unsigned int shaderID, const std::string& shaderCode)
    {
        const char* code = shaderCode.c_str();
        glShaderSource(shaderID, 1, &code, nullptr);
        glCompileShader(shaderID);
        CheckCompileErrors(shaderID, "SHADER");
    }

    void OpenGLShader::CheckCompileErrors(unsigned int shader, const std::string& type)
    {
        int success;
        char infoLog[512];
        if (type != "PROGRAM")
        {
            glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
            if (!success)
            {
                glGetShaderInfoLog(shader, 512, nullptr, infoLog);
                BG_ENGINE_LOG_ERROR("Shader compilation error:");
                BG_ENGINE_LOG_ERROR(infoLog);
            }
        }
        else
        {
            glGetProgramiv(shader, GL_LINK_STATUS, &success);
            if (!success)
            {
                glGetProgramInfoLog(shader, 512, nullptr, infoLog);
                BG_ENGINE_LOG_ERROR("Program linking error:");
                BG_ENGINE_LOG_ERROR(infoLog);
            }
        }
    }

    void OpenGLShader::Bind() const
    {
        glUseProgram(_shaderID);
    }

    void OpenGLShader::Unbind() const
    {
        glUseProgram(0);
    }

    void OpenGLShader::SetBool(const std::string& name, bool value) const
    {
        glUniform1i(glGetUniformLocation(_shaderID, name.c_str()), (int)value);
    }

    void OpenGLShader::SetInt(const std::string& name, int value) const
    {
        glUniform1i(glGetUniformLocation(_shaderID, name.c_str()), value);
    }

    void OpenGLShader::SetFloat(const std::string& name, float value) const
    {
        glUniform1f(glGetUniformLocation(_shaderID, name.c_str()), value);
    }

    void OpenGLShader::SetFloat2(const std::string& name, Maths::Vector2 value) const
    {
        glUniform2f(glGetUniformLocation(_shaderID, name.c_str()), value.getX(), value.getY());
    }

    void OpenGLShader::SetFloat3(const std::string& name, Maths::Vector3 value) const
    {
        glUniform3f(glGetUniformLocation(_shaderID, name.c_str()), value.getX(), value.getY(), value.getZ());
    }

    void OpenGLShader::SetFloat4(const std::string& name, glm::mat4 value) const // TODO: Switch mat4 to BGEngine::Maths::Matrix4
    {
        glUniformMatrix4fv(glGetUniformLocation(_shaderID, name.c_str()), 1, GL_FALSE, &value[0][0]);
    }
}