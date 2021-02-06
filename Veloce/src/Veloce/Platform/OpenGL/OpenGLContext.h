#pragma once

#include "Veloce/Renderer/GraphicsContext.h"

struct GLFWwindow;

namespace VELOCE
{
	class VELOCE_API OpenGLContext : public Veloce::GraphicsContext
	{
	public:
		OpenGLContext(GLFWwindow* windowHandle);

		void Init() override;
		void SwapBuffers() override;
	private:
		GLFWwindow* m_WindowHandle;
	};
}
