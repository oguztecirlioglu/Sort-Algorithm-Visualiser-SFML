#include "mergeSort.h"

// This code is contributed by shivanisinghss2110

// Merges two subarrays of arr[].
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
// Inplace Implementation
void merge(std::vector<int>& numsArray, int start, int mid, int end, sf::RenderWindow& window)
{
    int start2 = mid + 1;

    // If the direct merge is already sorted
    if (numsArray[mid] <= numsArray[start2]) {
        return;
    }

    // Two pointers to maintain start
    // of both arrays to merge
    while (start <= mid && start2 <= end) {
        drawingUtils::grabEvents(window);

        // If element 1 is in right place
        if (numsArray[start] <= numsArray[start2]) {
            start++;
        }
        else {
            int value = numsArray[start2];
            int index = start2;

            // Shift all the elements between element 1
            // element 2, right by 1.
            while (index != start) {
                numsArray[index] = numsArray[index - 1];
                index--;
                drawingUtils::drawColumns(numsArray, window);
            }
            numsArray[start] = value;

            // Update all the pointers
            start++;
            mid++;
            start2++;
        }
    }
}

/* l is for left index and r is right index of the
   sub-array of arr to be sorted */
void mergeSort(std::vector<int>& numsArray, int l, int r, sf::RenderWindow& window)
{
    drawingUtils::grabEvents(window);

    if (l < r) {

        // Same as (l + r) / 2, but avoids overflow
        // for large l and r
        int m = l + (r - l) / 2;

        // Sort first and second halves
        mergeSort(numsArray, l, m, window);
        mergeSort(numsArray, m + 1, r, window);

        merge(numsArray, l, m, r, window);
    }
}

// This code is contributed by shivanisinghss2110
// This mergeSort implementation in C++ is taken from: https://www.geeksforgeeks.org/in-place-merge-sort/
