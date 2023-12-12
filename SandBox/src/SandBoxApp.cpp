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
		if (Little::Input::IsKeyPressed(LE_KEY_TAB))
			LE_INFO("TAB IS PRESSED");
	}

	void OnEvent(Little::Event& event) override
	{
		
	}
};




class SandBox : public Little::Application
{
public:
	SandBox()
	{
		PushLayer(new ExampleLayer());
    }

	~SandBox()
	{
	}
};

Little::Application* Little::CreateApplication()
{
	return new SandBox();
}

