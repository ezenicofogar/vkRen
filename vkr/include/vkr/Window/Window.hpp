#pragma once
#include <vkr/API.hpp>

namespace vkr
{

	class VKR_API Window
	{
		void* GLFWwindow_ptr;
		bool isActive{ false };
		void closeWindow();

	public:
		// BASE
		Window(size_t _width, size_t _height, const char* _title);
		~Window();

		// COPY
		Window(const Window&) = delete;
		Window& operator=(const Window&) = delete;

		// MOVE
		Window(Window&&) = default;
		Window& operator=(Window&&) = default;

		// FUNCTIONS
		bool isRunning();

	};

}
