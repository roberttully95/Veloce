#include "velpch.h"
#include "OpenGLContext.h"

#include <GLFW/glfw3.h>
#include <glad/glad.h>
#include <GL/GL.h>

namespace Veloce
{
	OpenGLContext::OpenGLContext(GLFWwindow* windowHandle)
		: m_WindowHandle(windowHandle)
	{
		VELOCE_CORE_ASSERT(windowHandle, "Window handle is null!")
	}

	void OpenGLContext::Init()
	{
		glfwMakeContextCurrent(m_WindowHandle);
		auto status = gladLoadGLLoader(reinterpret_cast<GLADloadproc>(glfwGetProcAddress));
		VELOCE_CORE_ASSERT(status, "Failed to initialize Glad!");

		// Output graphics info
		VELOCE_CORE_INFO("OpenGL Info:");
		VELOCE_CORE_INFO("  Vendor: {0}", glGetString(GL_VENDOR));
		VELOCE_CORE_INFO("  Renderer: {0}", glGetString(GL_RENDERER));
		VELOCE_CORE_INFO("  Version: {0}", glGetString(GL_VERSION));
	}

	void OpenGLContext::SwapBuffers()
	{
		glfwSwapBuffers(m_WindowHandle);
	}
}