#include "class/SfmlWindow/SfmlWindow.hpp"

int main()
{
	SfmlWindow mainWindow{ "Snake: the Game" };
	mainWindow.mainLoop();
	return 0;
}