#include <vkrApplication.hpp>

int main()
{
	{
		vkr::Window x{ 800, 600, "Uwu" };
		while (x.isRunning()) {}
	}
	return 0;
}
