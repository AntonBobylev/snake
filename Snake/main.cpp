#include "class/SfmlWindow/SfmlWindow.hpp"

int main()
{
	SfmlWindow mainWindow{ 600, 600, "Snake: the Game" };
	mainWindow.mainLoop();
	return 0;
}