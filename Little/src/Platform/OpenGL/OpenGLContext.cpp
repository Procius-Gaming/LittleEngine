#include "lepch.h"

#include "Platform/OpenGL/OpenGLContext.h"

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <glad/glad.h>


namespace Little {

	OpenGLContext::OpenGLContext(GLFWwindow* windowHandle)
		: m_WindowHandle(windowHandle)
	{
		//LE_CORE_ASSERT(windowHandle, "Window handle is null");
	}
	void OpenGLContext::Init()
	{
		glfwMakeContextCurrent(m_WindowHandle);
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		//LE_CORE_ASSERT(status, "Failed to init glad");

		LE_CORE_INFO("OpenGL Info:");
		LE_CORE_INFO(" Vendor: {0}", fmt::ptr(glGetString(GL_VENDOR)));
		LE_CORE_INFO(" Renderer: {0}", fmt::ptr(glGetString(GL_RENDERER)));
		LE_CORE_INFO(" Version: {0}", fmt::ptr(glGetString(GL_VERSION)));

	}
	void OpenGLContext::SwapBuffers()
	{
		glfwSwapBuffers(m_WindowHandle);
	}
}