#include "stdafx.h"
#include "AlienDictionary.h"

#include <unordered_map>
#include <unordered_set>
#include <queue>

//explanation of problem https://youtu.be/hCrbYOlQFrY
//topological sort https://www.youtube.com/watch?v=ddTC4Zovtbc
//topological sort orders nodes uv where u is always before v
//this only works on DAG (acyclical graphs)
//goal is to have nodes with no dependencies (no indegrees) first
string Solution::alienOrder(vector<string>& words) {
	//construct graph
	unordered_map<char, unordered_set<char> > graph;
	int n = words.size();
	for (int i = 0; i < words.size(); i++) {
		for (int j = 0; j < words[i].size(); j++) {
			graph[words[i][j]] = unordered_set<char>();	//init all chars to an empty set
		}
	}

	//check the words against next word to find correct
	//order
	for (int i = 0; i < n - 1; i++) {
		int n1 = words[i].size();
		int n2 = words[i + 1].size();
		for (int j = 0; j < min(n1, n2); j++) {
			if (words[i][j] != words[i + 1][j]) {
				graph[words[i][j]].insert(words[i + 1][j]);
				break;
			}
			else {
				continue;
			}
		}
	}
	//get the indegree, i.e. the number of edges pointing towards the node
	unordered_map<char, int> inDegree;
	for (auto p : graph) {
		if (!inDegree.count(p.first)) inDegree[p.first] = 0;
		for (auto c : p.second) {
			inDegree[c]++;
		}
	}

	//bfs
	string res;
	queue<char> q;
	// put nodes with no incoming edges to queue first
	for (auto p : inDegree) {
		if (p.second == 0) {
			q.emplace(p.first);
		}
	}

	//the goal is to visit all the nodes and add the chars
	//to the answer string in the order of least indegrees to most
	while (!q.empty()) {
		char cur = q.front();
		q.pop();
		res += cur;
		for (auto c : graph[cur]) {
			inDegree[c]--;
			if (inDegree[c] == 0) {
				q.emplace(c);
			}
		}
	}
	//if cycle exists
	//the graph will be reduced to a cycle that every node has at least 1 edge pointing to it.
	//result will not have those nodes
	return res.size() == graph.size() ? res : "";
}

/* DFS
class Solution {
private:
	unordered_map<char, unordered_set<char> > graph;
	unordered_set<char> visited; // whether a char is visited
	unordered_set<char> done; // track whether a char is already in result
	string res;
	bool cycle = false;
public:
	void dfs(char c){
		if(cycle) return;
		visited.insert(c); // mark current node as visited
		for(auto child : graph[c]){
			//if a child is visited but not in result , then there must have a loop
			if(visited.count(child) && !done.count(child)){
				cycle = true;
			}
			if(!visited.count(child)){
				dfs(child);
			}
		}
		done.insert(c);
		res+=c;

	}
	string alienOrder(vector<string>& words) {
		//construct graph
		int n = words.size();
		for(int i = 0; i < words.size(); i++){
			for(int j = 0; j<words[i].size(); j++){
				graph[words[i][j]] = unordered_set<char>();
			}
		}
		for(int i = 0; i < n - 1; i++){
			int n1 = words[i].size();
			int n2 = words[i+1].size();
			for(int j = 0; j < min(n1, n2); j++){
				if(words[i][j] != words[i+1][j]){
					graph[words[i][j]].insert(words[i+1][j]);
					break;
				}
				else{
					continue;
				}
			}
		}
		//start dfs by checking every node.
		//if already in res, no need to dfs.
		for(auto p : graph){
			if(!done.count(p.first)) dfs(p.first);
		}

		//reverse the result to get a proper order.
		reverse(res.begin(), res.end());
		return cycle ? "" : res;


	}
};
*/