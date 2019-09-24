#include "stdafx.h"
#include "DesignSearchAutocompleteSystem.h"

AutocompleteSystem::AutocompleteSystem(vector<string>& sentences, vector<int>& times) {
	root = new TrieNode();
	reset();
	for (int i = 0; i < sentences.size(); i++) buildTrie(sentences[i], times[i]);
}

vector<string> AutocompleteSystem::input(char c) {
	vector<string>res;
	if (c == '#') {
		buildTrie(sentence, 1);
		reset();
		return res;
	}
	sentence.push_back(c);
	cur = cur->next[c];
	if (!cur) cur = new TrieNode();
	dfs(sentence, cur);
	while (!pq.empty()) {
		res.push_back(pq.top().first);
		pq.pop();
	}
	reverse(res.begin(), res.end());
	return res;
}

void AutocompleteSystem::buildTrie(string s, int time) {
	auto p = root;
	for (auto c : s) {
		if (!p->next[c]) p->next[c] = new TrieNode();
		p = p->next[c];
	}
	p->time += time;
}

void AutocompleteSystem::dfs(string& s, TrieNode* p) {
	if (p->time) {
		pq.push({ s, p->time });
		while (pq.size() > 3) pq.pop();
	}
	for (auto x : p->next) {
		s.push_back(x.first);
		dfs(s, x.second);
		s.pop_back();
	}
}

void AutocompleteSystem::reset() {
	cur = root;
	sentence = "";
}

/* no trie
class AutocompleteSystem {
	unordered_map<string, int> dict;
	string data;

public:
	AutocompleteSystem(vector<string> sentences, vector<int> times) {
		for (int i = 0; i < times.size(); i++)
			dict[sentences[i]] += times[i];
		data.clear();
	}

	vector<string> input(char c) {
		if (c == '#') {
			dict[data]++;
			data.clear();
			return {};
		}

		data.push_back(c);
		auto cmp = [](const pair<string, int> &a, const pair<string, int> &b) {
			return a.second > b.second || a.second == b.second && a.first < b.first;
		};

		priority_queue<pair<string, int>, vector<pair<string, int>>, decltype(cmp)> pq(cmp);

		for (auto &p : dict) {
			bool match = true;
			for (int i = 0; i < data.size(); i++) {
				if (data[i] != p.first[i]) {
					match = false;
					break;
				}
			}
			if (match) {
				pq.push(p);
				if (pq.size() > 3)
					pq.pop();
			}
		}

		vector<string> res(pq.size());
		for (int i = pq.size() - 1; i >= 0; i--) {
			res[i] = pq.top().first;
			pq.pop();
		}
		return res;
	}
};
*/