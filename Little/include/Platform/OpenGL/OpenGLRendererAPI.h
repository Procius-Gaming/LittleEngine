#pragma once

#include "Renderer/RendererAPI.h"

namespace Little {

    class OpenGLRendererAPI : public RendererAPI
    {
    public:
        OpenGLRendererAPI();

        virtual void Init() override;

        virtual void Clear() override;
        virtual void SetClearColor(const glm::vec4& color) override;

        virtual void DrawIndexed(const Ref<VertexArray>& vertexArray) override;
    };
    
} // namespace Little
