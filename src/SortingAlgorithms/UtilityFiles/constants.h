#ifndef CONSTANTS_H_INCLUDED
#define CONSTANTS_H_INCLUDED


#include <SFML/Window.hpp>
#include "drawingUtilities.h"

namespace constants {
	// Screen size
	const int originalX = sf::VideoMode::getDesktopMode().width / 150;
	const int originalY = sf::VideoMode::getDesktopMode().height / 150;

	const int X_WIDTH = originalX * 100;// Makes the X_WIDTH a multiple of hundred, depending on user screen size.
	const int Y_HEIGHT = originalY * 100; // Makes the X_WIDTH a multiple of hundred, depending on user screen size.
	
	// Menu stuff
	const int NUMBER_OF_ITEMS_ON_MENU = 3;


	// How many numbers to generate, the width of each column etc.
	const int AMOUNT_OF_NUMS_TO_GENERATE = 100;
	const int WIDTH_OF_COLUMN = X_WIDTH / AMOUNT_OF_NUMS_TO_GENERATE;

}

#endif