#pragma once

#ifdef VEL_PLATFORM_WINDOWS

extern Veloce::Application* Veloce::CreateApplication();

int main(int argc, char** argv)
{
	Veloce::Log::Init();
	VELOCE_CORE_WARN("Initialized Core Logger!");
	VELOCE_INFO("Initialized Client Logger!");

	auto app = Veloce::CreateApplication();
	app->Run();
	delete app;
}

#endif