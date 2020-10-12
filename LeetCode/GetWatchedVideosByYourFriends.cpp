#include "stdafx.h"
#include "GetWatchedVideosByYourFriends.h"

#include <unordered_map>
#include <algorithm>
#include <queue>

vector<string> Solution::watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
  vector<bool> visited(friends.size(), false);      //To track the visited `friends`
  unordered_map<string, int> count;        // Stores the frequency of all the  `watchedVideos` by a freind at required level
  vector<pair<int, string>> resultPairs;
  vector<string> result;
  queue<int> q;

  q.push(id), visited[id] = true;            //Push initial node/friend id.
  while (!q.empty() && level--) { //BFS to get to the level.
    int qsize = q.size();

    for (int i = 0; i < qsize; i++) {
      int cur = q.front();
      q.pop();

      for (auto &i : friends[cur]) {
        if (!visited[i]) {
          q.push(i);
          visited[i] = true;
        }
      }
    }
  }

  while (!q.empty()) { //The queue at this moment will only have all the friends at required level
    for (string &s : watchedVideos[q.front()])  count[s]++;
    q.pop();
  }

  for (auto &x : count) //Add results to the vector to sort by frequency first and then the string.
    resultPairs.push_back({ x.second,x.first });

  sort(resultPairs.begin(), resultPairs.end());

  for (auto &x : resultPairs) {
    result.push_back(x.second);
  }
  
  return result;
}