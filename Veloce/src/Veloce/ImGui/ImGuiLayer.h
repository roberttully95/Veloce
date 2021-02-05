#pragma once

#include "Veloce/Layer.h"
#include "Veloce/Events/ApplicationEvent.h"
#include "Veloce/Events/KeyEvent.h"
#include "Veloce/Events/MouseEvent.h"

namespace Veloce
{
	class VELOCE_API ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();
		
		void OnAttach() override;
		void OnDetach() override;
		void OnImGuiRender() override;

		static void Begin();
		static void End();
		
	private:
		float m_Time;
	};
}
