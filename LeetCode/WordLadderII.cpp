#include "stdafx.h"
#include "WordLadderII.h"

#include <queue>
#include <unordered_set>

// beat 69.82% forward graph and bfs queue
vector<vector<string>> Solution::findLadders(string begin_word, string end_word, vector<string> & word_list) {
	unordered_set<string> dic(word_list.cbegin(), word_list.cend());
	if (dic.find(end_word) == dic.end())
		return {};

	// we don't consider a path like hit -> ... -> hit -> ...
	dic.erase(begin_word);

	int level = 0;
	int word_len = begin_word.size();

	unordered_map<string, int> from_pos;
	from_pos[begin_word] = -1; // we can change all positions for the begin word

	queue<string> q;
	q.push(begin_word);

	// This is what we add for word ladder II
	unordered_map<string, int> levels{ {begin_word, 1} };
	unordered_map<string, vector<string>> children;
	bool end_word_found = false;

	while (!q.empty() && !end_word_found) {
		++level;

		// queue size is changing, take it out now! otherwise we don't know
		// how many items are in the current level.
		int level_items = q.size();
		for (int i = 0; i < level_items; ++i) {
			string orig_word = q.front();

			// make a copy for modification since we have to remember the original word to
			// contruct the graph
			string new_word = orig_word;
			q.pop();
			for (int pos = 0; pos < word_len; ++pos) {
				if (pos == from_pos[orig_word])
					continue;

				char orig_char = orig_word[pos];
				for (char c = 'a'; c <= 'z'; ++c) {
					if (c == orig_char)
						continue;

					new_word[pos] = c;
					if (new_word == end_word || dic.find(new_word) != dic.end()) {
						// First time encounter new_word, 
						levels[new_word] = level + 1;
						children[orig_word].push_back(new_word);

						// we don't want to have a path like ... hot -> ... -> hot
						dic.erase(new_word);
						if (new_word == end_word) {
							end_word_found = true;
						}
						else {
							// queue new_word to the next level
							q.push(new_word);
							from_pos[new_word] = pos;
						}
					}
					else {
						auto it = levels.find(new_word);
						if (it != levels.end() && it->second == level + 1) {
							// if new_word is already constructed and we are on the previous level, put it in the graph
							children[orig_word].push_back(new_word);
						}

						// otherwise do nothing
					}
					new_word[pos] = orig_char;
				}
			}
		}
	}

	// standard dfs
	vector<vector<string>> res;
	if (end_word_found) {
		vector<string> line{ begin_word };
		dfs_wordladderii(end_word, begin_word, children, line, res);
	}
	return res;
}

void Solution::dfs_wordladderii(const string & end_word,
	const string & cur_word,
	const unordered_map<string, vector<string>>& children,
	vector<string> & line,
	vector<vector<string>> & res) {
	if (cur_word == end_word) {
		res.push_back(vector<string>(line.begin(), line.end()));
		return;
	}

	auto it = children.find(cur_word);
	if (it != children.end()) {
		for (const string & word : it->second) {
			line.push_back(word);
			dfs_wordladderii(end_word, word, children, line, res);
			line.pop_back();
		}
	}
}

/*
// beats 77.91% backward graph and queue
class Solution {
public:
	vector<vector<string>> findLadders(string begin_word, string end_word, vector<string> & word_list) {
		unordered_set<string> dic(word_list.cbegin(), word_list.cend());
		if (dic.find(end_word) == dic.end())
			return {};

		// we don't consider a path like hit -> ... -> hit -> ...
		dic.erase(begin_word);

		int level = 0;
		int word_len = begin_word.size();

		unordered_map<string, int> from_pos;
		from_pos[begin_word] = -1; // we can change all positions for the begin word

		queue<string> q;
		q.push(begin_word);

		// This is what we add for word ladder II
		unordered_map<string, int> levels{{begin_word, 1}};
		unordered_map<string, vector<string>> parents;
		bool end_word_found = false;

		while (!q.empty() && !end_word_found) {
			++level;

			// queue size is changing, take it out now! otherwise we don't know
			// how many items are in the current level.
			int level_items = q.size();
			for (int i = 0; i < level_items; ++i) {
				string orig_word = q.front();

				// make a copy for modification since we have to remember the original word to
				// contruct the graph
				string new_word = orig_word;
				q.pop();
				for (int pos = 0; pos < word_len; ++pos) {
					if (pos == from_pos[orig_word])
						continue;

					char orig_char = orig_word[pos];
					for (char c = 'a'; c <= 'z'; ++c) {
						if (c == orig_char)
							continue;

						new_word[pos] = c;
						if (new_word == end_word || dic.find(new_word) != dic.end()) {
							// First time encounter new_word,
							levels[new_word] = level + 1;
							parents[new_word].push_back(orig_word);

							// we don't want to have a path like ... hot -> ... -> hot
							dic.erase(new_word);
							if (new_word == end_word) {
								end_word_found = true;
							} else {
								// queue new_word to the next level
								q.push(new_word);
								from_pos[new_word] = pos;
							}
						} else {
							auto it = levels.find(new_word);
							if (it != levels.end() && it->second == level + 1) {
								// if new_word is already constructed and we are on the previous level, put it in the graph
								parents[new_word].push_back(orig_word);
							}

							// otherwise do nothing
						}
						new_word[pos] = orig_char;
					}
				}
			}
		}

		// standard dfs
		vector<vector<string>> res;
		if (end_word_found) {
			vector<string> line{end_word};
			dfs(begin_word, end_word, parents, line, res);
		}
		return res;
	}

private:
	void dfs(const string & begin_word,
			 const string & cur_word,
			 const unordered_map<string, vector<string>>& parents,
			 vector<string> & line,
			 vector<vector<string>> & res) {
		if (cur_word == begin_word) {
			res.push_back(vector<string>(line.rbegin(), line.rend()));
			return;
		}

		// use at instead of operator [] to avoid construct entry in parent
		// const also gurantees that
		for (const string & word : parents.at(cur_word)) {
			line.push_back(word);
			dfs(begin_word, word, parents, line, res);
			line.pop_back();
		}
	}
};
*/

/*
vector<vector<string>> Solution::findLadders(string beginWord, string endWord, vector<string>& wordList) {
	//very interesting problem
	//It can be solved with standard BFS. The tricky idea is doing BFS of paths instead of words!
	//Then the queue becomes a queue of paths.
	vector<vector<string>> ans;
	queue<vector<string>> paths;
	unordered_set<string> dict;
	
	for (int i = 0; i < wordList.size(); i++) {
		dict.insert(wordList[i]);
	}

	paths.push({ beginWord });
	int level = 1;
	int minLevel = INT_MAX;

	//"visited" records all the visited nodes on this level
	//these words will never be visited again after this level 
	//and should be removed from wordList. This is guaranteed
	// by the shortest path.
	unordered_set<string> visited;

	while (!paths.empty()) {
		vector<string> path = paths.front();
		paths.pop();
		if (path.size() > level) {
			//reach a new level
			for (string w : visited) dict.erase(w);
			visited.clear();
			if (path.size() > minLevel)
				break;
			else
				level = path.size();
		}
		string last = path.back();
		//find next words in wordList by changing
		//each element from 'a' to 'z'
		for (int i = 0; i < last.size(); ++i) {
			string news = last;
			for (char c = 'a'; c <= 'z'; ++c) {
				news[i] = c;
				if (dict.find(news) != dict.end()) {
					//next word is in wordList
					//append this word to path
					//path will be reused in the loop
					//so copy a new path
					vector<string> newpath = path;
					newpath.push_back(news);
					visited.insert(news);
					if (news == endWord) {
						minLevel = level;
						ans.push_back(newpath);
					}
					else
						paths.push(newpath);
				}
			}
		}
	}
	return ans;
}
*/