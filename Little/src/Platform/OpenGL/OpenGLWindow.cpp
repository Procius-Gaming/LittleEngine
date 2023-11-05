#include "lepch.h"
#include "OpenGL/OpenGLWindow.h"

namespace Little {

	static bool s_GLFWInitialized = false;

	Window* Window::Create(const WindowPros& props)
	{
		return new OpenGLWindow(props);
	}

	OpenGLWindow::OpenGLWindow(const WindowPros& props)
	{
		Init(props);
	}

	OpenGLWindow::~OpenGLWindow()
	{
		Shutdown();
	}

	void OpenGLWindow::Init(const WindowPros& props)
	{
		m_Data.Title = props.Title;
		m_Data.Width = props.Width;
		m_Data.Height = props.Height;

		LE_CORE_INFO("Creating window {0} {1}, {2}", props.Title, props.Width, props.Height);
		if(!s_GLFWInitialized)
		{
			int success = glfwInit();
			LE_CORE_ASSERT(success, "Could not Initialize GLFW!");

			s_GLFWInitialized = true;
		}

		m_Window = glfwCreateWindow((int)props.Width, (int)props.Height, m_Data.Title.c_str(), nullptr, nullptr);
		glfwMakeContextCurrent(m_Window);
		glfwSetWindowUserPointer(m_Window, &m_Data);
		SetVSync(true);
	}

	void OpenGLWindow::Shutdown()
	{
		glfwDestroyWindow(m_Window);
	}

	void OpenGLWindow::OnUpdate()
	{
		glfwPollEvent();
		glfwSwapBuffers(m_Window);
	}

	void OpenGLWindow::SetVSync(bool enabled)
	{
		if(enabled)
			glfwSwapInterval(1);
		else
			glfwSwapInterval(0);

		m_Data.VSync = enabled;
	}


}
