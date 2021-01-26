#pragma once

#include "Core.h"
#include "Window.h"
#include "Veloce/LayerStack.h"
#include "Veloce/Events/Event.h"
#include "Veloce/Events/ApplicationEvent.h"

namespace Veloce
{
	class VELOCE_API Application
	{
	public:
		Application();
		virtual ~Application();

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);
		
		void OnEvent(Event& e);
		void Run();

	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		LayerStack m_LayerStack;
	};

	// To be defined in client.
	Application* CreateApplication();
}

