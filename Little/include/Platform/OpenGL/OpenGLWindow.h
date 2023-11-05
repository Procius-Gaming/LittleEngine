#pragma once

#include "Window.h"

#include <GLFW/glf3.h>

namespace Little {

	class OpenGLWindow : public Window
	{
	public:
		OpenGLWindow(const WindowPros& props);
		virtual ~OpenGLWindow();

		void OnUpdate() override;

		inline unsigned int GetWidth() const override { return m_Data.Width; }
		inline unsigned int GetHeight() const override { return m_Data.Height; }

		// Window attributes
		inline void SetEventCallback(const EventCallbackFn& callback) override { m_Data.EventCallback = callback; }
		void SetVSync(bool enabled) override;
		void IsVSync() const override;
	private:
		virtual void Init(const WindowPros& props);
		virtual void Shutdown();
	private:
		GLFWwindow* m_Window;

		struct WindowData
		{
			std::string Title;
			unsigned int Width, Height;
			bool VSync;

			EventCallbackFn EventCallback;
		};

		WindowData m_Data;
	}

}
