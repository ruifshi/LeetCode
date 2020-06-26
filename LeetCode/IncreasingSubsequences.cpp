#include "stdafx.h"
#include "IncreasingSubsequences.h"

#include <set>

void findSubsequences(vector<int>& nums, int index, set<vector<int>> &subseqs, vector<int> &cur_seq) {
  if (cur_seq.size() >= 2) {
    subseqs.insert(cur_seq);
  }

  for (int i = index; i < nums.size(); i++) {
    // if first element or nums[i] is increasing or equal to from last element in cur_seq
    if (index == 0 || nums[i] >= cur_seq.back()) {
      cur_seq.push_back(nums[i]);
      findSubsequences(nums, i + 1, subseqs, cur_seq);
      cur_seq.pop_back();
    }
  }
}

vector<vector<int>> findSubsequences(vector<int>& nums) {
  set<vector<int>> subseqs;
  vector<int> cur_seq;
  findSubsequences(nums, 0, subseqs, cur_seq);

  return vector<vector<int>>(subseqs.begin(), subseqs.end());
}

/* The unordered_set is used to avoid [4,6,7(1)] and [4,6,7(2)] in a same level when we dfs. But it will not 
// skip [4,6,7(1),7(2)], because 7(2) is added in the next dfs level of [4,6,7(1)]. Every time we start a "next level dfs", 
// we will initialize a new unordered_set.
vector<vector<int>> findSubsequences(vector<int>& nums) {
    vector<vector<int>> res;
    vector<int> seq;
    dfs(res, seq, nums, 0);
    return res;
}

void dfs(vector<vector<int>>& res, vector<int>& seq, vector<int>& nums, int pos) {
    if(seq.size() > 1) res.push_back(seq);
    unordered_set<int> hash;
    for(int i = pos; i < nums.size(); ++i) {
        if((seq.empty() || nums[i] >= seq.back()) && hash.find(nums[i]) == hash.end()) {
            seq.push_back(nums[i]);
            dfs(res, seq, nums, i + 1);
            seq.pop_back();
            hash.insert(nums[i]);
        }
    }
}
*/