// SFML_MultipleSortVisualiser.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "menu.h"



int main()
{
	sf::RenderWindow window;
	window.create(sf::VideoMode(constants::X_WIDTH, constants::Y_HEIGHT), "Sort Visualiser");
	menu sortMenu(constants::X_WIDTH, constants::Y_HEIGHT);

	std::vector<int> nums = drawingUtils::generateRandomNumbers(constants::AMOUNT_OF_NUMS_TO_GENERATE);
	bool sorted = 0;

	while (window.isOpen()) {
		drawMenu(sortMenu, window, nums, sorted);
	}
	return 0;
}