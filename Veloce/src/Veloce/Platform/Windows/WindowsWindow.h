#pragma once

#include "Veloce/Window.h"
#include "GLFW/glfw3.h"

namespace Veloce {

	class WindowsWindow : public Window
	{
	public:
		WindowsWindow(const WindowProps& props);
		virtual ~WindowsWindow();

		void OnUpdate() override;

		[[nodiscard]] float GetWidth() const override { return m_Data.Width; }
		[[nodiscard]] float GetHeight() const override { return m_Data.Height; }

		// Window attributes
		void SetEventCallback(const EventCallbackFn& callback) override { m_Data.EventCallback = callback; }
		void SetVSync(bool enabled) override;
		[[nodiscard]] bool IsVSync() const override;
	private:
		[[nodiscard]] void* GetNativeWindow() const override { return m_Window; }
		
		virtual void Init(const WindowProps& props);
		virtual void Shutdown();
		GLFWwindow* m_Window;

		struct WindowData
		{
			std::string Title;
			float Width, Height;
			bool VSync;

			EventCallbackFn EventCallback;
		};

		WindowData m_Data;
	};

}