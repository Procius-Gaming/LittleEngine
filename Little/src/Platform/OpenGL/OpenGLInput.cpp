#include "lepch.h"
#include "Platform/OpenGL/OpenGLInput.h"
#include "OpenGLInput.h"

#include <GLFW/glfw3.h>
#include "Application.h"

namespace Little {

    Input* Input::s_Instance = new OpenGLInput();

    bool OpenGLInput::IsKeyPressedImpl(int keycode)
    {
        auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
        auto state = glfwGetKey(window, keycode);
        return state == GLFW_PRESS || state == GLFW_REPEAT;
    }
    bool OpenGLInput::IsMouseButtonPressedImpl(int button)
    {
        auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
        auto state = glfwGetMouseButton(window, button);
        return state == GLFW_PRESS;
    }
    std::pair<float, float> OpenGLInput::GetMousePositionImpl()
    {
        auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
        double xpos, ypos;
        glfwGetCursorPos(window, &xpos, &ypos);
        return {(float)xpos, (float)ypos};
    }
    float OpenGLInput::GetMouseXImpl()
    {
        auto[x, y] = GetMousePositionImpl();
        return x;
    }
    float OpenGLInput::GetMouseyImpl()
    {
        auto[x, y] = GetMousePositionImpl();
        return y;
    }
}