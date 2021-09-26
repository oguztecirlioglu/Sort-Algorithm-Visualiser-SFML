#include "menu.h"
#include <iostream>

menu::menu(int width, int height) {
	if (!font.loadFromFile("arial.ttf")) {
		// handle error
		std::cout << "error font" << std::endl;
	}
	std::vector<std::string> itemNames = { "Bubble Sort", "Quick Sort", "Merge Sort","Exit"};
	assignMenuItems(itemNames);

	//initialise the state variables of this object.
	numberOfMenuItems = itemNames.size();
	selectedItemIndex = 0;
};

menu::~menu() {};

void menu::draw(sf::RenderWindow& window)
{
	for (int i = 0; i < numberOfMenuItems; i++) {
		window.draw(menuItems[i]);
	}
}

void menu::assignMenuItems(std::vector<std::string> itemNames) {
	
	for (int i = 0; i < numberOfMenuItems; ++i) {
		menuItems[i].setCharacterSize(55);
		menuItems[i].setFont(font);
		menuItems[i].setFillColor(sf::Color::Blue);
		menuItems[i].setString(itemNames[i]);
		menuItems[i].setPosition(sf::Vector2f(constants::X_WIDTH / 10, (i+1) * (constants::Y_HEIGHT/(itemNames.size()+3)) ));
	}
	menuItems[0].setFillColor(sf::Color::White);
}

void menu::MoveUp() {
	if (selectedItemIndex - 1 >= 0) {
		menuItems[selectedItemIndex].setFillColor(sf::Color::Blue);
		selectedItemIndex--;
		menuItems[selectedItemIndex].setFillColor(sf::Color::White);
	}
}

void menu::MoveDown() {
	if(selectedItemIndex + 1 < constants::NUMBER_OF_ITEMS_ON_MENU) {
		menuItems[selectedItemIndex].setFillColor(sf::Color::Blue);
		selectedItemIndex++;
		menuItems[selectedItemIndex].setFillColor(sf::Color::White);
	}
}

int menu::getPressedItem() {
	return selectedItemIndex;
}

void drawMenu(menu& sortMenu, sf::RenderWindow& window, std::vector<int>& nums, bool& sorted) {
	sf::Event event;
	if (sorted == true) {
		nums = drawingUtils::generateRandomNumbers(constants::AMOUNT_OF_NUMS_TO_GENERATE);
	}
	while (window.pollEvent(event))
	{
		switch (event.type) {
		case sf::Event::Closed:
			window.close();
			break;

		case sf::Event::KeyReleased:
			switch (event.key.code) {
			case sf::Keyboard::Up:
				sortMenu.MoveUp();
				break;

			case sf::Keyboard::Down:
				sortMenu.MoveDown();
				break;

			case sf::Keyboard::Return:
				switch (sortMenu.getPressedItem()) {
				case 0:
					drawingUtils::grabEvents(window);
					bubblesort(nums, window);
					sorted = true;
					break;

				case 1:
					drawingUtils::grabEvents(window);
					quicksort(nums, 0, nums.size() - 1, window);
					sorted = true;
					break;

				case 2:
					drawingUtils::grabEvents(window);
					mergeSort(nums, 0, nums.size() - 1, window);
					sorted = true;

					break;
				
				case 3:
					window.close();
					break;
				}
				break;
			}
		}
	}

	window.clear();

	sortMenu.draw(window);

	window.display();
}