// SFML_MultipleSortVisualiser.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include "menu.h"



int main()
{
	// Create the SFML RenderWindow object named window. This is the popup window that the algorithms are visualised on.
	sf::RenderWindow window;

	// Creates a window of X_WIDTH by Y_HEIGHT size, with title Sort Visualiser
	window.create(sf::VideoMode(constants::X_WIDTH, constants::Y_HEIGHT), "Sort Visualiser");

	// Creates the object sortMenu, which is from class menu. The menu class basically implements the "main menu" functionality, where algorithms
	// can be chosen using the Arrow up and arrow down keys, then entered by hitting return (or enter).
	menu sortMenu(constants::X_WIDTH, constants::Y_HEIGHT);

	// Generates a randomly ordered series, from [1, AMOUNT_OF_NUMS_TO_GENERATE].
	std::vector<int> nums = drawingUtils::generateRandomNumbers(constants::AMOUNT_OF_NUMS_TO_GENERATE);

	// Global sorted flag. If false, nums (declared on line 21) is not sorted. 
	bool sorted = false;

	while (window.isOpen()) {
		drawMenu(sortMenu, window, nums, sorted);
	}
	return 0;
}