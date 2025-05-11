#pragma once

#include "BGPCH.h"
#include "BGEngine/Maths/Vector2.h"
#include "BGEngine/Maths/Vector3.h"
#include "glm/glm.hpp"

namespace BGEngine::Graphics
{
	class Shader
	{
	public:
        ~Shader() = default;

		virtual void Bind() const = 0;
		virtual void Unbind() const = 0;

		virtual void SetBool(const std::string& name, bool value) const = 0;
		virtual void SetInt(const std::string& name, int value) const = 0;
		virtual void SetFloat(const std::string& name, float value) const = 0;
        virtual void SetFloat2(const std::string& name, Maths::Vector2 value) const = 0;
        virtual void SetFloat3(const std::string& name, Maths::Vector3 value) const = 0;
        virtual void SetFloat4(const std::string& name, glm::mat4 value) const = 0;

        virtual const std::string& GetName() const = 0;

        static std::shared_ptr<Shader> Create(const std::string& name, const std::string& vertexPath, const std::string& fragmentPath);
	};
}