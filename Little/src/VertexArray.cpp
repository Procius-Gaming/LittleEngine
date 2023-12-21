#include "lepch.h"
#include "Renderer/VertexArray.h"

#include "Renderer/Renderer.h"
#include "Platform/OpenGL/OpenGLVertexArray.h"


namespace Little {


	Ref<VertexArray> VertexArray::Create()
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::API::None:		LE_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
		case RendererAPI::API::OpenGl:	return std::make_shared<OpenGLVertexArray>();
		}

		LE_CORE_ASSERT(false, "Unknown RenderAPI");
		return nullptr;
	}
}