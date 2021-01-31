#pragma once

#include "velpch.h"

#include "Veloce/Core.h"
#include "Veloce/Events/Event.h"

namespace Veloce {

	struct WindowProps
	{
		std::string Title;
		float Width;
		float Height;

		WindowProps(const std::string& title = "Veloce Engine",
		            const float width = 1280.0f,
		            const float height = 720.0f)
			: Title(title), Width(width), Height(height)
		{
		}
	};

	// Interface representing a desktop system based Window
	class VELOCE_API Window
	{
	public:
		using EventCallbackFn = std::function<void(Event&)>;

		virtual ~Window() {}

		virtual void OnUpdate() = 0;

		[[nodiscard]] virtual float GetWidth() const = 0;
		[[nodiscard]] virtual float GetHeight() const = 0;

		// Window attributes
		virtual void SetEventCallback(const EventCallbackFn& callback) = 0;
		virtual void SetVSync(bool enabled) = 0;
		[[nodiscard]] virtual bool IsVSync() const = 0;

		// Getter for window
		[[nodiscard]] virtual void* GetNativeWindow() const = 0;
		
		static Window* Create(const WindowProps& props = WindowProps());
	};

}
