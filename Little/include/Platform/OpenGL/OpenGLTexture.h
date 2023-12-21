#pragma once

#include "Renderer/Texture.h"


namespace Little {

	class OpenGLTexture2D : public Texture2D
	{
	public:
		OpenGLTexture2D(const std::string& path);
		virtual ~OpenGLTexture2D() override;

		virtual uin32_t GetWidth() override { return m_Width; }
		virtual uin32_t GetHeight() override { return m_Height; }

		virtual void Bind() override;
	private:
		std::string m_Path;
		uint32_t m_Width, m_Height;
		uint32_t m_RendererID;
	};
}