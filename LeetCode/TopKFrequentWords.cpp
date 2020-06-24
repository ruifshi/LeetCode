#include "stdafx.h"
#include "TopKFrequentWords.h"

#include <unordered_map>
#include <queue>

struct comp
{
	bool operator()(const pair<int, string>& a, const pair<int, string>& b)
	{
		if(a.first != b.first) return a.first < b.first;
		return a.second > b.second;
	}
};

/*
struct comp
{
    bool operator()(const pair<int, string>& a, const pair<int, string>& b)
    {
        if(a.first != b.first) return a.first > b.first;
        return a.second < b.second;
    }
};

vector<string> Solution::topKFrequent(vector<string>& words, int k) {
  unordered_map<string, int> table;
  priority_queue<pair<int, string>, vector<pair<int, string>>, comp> q;

  for (int i = 0; i < words.size(); i++) {
      table[words[i]]++;
  }

  for (auto x : table) {
      q.push(make_pair(x.second, x.first));
      if(q.size() > k) {
          q.pop();
      }
  }

  words.clear();

  while(!q.empty()) {
      words.push_back(q.top().second);
      q.pop();
  }

  reverse(words.begin(), words.end());

  return words;
}
*/

bool comp(pair<int, string> a, pair<int, string> b) {
	if (a.first != b.first) return a.first > b.first;
	return a.second < b.second;
}

vector<string> Solution::topKFrequent(vector<string>& words, int k) {
	unordered_map<string, int> table;
	vector<pair<int, string>> vec;

	for (int i = 0; i < words.size(); i++) {
		table[words[i]]++;
	}

	for (auto x : table) {
		vec.push_back(make_pair(x.second, x.first));
	}

	sort(vec.begin(), vec.end(), comp);

	words.clear();

	for (int i = 0; i < k; i++) {
		words.push_back(vec[i].second);
	}

	return words;
}