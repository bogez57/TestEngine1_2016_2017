#pragma once
#include "Macro.h"
#include "UniversalTypeDefs.h"
#include "../Input/Input.h"
#include "../Framework/LowLevelWindow/WindowHandling.h"

namespace BlazeGraphics
{
	class Window
	{
	public:
		Window(uint16 width, uint16 height, char8* title);
		~Window();

		void Update();
		void Clear() const;
		bool Closed() const;

		//According to Scott Meyer's Modern Effective C++ book, having copy and = operator functions
		//public and equal to delete produce more descriptive error messages than just the normal
		//empty body (Window(const Window& copy) {}) under private 
		Window(const Window& copy) = delete;
		void operator=(const Window& copy) = delete;

	private:
		//Needed Input to have access to Window's m_window variable since underlying implementation 
		//requires a reference to BlazeWindow* (and not just a regular Window* object). Helps to avoid 
		//making m_window publicly available.
		friend class BlazeInput::Input;

		const uint16 cHeight = 0;
		const uint16 cWidth = 0;
		const char8* cpTitle = nullptr;

		BlazeFramework::WindowHandling::BlazeWindow* m_window;
	};
}
