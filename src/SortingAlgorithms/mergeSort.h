#pragma once

// include needed files

#include <vector>
#include <SFML/Graphics.hpp>
#include "UtilityFiles/drawingUtilities.h"
#include "UtilityFiles/sortingUtilities.h"

void mergeSort(std::vector<int>& numsArray, int l, int r, sf::RenderWindow& window);
void merge(std::vector<int>& numsArray, int start, int mid, int end, sf::RenderWindow& window);

