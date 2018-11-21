#include "stdafx.h"
#include "NumIslands.h"

void rec(char** grid, int* visited, int gridRowSize, int gridColSize, int i, int j) {
    if(i<0 || j <0 || i >= gridRowSize || j >= gridColSize) {
        return;
    }
    if(!*((visited + i * gridColSize) + j ) && grid[i][j] == '1') {
        *((visited + i * gridColSize) + j)  = 1;
        rec(grid, visited, gridRowSize, gridColSize, i+1, j);
        rec(grid, visited, gridRowSize, gridColSize, i, j+1);
        rec(grid, visited, gridRowSize, gridColSize, i-1, j);
        rec(grid, visited, gridRowSize, gridColSize, i, j-1);
    }
}

int numIslands(char** grid, int gridRowSize, int gridColSize) {    
    int visited[10000][10000];
    int count = 0;
    int i;
    int j;
    
    if(gridRowSize <= 0 || gridColSize <= 0) {
        return 0;
    }

    for(i = 0; i < gridRowSize; i++) {
        for(j = 0; j < gridColSize; j++) {
            visited[i][j] = 0;
        }
    }
    
    for(i = 0; i < gridRowSize; i++) {
        for(j = 0; j < gridColSize; j++) {
            if(!visited[i][j] && grid[i][j] == '1') {
                count++;
                rec(grid, (int *)visited, gridRowSize, gridColSize, i, j);
            }
        }
    }
    
    return count;
}