#include "stdafx.h"
#include "SearchSuggestionsSystem.h"

#include <algorithm>

/*
Intuition
In a sorted list of words,
for any word A[i],
all its sugested words must following this word in the list.

For example, if A[i] is a prefix of A[j],
A[i] must be the prefix of A[i + 1], A[i + 2], ..., A[j]

Explanation
With this observation,
we can binary search the position of each prefix of search word,
and check if the next 3 words is a valid suggestion.


Complexity
Time O(NlogN) for sorting
Space O(logN) for quick sort.

Time O(logN) for each query
Space O(query) for each query
where I take word operation as O(1)
*/

vector<vector<string>> Solution::suggestedProducts(vector<string>& products, string searchWord) {
  auto it = products.begin();
  sort(it, products.end());
  vector<vector<string>> res;
  string cur = "";
  for (char c : searchWord) {
    cur += c;
    vector<string> suggested;
    it = lower_bound(it, products.end(), cur);
    for (int i = 0; i < 3 && it + i != products.end(); i++) {
      string& s = *(it + i);
      if (s.find(cur)) break;
      suggested.push_back(s);
    }
    res.push_back(suggested);
  }
  return res;
}

/*
class Solution {
public:
  struct Trie {
    unordered_map<char, Trie*> next = {};
    priority_queue<string> suggest = {};
  };

  vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
    Trie *root = new Trie();
    for (auto word : products) {
      Trie *ptr = root;
      for (auto c : word) {
        if (!ptr->next.count(c)) {
          ptr->next[c] = new Trie();
        }
        ptr = ptr->next[c];
        ptr->suggest.push(word);
        if (ptr->suggest.size() > 3) {
          ptr->suggest.pop();
        }
      }
    }

    vector<vector<string>> result(searchWord.length());
    for (int i = 0; i < searchWord.length() && root->next.count(searchWord[i]); ++ i) {
      root = root->next[searchWord[i]];
      vector<string> match(root->suggest.size());
      for (int i = root->suggest.size()-1; i >= 0; -- i) {
        match[i] = root->suggest.top();
        root->suggest.pop();
      }
      result[i] = match;
    }
    return result;
  }
};
*/