#include "lepch.h"
#include "Renderer/RenderCommand.h"

#include "Platform/OpenGL/OpenGLRendererAPI.h"


namespace Little {

    RendererAPI* RenderCommand::s_RendererAPI = new OpenGLRendererAPI;
}