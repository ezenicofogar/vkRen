// PROJECT
#include <vkr/Window/Window.hpp>

// LIBRARIES
#include <GLFW/glfw3.h>

// STD
#include <exception>
#include <mutex>

namespace vkr
{

	static size_t windowCount{ 0U };
	static std::mutex wmThread{};

	void initWindowManager()
	{
		if (glfwInit() != GLFW_TRUE)
			throw std::exception{"Can't initialize window manager\n\tglfwInit() failed\n\t" __FILE__};
	}

	void destroyWindowManager()
	{
		glfwTerminate();
	}
	
	void Window::closeWindow()
	{
		if (!isActive) return;

		wmThread.lock();

		isActive = false;

		glfwDestroyWindow((GLFWwindow*)GLFWwindow_ptr);

		windowCount--;
		if (!windowCount)
			destroyWindowManager();

		wmThread.unlock();
	}

	Window::Window(size_t _width, size_t _height, const char* _title)
	{
		wmThread.lock();

		if (!windowCount)
			initWindowManager();
		windowCount++;

		glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
		glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

		GLFWwindow_ptr = glfwCreateWindow(_width, _height, _title, nullptr, nullptr);

		isActive = true;

		wmThread.unlock();
	}
	
	Window::~Window()
	{
		closeWindow();
	}
	
	bool Window::isRunning()
	{
		if (isActive)
		{
			wmThread.lock();
			glfwPollEvents();
			wmThread.unlock();
			if (glfwWindowShouldClose((GLFWwindow*)GLFWwindow_ptr))
				closeWindow();
		}
		return isActive;
	}

}
