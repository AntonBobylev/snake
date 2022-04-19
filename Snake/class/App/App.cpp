#include "App.hpp"

App::App() {}

App::~App() {}

int App::go()
{
	SfmlWindow mainWindow;
	return mainWindow.mainLoop();
}
