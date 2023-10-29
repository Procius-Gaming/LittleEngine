#pragma once

#ifdef LE_PLATFORM_WINDOWS

// to do
#else

extern Little::Application* Little::CreateApplication();

int main(int argc, char** argv)
{
	printf("Init Little Engine\n");
	auto app = Little::CreateApplication();
	app->Run();
	delete app;
}
#endif
