#include "lepch.h"
#include "Renderer/Buffer.h"

#include "Renderer/Renderer.h"

#include "Platform/OpenGL/OpenGLBuffer.h"

namespace Little {


	VertexBuffer* VertexBuffer::Create(float* vertices, uint32_t size)
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::API::None:		LE_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
		case RendererAPI::API::OpenGl:	return new OpenGLVertexBuffer(vertices, size);
		}

		LE_CORE_ASSERT(false, "Unknown RenderAPI");
		return nullptr;
	}

	IndexBuffer* IndexBuffer::Create(uint32_t* indices, uint32_t size)
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::API::None:		LE_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
		case RendererAPI::API::OpenGl:	return new OpenGLIndexBuffer(indices, size);
		}

		LE_CORE_ASSERT(false, "Unknown RenderAPI");
		return nullptr;
	}
}