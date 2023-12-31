#pragma once

#ifdef LE_PLATFORM_WINDOWS
extern Little::Application* Little::CreateApplication();

int main(int argc, char** argv)
{
	printf("Init Little Engine\n");
	Little::Log::Init();
	LE_CORE_WARN("Log Init");
	LE_INFO("CLient log init");
	auto app = Little::CreateApplication();
	app->Run();
	delete app;
}
#elif LE_PLATFORM_LINUX

extern Little::Application* Little::CreateApplication();

int main(int argc, char** argv)
{
	printf("Init Little Engine\n");
	Little::Log::Init();
	LE_CORE_WARN("Log Init");
	LE_INFO("CLient log init");
	auto app = Little::CreateApplication();
	app->Run();
	delete app;
}
#else

#endif
