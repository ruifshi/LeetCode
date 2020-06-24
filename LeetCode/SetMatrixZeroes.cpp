#include "stdafx.h"
#include "SetMatrixZeroes.h"

void Solution::setZeroes(vector<vector<int>>& matrix) {
  bool isCol = false;
  int R = matrix.size();
  int C = matrix[0].size();

  for (int i = 0; i < R; i++) {

    /*
    if you don't handle the first row separately, then if there is a zero in the row, we would mark matrix[0][0] 
    as zero (based on our core logic), which means the first column would be set all to 0s later on when in fact it may not be required.

    Vice versa, if we don't treat the first column separately, if there is a zero in the column, we would also mark 
    matrix[0][0] as zero, which means the first row would be set all to 0s later on when in fact it may not be required.
    */
    if (matrix[i][0] == 0) {
      isCol = true;
    }

    for (int j = 1; j < C; j++) {
      // If an element is zero, we set the first element of the corresponding row and column to 0
      if (matrix[i][j] == 0) {
        matrix[0][j] = 0;
        matrix[i][0] = 0;
      }
    }
  }

  // Iterate over the array once again and using the first row and first column, update the elements.
  for (int i = 1; i < R; i++) {
    for (int j = 1; j < C; j++) {
      if (matrix[i][0] == 0 || matrix[0][j] == 0) {
        matrix[i][j] = 0;
      }
    }
  }

  // See if the first row needs to be set to zero as well
  if (matrix[0][0] == 0) {
    for (int j = 0; j < C; j++) {
      matrix[0][j] = 0;
    }
  }

  // See if the first column needs to be set to zero as well
  if (isCol) {
    for (int i = 0; i < R; i++) {
      matrix[i][0] = 0;
    }
  }
}

/* brute force
class Solution {
  public void setZeroes(int[][] matrix) {
    int MODIFIED = -1000000;
    int R = matrix.length;
    int C = matrix[0].length;

    for (int r = 0; r < R; r++) {
      for (int c = 0; c < C; c++) {
        if (matrix[r][c] == 0) {
          // We modify the corresponding rows and column elements in place.
          // Note, we only change the non zeroes to MODIFIED
          for (int k = 0; k < C; k++) {
            if (matrix[r][k] != 0) {
              matrix[r][k] = MODIFIED;
            }
          }
          for (int k = 0; k < R; k++) {
            if (matrix[k][c] != 0) {
              matrix[k][c] = MODIFIED;
            }
          }
        }
      }
    }

    for (int r = 0; r < R; r++) {
      for (int c = 0; c < C; c++) {
        // Make a second pass and change all MODIFIED elements to 0 """
        if (matrix[r][c] == MODIFIED) {
          matrix[r][c] = 0;
        }
      }
    }
  }
}
*/

/* extra space
class Solution {
  public void setZeroes(int[][] matrix) {
    int R = matrix.length;
    int C = matrix[0].length;
    Set<Integer> rows = new HashSet<Integer>();
    Set<Integer> cols = new HashSet<Integer>();

    // Essentially, we mark the rows and columns that are to be made zero
    for (int i = 0; i < R; i++) {
      for (int j = 0; j < C; j++) {
        if (matrix[i][j] == 0) {
          rows.add(i);
          cols.add(j);
        }
      }
    }

    // Iterate over the array once again and using the rows and cols sets, update the elements.
    for (int i = 0; i < R; i++) {
      for (int j = 0; j < C; j++) {
        if (rows.contains(i) || cols.contains(j)) {
          matrix[i][j] = 0;
        }
      }
    }
  }
}
*/