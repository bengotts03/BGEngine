#pragma once

namespace BGEngine::Renderer
{
	class VertexArray
	{
	public:
		virtual ~VertexArray() = default;

		virtual void Bind() const = 0;
		virtual void Unbind() const = 0;
	private:
		unsigned int vertexArray;
	};
}