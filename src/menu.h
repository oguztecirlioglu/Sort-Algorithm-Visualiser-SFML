#pragma once
#include "SFML/Graphics.hpp"
#include "SortingAlgorithms/UtilityFiles/constants.h"
#include "SortingAlgorithms/quicksort.h"
#include "SortingAlgorithms/UtilityFiles/drawingUtilities.h"
#include "SortingAlgorithms/bubblesort.h"
#include "SortingAlgorithms/mergeSort.h"

class menu
{
public:
	menu(int width, int height);
	~menu();

	void draw(sf::RenderWindow& window);
	void MoveUp();
	void MoveDown();
	int getPressedItem();

private:
	int numberOfMenuItems = constants::NUMBER_OF_ITEMS_ON_MENU;
	int selectedItemIndex;
	sf::Font font;
	sf::Text menuItems[constants::NUMBER_OF_ITEMS_ON_MENU];
	void assignMenuItems(std::vector<std::string> itemNames);

};

void drawMenu(menu& sortMenu, sf::RenderWindow& window, std::vector<int>& numsArray, bool& sorted);