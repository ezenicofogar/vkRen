#include <vkrApplication.hpp>

int main()
{
	{
		vkr::window x{ 800, 600, "Uwu" };
		while (x.isRunning()) {}
	}
	return 0;
}
