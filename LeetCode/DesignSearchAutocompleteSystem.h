#include <unordered_map>
#include <vector>
#include <queue>

using namespace std;

struct TrieNode {
	int time;
	unordered_map<char, TrieNode*>next;
	TrieNode() :time(0) {}
};

struct Compare {
	bool operator() (pair<string, int>& p1, pair<string, int>& p2) {
		return p1.second == p2.second ? p1.first < p2.first : p1.second > p2.second;
	}
};

class AutocompleteSystem {
private:
	TrieNode* root;
	TrieNode* cur;
	string sentence;
	priority_queue<pair<string, int>, vector<pair<string, int>>, Compare>pq;

public:
	AutocompleteSystem(vector<string>& sentences, vector<int>& times);

	vector<string> input(char c);

	void buildTrie(string s, int time);
	void dfs(string& s, TrieNode* p);
	void reset();
};

/**
 * Your AutocompleteSystem object will be instantiated and called as such:
 * AutocompleteSystem* obj = new AutocompleteSystem(sentences, times);
 * vector<string> param_1 = obj->input(c);
 */