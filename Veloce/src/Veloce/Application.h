#pragma once

#include "Core.h"
#include "Events/Event.h"
#include "Veloce/Events/ApplicationEvent.h"

#include "Window.h"

namespace Veloce
{
	class VELOCE_API Application
	{
	public:
		Application();
		virtual ~Application();

		void OnEvent(Event& e);
		void Run();

	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
	};

	// To be defined in client.
	Application* CreateApplication();
}

