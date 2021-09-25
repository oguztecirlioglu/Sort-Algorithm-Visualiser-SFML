#include "quicksort.h"
#include <iostream>

/* Inputs: A vector of ints, which should be the random integers from 1 to n, randomly sorted.
A window object from the SFML library so that events can be drawn to it.
int low, initially 0, and int high, initially the last element of the vector of ints given.

Purpose : Sorts the given numsArray with quicksort. The window is passed into the partition function, 
and each time a swap is made in the partition function the new changes get drawn to the window.

Outputs : Nothing.
*/
void quicksort(std::vector<int>& numsArray, int low, int high, sf::RenderWindow& window) {
	if (low < high)
	{
		/* pi is partitioning index, arr[p] is now
		   at right place */
		int pi = partition(numsArray, low, high, window);

		// separately sort elements before
		// partition and after partition
		drawingUtils::grabEvents(window);
		quicksort(numsArray, low, pi - 1, window);
		quicksort(numsArray, pi + 1, high, window);
	}
}

/*
The partition function that is usually seen with psuedocodes of bubblesort. Same inputs as quicksort().
Output: returns the index where the partition is made (all elements before x are smaller, all after x are larger).
*/
int partition(std::vector<int>& numsArray, int low, int high, sf::RenderWindow& window) {
	int size = numsArray.size();
	int pivot = numsArray[high];    // pivot
	int i = (low - 1);  // Index of smaller element

	for (int j = low; j <= high - 1; j++)
	{
		drawingUtils::grabEvents(window);
		/*If current element is smaller than or
		equal to pivot*/
		if (numsArray[j] <= pivot)
		{
			i++;    // increment index of smaller element
			sortingUtils::swap(numsArray[i], numsArray[j]);
		}
		drawingUtils::drawColumns(numsArray, window);
	}
	sortingUtils::swap(numsArray[i + 1], numsArray[high]);
	drawingUtils::drawColumns(numsArray, window);

	return (i + 1);
}