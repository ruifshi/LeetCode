#include "stdafx.h"
#include "FriendCircles.h"

void dfs(vector<vector<int>>& M, int node, vector<bool> &visited) {
  for (int i = 0; i < M.size(); i++) {
    if (M[node][i] == 1 && !visited[i]) {
      visited[i] = true;
      dfs(M, i, visited);
    }
  }
}

// graph problem finding the number of connected components
int Solution::findCircleNum(vector<vector<int>>& M) {
  vector<bool> visited(M.size(), false);
  int count = 0;

  for (int i = 0; i < M.size(); i++) {
    if (!visited[i]) {
      dfs(M, i, visited);
      count++;
    }
  }

  return count;
}

/* bfs
public class Solution {
    public int findCircleNum(int[][] M) {
        int[] visited = new int[M.length];
        int count = 0;
        Queue < Integer > queue = new LinkedList < > ();
        for (int i = 0; i < M.length; i++) {
            if (visited[i] == 0) {
                queue.add(i);
                while (!queue.isEmpty()) {
                    int s = queue.remove();
                    visited[s] = 1;
                    for (int j = 0; j < M.length; j++) {
                        if (M[s][j] == 1 && visited[j] == 0)
                            queue.add(j);
                    }
                }
                count++;
            }
        }
        return count;
    }
}
*/