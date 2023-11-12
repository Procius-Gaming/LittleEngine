#include "Application.h"

#include "ApplicationEvent.h"
#include "Log.h"

namespace Little {

	#define BIND_EVENT_FN(x) std::bind(&x, this, std::placeholders::_1)

    Application::Application()
		{
			m_Window = std::unique_ptr<Window>(Window::Create());
			m_Window->SetEventCallback(BIND_EVENT_FN(Application::OnEvent));
		}

		Application::~Application()
		{
		}

		void Application::Run()
		{
			
			while(m_Running)
			{
				m_Window->OnUpdate();
			}
		}

        void Application::OnEvent(Event &e)
        {
			LE_CORE_INFO("{0}", e);
        }
}
