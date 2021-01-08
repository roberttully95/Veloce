#pragma once

#ifdef VEL_PLATFORM_WINDOWS

extern Veloce::Application* Veloce::CreateApplication();

int main(int argc, char** argv)
{
	auto app = Veloce::CreateApplication();
	app->Run();
	delete app;
}

#endif