#pragma once
#include "Core.h"
#include "Event.h"


namespace Little {

    class LITTLE_API Application
	{
    public:
		Application();
		virtual ~Application();

		void Run();
	};

	// to be define in client
	Application* CreateApplication();

}
