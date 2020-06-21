#include "stdafx.h"
#include "FindTheKthSmallestSumOfAMatrixWithSortedRows.h"

#include <queue>

int Solution::kthSmallest2(vector<vector<int>>& mat, int k) {
  if (mat.size() == 0 || mat[0].size() == 0) return 0;

  priority_queue<int> pq;
  int row = mat.size();
  int col = mat[0].size();
  for (int i = 0; i < col && i < k; i++)
  {
    pq.push(mat[0][i]);//push all values in the first row to the priority queue as long as i<k
  }

  // for each row, get the sums of current row values + previous one and use
  // a pq to keep only the kth smallest
  for (int r = 1; r < row; r++)
  {
    priority_queue<int> pqnext;//create a new priority queue for each row
    while (!pq.empty())
    {
      int val = pq.top();//get the value at the top of the priority queue 
      pq.pop();//pop the value at the top
      for (int c = 0; c < col && c < k; c++)//loop through all columns in current row
      {

        pqnext.push(val + mat[r][c]);//add the value at the top of priority queue to the value in the current index;
        if (pqnext.size() > k) {//check if the size of the priority queue is greater than k
          if (pqnext.top() == val + mat[r][c])//check if the value added recently is the value to be popped from the queue
          {
            pqnext.pop();//pop the value from the new queue
            break;//exit the loop
          }
          pqnext.pop();//pop the value because it exceeds the size of the priority queue
        }

      }

    }

    pq = pqnext;//copy values from pqnext to pq

  }
  return pq.top();//return the value at the top (represents the kth smallest)
}