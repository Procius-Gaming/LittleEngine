#pragma once
#include "Core.h"
#include "Event.h"
#include "Window.h"


namespace Little {

    class LITTLE_API Application
	{
    public:
		Application();
		virtual ~Application();

		void Run();
		void OnEvent(Event& e);
	private:
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
	};

	// to be define in client
	Application* CreateApplication();

}
