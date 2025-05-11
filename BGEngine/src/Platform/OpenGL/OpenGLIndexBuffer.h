//
// Created by Ben Gotts on 03/05/2025.
//

#ifndef BGENGINE_OPENGLINDEXBUFFER_H
#define BGENGINE_OPENGLINDEXBUFFER_H

#include "BGPCH.h"
#include "BGEngine/Renderer/IndexBuffer.h"

namespace BGEngine::Graphics {

    class OpenGLIndexBuffer : public IndexBuffer {
    private:
        unsigned int indexBufferID;
        uint32_t count;
    public:
        OpenGLIndexBuffer(unsigned int* indices, uint32_t count);
        ~OpenGLIndexBuffer() override;

        virtual void Bind() const override;
        virtual void Unbind() const override;

        inline uint32_t GetCount() const { return count; }
    };
}

#endif //BGENGINE_OPENGLINDEXBUFFER_H
