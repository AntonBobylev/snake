#pragma once
#include <iostream>

namespace config {
	const std::string APPLICATION_VERSION = "1.0.0";
	const std::string APPLICATION_NAME = "Snake: The Game v" + APPLICATION_VERSION;
	const std::string APPLICATION_ICON_PATH = "resources/icon.png";

	const unsigned int WINDOW_WIDTH = 600;
	const unsigned int WINDOW_HEIGHT = 600;

	const unsigned int SNAKE_TEXTURE_SIZE = 32; // snake texture size : 32x32
	const float SNAKE_STEP = 0.1f; // snake texture size : 32x32

	const unsigned int SNAKE_MAX_LENGTH = 100;
}