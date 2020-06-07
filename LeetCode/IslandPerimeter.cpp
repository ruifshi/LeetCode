#include "stdafx.h"
#include "IslandPerimeter.h"

/*
For every one we know that the square consists of four walls.
Now for every one found in the grid, don't add the walls which are surrounded by other blocks (i.e. 1s).
Add the ones not surrounded by any 1s (i.e. have 0 as adjacent element).
*/
int islandPerimeter(vector<vector<int>>& grid) {
  int res = 0;
  int r = grid.size();
  int c = grid[0].size();

  for (int i = 0; i < r; i++)
  {
    for (int j = 0; j < c; j++)
    {
      if (grid[i][j] == 1)
      {
        res += (i == 0 || grid[i - 1][j] == 0 ? 1 : 0);
        res += (i == r - 1 || grid[i + 1][j] == 0 ? 1 : 0);
        res += (j == 0 || grid[i][j - 1] == 0 ? 1 : 0);
        res += (j == c - 1 || grid[i][j + 1] == 0 ? 1 : 0);
      }
    }
  }

  return res;
}

/* Everytime we hit a bondary, we add 1. Set grid to -1 if already visited

int dfs(vector<vector<int>>& grid,int i,int j){
    if(i<0||j<0||i>grid.size()-1||j>grid[0].size()-1||grid[i][j]==0) return 1; 
    if(grid[i][j]==-1) return 0;
    grid[i][j]=-1;
    return dfs(grid,i-1,j)+dfs(grid,i,j-1)+dfs(grid,i+1,j)+dfs(grid,i,j+1);
}

int islandPerimeter(vector<vector<int>>& grid) {
    if(grid.size()==0) return 0;
    for(int i=0;i<grid.size();i++)
        for(int j=0;j<grid[0].size();j++)
            if(grid[i][j]==1) return dfs(grid,i,j);
    return 0;
}
*/