#include "stdafx.h"
#include "DesignALeaderboard.h"

//unordered_map<int, int> playerScore;  // keeps track of player to total score
//multiset<int> scoreSet; // keeps track of top scores

Leaderboard::Leaderboard() {
  playerScore.clear();
  scoreSet.clear();
}

// O(log n)
void Leaderboard::addScore(int playerId, int score) {
  if (playerScore.find(playerId) != playerScore.end())
    scoreSet.erase(scoreSet.find(playerScore[playerId]));

  playerScore[playerId] += score;
  scoreSet.insert(playerScore[playerId]);
}

// O(K)
int Leaderboard::top(int K) {
  int res = 0;
  for (auto itr = --scoreSet.end(); K > 0; K--, itr--) {
    res += *itr;
  }
  return res;
}

// O(log n)
void Leaderboard::reset(int playerId) {
  scoreSet.erase(scoreSet.find(playerScore[playerId]));
  playerScore.erase(playerId);
}