#include "lepch.h"
#include "Renderer/VertexArray.h"

#include "Renderer/Renderer.h"
#include "Platform/OpenGL/OpenGLVertexArray.h"


namespace Little {


	VertexArray* VertexArray::Create()
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::None:		LE_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
		case RendererAPI::OpenGl:	return new OpenGLVertexArray();
		}

		LE_CORE_ASSERT(false, "Unknown RenderAPI");
		return nullptr;
	}
}