#include "lepch.h"
#include "Renderer/Shader.h"

#include "Renderer/Renderer.h"
#include "Platform/OpenGL/OpenGLShader.h"


namespace Little {


	Shader* Shader::Create(const std::string& vertexSrc, const std::string& fragmentSrc)
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::API::None:		LE_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
		case RendererAPI::API::OpenGl:	return new OpenGLShader(vertexSrc, fragmentSrc);
		}

		LE_CORE_ASSERT(false, "Unknown RenderAPI");
		return nullptr;
	}
}