#pragma once

#include "Layer.h"
#include "KeyEvent.h"
#include "MouseEvent.h"
#include "ApplicationEvent.h"

namespace Little {

	class LITTLE_API ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnImGuiRender() override;

		void Begin();
		void End();
		
	private:
		float m_Time = 0.0f;
	};

}