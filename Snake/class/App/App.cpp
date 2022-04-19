#include "App.hpp"

App::App() {}

App::~App() {}

int App::go()
{
	SfmlWindow mainWindow{600, 600, "Snake: the Game"};
	return mainWindow.mainLoop();
}
