#include "Application.h"

#include "ApplicationEvent.h"
#include "Log.h"

namespace Little {

    Application::Application()
		{
		}

		Application::~Application()
		{
		}

		void Application::Run()
		{
			WindowResizeEvent e(1280, 720);
			LE_TRACE(e);

			while(true);
		}

}
