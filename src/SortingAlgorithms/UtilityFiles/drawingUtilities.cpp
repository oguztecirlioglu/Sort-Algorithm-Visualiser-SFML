#include "drawingUtilities.h"

namespace drawingUtils {

	std::vector<int> generateRandomNumbers(int amountOfNums) {

		std::vector<int> returnVector(amountOfNums);

		std::iota(std::begin(returnVector), std::end(returnVector), 1);
		auto rng = std::default_random_engine{};
		std::shuffle(returnVector.begin(), returnVector.end(), rng);

		return returnVector;
	}

	void drawColumns(std::vector<int>& numsVector, sf::RenderWindow& window) {
		window.clear();

		std::vector<sf::RectangleShape> rects(numsVector.size());

		for (auto i = 0; i < numsVector.size(); ++i) {
			int currentHeight = 0.9 * constants::Y_HEIGHT / constants::AMOUNT_OF_NUMS_TO_GENERATE * numsVector[i];
			int thickness = 2;
			int currentWidth = constants::WIDTH_OF_COLUMN - 2 * thickness;

			rects[i].setSize(sf::Vector2f(currentWidth, currentHeight));
			rects[i].setPosition(sf::Vector2f(i * constants::WIDTH_OF_COLUMN, constants::Y_HEIGHT - currentHeight));
			rects[i].setFillColor(sf::Color(120, 50, 250));
			rects[i].setOutlineThickness(2.f);

			grabEvents(window);
			window.draw(rects[i]);
		}
		window.display();
	}

	/*
	A celever way to constantly check if the X button on the window has been pressed, taken from someone elses GitHub. 
	*/
	void grabEvents(sf::RenderWindow& screen)
	{
		sf::Event event;
		while (screen.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				screen.close();
		}
	}

}