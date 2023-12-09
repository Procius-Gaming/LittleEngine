#include <Little.h>

class ExampleLayer : public Little::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{
	}

	void OnUpdate() override
	{
		//LE_INFO("ExampleLayer::Update");
	}

	void OnEvent(Little::Event& event) override
	{
		LE_TRACE("TEST@,{0}", event);
	}
};




class SandBox : public Little::Application
{
public:
	SandBox()
	{
		PushLayer(new ExampleLayer());
		PushOverlay(new Little::ImGuiLayer());
    }

	~SandBox()
	{
	}
};

Little::Application* Little::CreateApplication()
{
	return new SandBox();
}

