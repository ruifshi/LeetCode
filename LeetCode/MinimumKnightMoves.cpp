#include "stdafx.h"
#include "MinimumKnightMoves.h"

#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

int Solution::minKnightMoves(int x, int y) {
  if (x == 0 && y == 0)
    return 0;
  queue<pair<int, int>> q;
  q.push({ 0,0 });
  vector<vector<int>> directions = { {1,2},{2,1},{2,-1},{1,-2},{-1,2},{-2,1},{-1,-2},{-2,-1} };
  int steps = 0;
  unordered_map<int, unordered_map<int, bool>> visited;
  visited[0][0] = true;
  while (!q.empty())
  {
    steps++;
    int size = q.size();
    for (int i = 0; i < size;i++)
    {
      auto front = q.front();
      q.pop();
      for (const auto& dir : directions)
      {
        int nextx = front.first + dir[0];
        int nexty = front.second + dir[1];
        if (nextx == x && nexty == y)
        {
          return steps;
        }
        if (!visited[nextx][nexty] && (nextx * x >= 0 && nexty * y >= 0 || steps < 3))  // quadrant pruning
        {
          visited[nextx][nexty] = true;
          q.push({ nextx,nexty });
        }
      }
    }
  }
  return -1;
}