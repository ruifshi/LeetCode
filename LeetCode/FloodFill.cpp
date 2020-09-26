#include "stdafx.h"
#include "FloodFill.h"

void dfs(vector<vector<int>>& image, int i, int j, int origColor, int newColor) {
  if (i < 0 || j < 0 || i >= image.size() || j >= image[0].size() || image[i][j] != origColor) return;
  image[i][j] = newColor;
  dfs(image, i, j - 1, origColor, newColor);
  dfs(image, i, j + 1, origColor, newColor);
  dfs(image, i - 1, j, origColor, newColor);
  dfs(image, i + 1, j, origColor, newColor);
}

vector<vector<int>> Solution::floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
  if (image[sr][sc] != newColor)
    dfs(image, sr, sc, image[sr][sc], newColor);
  return image;
}