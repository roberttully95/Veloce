#include <Veloce.h>

class ExampleLayer : public Veloce::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{
	}

	void OnUpdate() override
	{
		VELOCE_INFO("ExampleLayer::Update");
	}

	void OnEvent(Veloce::Event& event) override
	{
		VELOCE_TRACE("{0}", event);
	}

};

class Sandbox : public Veloce::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
	}

	~Sandbox()
	{

	}
};

Veloce::Application* Veloce::CreateApplication()
{
	return new Sandbox();
}