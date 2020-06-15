#include "stdafx.h"
#include "TheMaze.h"

#include <queue>

bool Solution::hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
  if (maze.size() == 0 || maze[0].size() == 0) return false;

  queue<pair<int, int>> q;
  vector<vector<bool>> visited(maze.size(), vector<bool>(maze[0].size(), false));

  q.push({ start[0], start[1] });
  visited[start[0]][start[1]] = true;

  vector<vector<int>> dirs{ {0,1}, {1,0}, {0,-1}, {-1,0} };

  while (!q.empty()) {
    int x = q.front().first;
    int y = q.front().second;
    q.pop();

    if (x == destination[0] && y == destination[1]) return true;

    for (auto dir : dirs) {
      int x2 = x + dir[0];
      int y2 = y + dir[1];

      // ball keeps rolling
      while (x2 >= 0 && x2 < maze.size() && y2 >= 0 && y2 < maze[0].size() && maze[x2][y2] == 0) {
        x2 += dir[0];
        y2 += dir[1];
      }

      // subtract one dir since previous while loop went one too far
      if (!visited[x2 - dir[0]][y2 - dir[1]]) {
        q.push({ x2 - dir[0], y2 - dir[1] });
        visited[x2 - dir[0]][y2 - dir[1]] = true;
      }
    }
  }

  return false;
}

/* dfs
public class Solution {
    public boolean hasPath(int[][] maze, int[] start, int[] destination) {
        boolean[][] visited = new boolean[maze.length][maze[0].length];
        return dfs(maze, start, destination, visited);
    }
    public boolean dfs(int[][] maze, int[] start, int[] destination, boolean[][] visited) {
        if (visited[start[0]][start[1]])
            return false;
        if (start[0] == destination[0] && start[1] == destination[1])
            return true;
        visited[start[0]][start[1]] = true;
        int r = start[1] + 1, l = start[1] - 1, u = start[0] - 1, d = start[0] + 1;
        while (r < maze[0].length && maze[start[0]][r] == 0) // right
            r++;
        if (dfs(maze, new int[] {start[0], r - 1}, destination, visited))
            return true;
        while (l >= 0 && maze[start[0]][l] == 0) //left
            l--;
        if (dfs(maze, new int[] {start[0], l + 1}, destination, visited))
            return true;
        while (u >= 0 && maze[u][start[1]] == 0) //up
            u--;
        if (dfs(maze, new int[] {u + 1, start[1]}, destination, visited))
            return true;
        while (d < maze.length && maze[d][start[1]] == 0) //down
            d++;
        if (dfs(maze, new int[] {d - 1, start[1]}, destination, visited))
            return true;
        return false;
    }
}
*/