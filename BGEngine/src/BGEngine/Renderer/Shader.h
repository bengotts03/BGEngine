#pragma once

namespace BGEngine::Renderer
{
	class Shader
	{
	public:
		void Bind() const;
		void Unbind() const;

		void SetBool(const std::string& name, bool value) const;
		void SetInt(const std::string& name, int value) const;
		void SetFloat(const std::string& name, float value) const;
	private:
		unsigned int shaderID;
	};
}