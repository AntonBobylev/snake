#include "class/SfmlWindow/SfmlWindow.hpp"

int main()
{
	SfmlWindow mainWindow{ config::APPLICATION_NAME.c_str()};
	mainWindow.mainLoop();
	return 0;
}