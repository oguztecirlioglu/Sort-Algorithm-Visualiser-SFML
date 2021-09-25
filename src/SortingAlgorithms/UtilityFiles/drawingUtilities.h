#ifndef DRAWINGUTILITIES_H_INCLUDED
#define DRAWINGUTILITIES_H_INCLUDED

#include <vector>
#include <numeric>
#include <random>
#include <SFML/Graphics.hpp>
#include "constants.h"


namespace drawingUtils {
	std::vector<int> generateRandomNumbers(int amountOfNums);
	void drawColumns(std::vector<int>& numsVector, sf::RenderWindow& window);
	void grabEvents(sf::RenderWindow& window);
}

#endif
