#include "velpch.h"
#include "Application.h"

#include "Veloce/Events/ApplicationEvent.h"
#include "Veloce/Log.h"

namespace Veloce
{
	Application::Application()
	{

	}

	Application::~Application()
	{

	}

	void Application::Run()
	{
		WindowResizeEvent e(1280, 720);
		if (e.IsInCategory(EventCategoryApplication))
		{
			VELOCE_TRACE(e);
		}
		if (e.IsInCategory(EventCategoryInput))
		{
			VELOCE_TRACE(e);
		}

		while (true);
	}
}