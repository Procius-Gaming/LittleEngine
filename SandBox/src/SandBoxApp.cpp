#include <Little.h>

class SandBox : public Little::Application
{
public:
	SandBox()
	{
    }

	~SandBox()
	{
	}
};

Little::Application* Little::CreateApplication()
{
	return new SandBox();
}

