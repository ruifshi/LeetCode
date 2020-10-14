#pragma once

#include <unordered_map>
#include <set>

using namespace std;

class Leaderboard {
private:
  unordered_map<int, int> playerScore;
  multiset<int> scoreSet;

public:
  Leaderboard();

  void addScore(int playerId, int score);

  int top(int K);

  void reset(int playerId);
};

/**
 * Your Leaderboard object will be instantiated and called as such:
 * Leaderboard* obj = new Leaderboard();
 * obj->addScore(playerId,score);
 * int param_2 = obj->top(K);
 * obj->reset(playerId);
 */