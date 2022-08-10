#pragma once
#include <vkr/API.hpp>

namespace vkr
{

	class VKR_API window
	{
		void* GLFWwindow_ptr;
		bool isActive{ false };
		void closeWindow();

	public:
		// BASE
		window(size_t _width, size_t _height, const char* _title);
		~window();

		// COPY
		window(const window&) = delete;
		window& operator=(const window&) = delete;

		// MOVE
		window(window&&) = default;
		window& operator=(window&&) = default;

		// FUNCTIONS
		bool isRunning();

	};

}
