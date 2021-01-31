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
		if (Hazel::Input::IsKeyPressed(VELOCE_KEY_TAB))
			VELOCE_TRACE("Tab key is pressed (poll)!");
	}

	void OnEvent(Veloce::Event& event) override
	{
		if (event.GetEventType() == Veloce::EventType::KeyPressed)
		{	
			auto& e = dynamic_cast<Veloce::KeyPressedEvent&>(event);
			if (e.GetKeyCode() == VELOCE_KEY_TAB)
				VELOCE_TRACE("Tab key is pressed (event)!");
			VELOCE_TRACE("{0}", static_cast<char>(e.GetKeyCode()));
		}
	}

};

class Sandbox : public Veloce::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
		PushOverlay(new Veloce::ImGuiLayer());
	}
};

Veloce::Application* Veloce::CreateApplication()
{
	return new Sandbox();
}