#include <Veloce.h>

class Sandbox : public Veloce::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}
};

Veloce::Application* Veloce::CreateApplication()
{
	return new Sandbox();
}