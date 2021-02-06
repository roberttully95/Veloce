#pragma once

namespace Veloce {

	class VELOCE_API GraphicsContext
	{
	public:		
		virtual void Init() = 0;
		virtual void SwapBuffers() = 0;
	};

}