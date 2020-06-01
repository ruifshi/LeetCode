#include "stdafx.h"
#include "LeftmostColumnWithAtLeastAOne.h"

#include <algorithm>

vector<int> BinaryMatrix::dimensions() {
  return { 0,0 };
}

int BinaryMatrix::get(int row, int col) {
  return 0;
}

// row sorted so next row can't be smaller than current
int Solution::leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
  int rows = binaryMatrix.dimensions()[0];
  int cols = binaryMatrix.dimensions()[1];
  int smallestIndex = cols;
  for (int row = 0; row < rows; row++) {
    // Binary Search for the first 1 in the row.
    int lo = 0;
    int hi = cols - 1;
    while (lo < hi) {
      int mid = (lo + hi) / 2;
      if (binaryMatrix.get(row, mid) == 0) {
        lo = mid + 1;
      }
      else {
        hi = mid;
      }
      // If the last element in the search space is a 1, then this row
      // contained a 1.
      if (binaryMatrix.get(row, lo) == 1) {
        smallestIndex = min(smallestIndex, lo);
      }
    }
  }
  // If smallest_index is still set to cols, then there were no 1's in 
  // the grid. 
  return smallestIndex == cols ? -1 : smallestIndex;

/*
  //When we encounter a 0, we know that the leftmost 1 can't be to the left of it.
  //When we encounter a 1, we should continue the search on that row (move pointer to the left), in order to find an even smaller index.
  int rows = binaryMatrix.dimensions()[0];
  int cols = binaryMatrix.dimensions()[1];

  // Set pointers to the top-right corner.
  int currentRow = 0;
  int currentCol = cols - 1;

  // Repeat the search until it goes off the grid.
  while (currentRow < rows && currentCol >= 0) {
    if (binaryMatrix.get(currentRow, currentCol) == 0) {
      currentRow++;
    } else {
      currentCol--;
    }
  }

  // If we never left the last column, this is because it was all 0's.
  return (currentCol == cols - 1) ? -1 : currentCol + 1;
*/
}
