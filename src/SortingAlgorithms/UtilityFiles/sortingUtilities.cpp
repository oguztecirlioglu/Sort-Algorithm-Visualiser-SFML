#include "sortingUtilities.h"

// Include files needed for the functions. I could have done this in the header file too, but idk which is the better convention.
#include <iostream>


// Swaps two numbers by reference. Pointers could have been used but this is unsafer(?) practice, and backwards compatibility with C isnt needed. 
void sortingUtils::swap(int& x, int& y)
{
	int temp = x;
	x =  y;
	y = temp;
	return;
}

// Prints the array of vector<int> given. A function used during initial development just to visualise things on the console.
void sortingUtils::printArray(std::vector<int>& numsArray)
{
	int i;
	for (int num : numsArray) {
		std::cout << num << " || ";
	}
	std::cout << std::endl;
}