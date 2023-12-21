#include "lepch.h"
#include "Renderer/Texture.h"

#include "Renderer/Renderer.h"
#include "Platform/OpenGL/OpenGLTexture.h"

namespace Little {

	Ref<Texture2D> Texture2D::Create(const std::string& path);
	{
		
		switch (Renderer::GetAPI())
		{
		case RendererAPI::API::None:		LE_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
		case RendererAPI::API::OpenGl:	return make_shared<OpenGLTexture2D>(path);
		}

		LE_CORE_ASSERT(false, "Unknown RenderAPI");
		return nullptr;
		
	}

}