#pragma once

#include "Core.h"

namespace Veloce
{
	class VELOCE_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	// To be defined in client.
	Application* CreateApplication();
}

