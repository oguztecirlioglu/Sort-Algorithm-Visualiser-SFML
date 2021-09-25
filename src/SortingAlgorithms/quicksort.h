#ifndef QUICKSORT_H_INCLUDED
#define QUICKSORT_H_INCLUDED

//include needed files
#include <vector>
#include <SFML/Graphics.hpp>
#include "UtilityFiles/drawingUtilities.h"
#include "UtilityFiles/sortingUtilities.h"

void quicksort(std::vector<int>& numsArray, int low, int high, sf::RenderWindow& window);
int partition(std::vector<int>& numsArray, int low, int high, sf::RenderWindow& window);

#endif // !QUICKSORT_H_INCLUDED