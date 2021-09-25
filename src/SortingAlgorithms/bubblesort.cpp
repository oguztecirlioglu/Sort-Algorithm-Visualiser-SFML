#include "bubblesort.h"

/* 
Inputs: A vector of ints, which should be the random integers from 1 to n, randomly sorted.
A window object from the SFML library so that events can be drawn to it.

Purpose: Sorts the given numsArray with bubblesort, drawing the updated columns to the screen each and only each time a swap is made.

Outputs: Nothing.
*/
void bubblesort(std::vector<int>& numsArray, sf::RenderWindow& window) {
	int size = numsArray.size();
	
	drawingUtils::drawColumns(numsArray, window);

	for (int i = 0; i < size; ++i) {
		bool swapped = false;
		for (int j = 0; j < size - 1; j++) {
			if (numsArray[j] > numsArray[j + 1]) {
				sortingUtils::swap(numsArray[j], numsArray[j + 1]);
				swapped = true;
				drawingUtils::drawColumns(numsArray, window);
			}
		}
	}
}