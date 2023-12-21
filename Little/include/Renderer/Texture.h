#pragma once

#include <string>
#include "Core.h"

namespace Little[

	class Texture
	{
	public:
		virtual ~Texture() = default;

		virtual uin32_t GetWidth() const = 0;
		virtual uin32_t GetHeight() const = 0;

		virtual void Bind() const = 0;
	};


	class Texture2D : public Texture
	{
	public:
		static Ref<Texture2D> Create(const std::string& path);
	};
]