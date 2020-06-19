#include "stdafx.h"
#include "SlidingPuzzle.h"

#include <string>
#include <unordered_set>
#include <queue>

/*
The nodes are comprised of each candidate string, and nodes are "connected" to each other if they are not already visited and are one move away from each other...

board = {
{ 1,2,3 },
{ 4,0,5 },
};

begin = 123405

depth 0:           123405   <== 0 is at index 4, nextMoves[4]={1,3,5}, so swap 0 with the value
                 /   |    \       at each index 1,3,5 to form the next candidates to be pushed
                /    |     \      onto q in preparation for the next depth of processing
               /     |      \
depth 1:    103425  123045  123450   <== next candidates pushed onto q
                           (target)
*/
int Solution::slidingPuzzle(vector<vector<int>>& board) {
  string target = "123450",

  begin = to_string(board[0][0]) + to_string(board[0][1]) + to_string(board[0][2]) 
    + to_string(board[1][0]) + to_string(board[1][1]) + to_string(board[1][2]);

  // This is the board representation on what indices you can swap 0 with since you can only swap adjacents one
  //board = {
  //{ 1,2,3 },
  //{ 4,0,5 },
  //};
  vector<vector<int>> nextMoves{ {1,3},{0,2,4},{1,5},{0,4},{1,3,5},{2,4} };

  unordered_set<string> visited{ begin };
  queue<string> q; q.push(begin);
  int depth = -1;
  while (!q.empty()) {
    depth++;
    int size = (int)q.size();
    for (int i = 0; i < size; ++i) {
      auto curr = q.front();
      q.pop();

      if (curr == target) return depth;

      int zero = (int)curr.find("0");
      for (auto next : nextMoves[zero]) {
        auto candidate = curr;
        swap(candidate[zero], candidate[next]);

        if (visited.find(candidate) == visited.end()) {
          visited.insert(candidate);
          q.push(candidate);
        }
      }
    }
  }
  return -1;
}