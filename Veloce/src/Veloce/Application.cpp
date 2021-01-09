#include "velpch.h"
#include "Application.h"

#include "Veloce/Events/ApplicationEvent.h"
#include "Veloce/Log.h"

#include <GLFW/glfw3.h>

namespace Veloce
{
	Application::Application()
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
	}

	Application::~Application()
	{

	}

	void Application::Run()
	{
		while (m_Running)
		{
			m_Window->OnUpdate();
		}
	}
}