#pragma once

#include "Core.h"
#include "Window.h"
#include "Veloce/LayerStack.h"
#include "Veloce/Events/Event.h"
#include "Veloce/Events/ApplicationEvent.h"
#include "Veloce/ImGui/ImGuiLayer.h"

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

		[[nodiscard]] static Application& Get(){ return *s_Instance; }
		[[nodiscard]] Window& GetWindow() const { return *m_Window; }

		unsigned int m_VertexArray, m_VertexBuffer, m_IndexBuffer;
	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		ImGuiLayer* m_ImGuiLayer;
		bool m_Running = true;
		LayerStack m_LayerStack;

		static Application* s_Instance;
	};

	// To be defined in client.
	Application* CreateApplication();
}

