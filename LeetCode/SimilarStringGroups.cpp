#include "stdafx.h"
#include "SimilarStringGroups.h"

#include <unordered_set>
#include <queue>

/*
This question asks for number of disjoint groups. While a group contains strings swappable from at least one other string in it, it looks like this is a graph problem: strings are the nodes in the graph, and two strings (nodes) have a path between them if they are similar.

How do we know if two strings are similar?

This can be determined by calculating hamming distance between them. Since all strings are anagrams, if two strings have hamming distance of two, then they can be converted into each other by swapping the only two different characters.

In other wors, two strings are similar if and only if they have hamming distance two.

We can compute the hamming distance between every two strings in O(n ^ 2 * l) time. And if two strings have hamming distance 2, they are definitely in the same group.

How do we represent the graph?

Now we know all nodes in the graph (which are all strings in the input), we also know the edges between them. We've got everything we need!

Here i choose to use the adjacency list representation of the graph. If two strings have hamming distance 2, there's an edge between them.

How to find all disjoint groups?

Here comes the easiest part! We can find a group by visiting all nodes in it.

If two nodes A and B are in different groups, there's no way we can go from A to B. However, if A and C are in the same group, there must exist a way we can go from A to C.

Similarly, we can go from the first string, visit all strings that are in the same group as the first string(we call this group group_1). Then find another string which we haven't visted yet and visit all strings in that group (we call this group group_2). We can do this until all strings have been visited and we find all the groups.

Actually this is the problem of finding all connected components of a graph . Now we have our graph, we can use BFS to do this!
*/
int hamdist(const string &a, const string &b)
{  // compute hamming distance between two strings a and b
	int ans = 0;
	for (int i = 0, end = a.size(); i != end; ++i) {
		if (a[i] != b[i]) ++ans;
	}
	return (ans == 2);  // return true if they are similar, otherwise false
}

int Solution::numSimilarGroups(vector<string>& A) {
	// preparation to reduce copies in A
	unordered_set<string> tmp(A.cbegin(), A.cend());
	vector<string> A_copy(tmp.cbegin(), tmp.cend());  // now that all strings in A_copy are distinct


	int l = A_copy.size();
	vector<vector<int>> graph(l, vector<int>());  // this is the graph in adjacency list representation
	for (int i = 0; i < l; ++i) {
		for (int j = i + 1; j < l; ++j) {
			if (hamdist(A_copy[i], A_copy[j])) {  // if they are similar
				graph[i].push_back(j);
				graph[j].push_back(i);
			}
		}
	}

	int ans = 0;
	unordered_set<int> seen;
	for (int i = 0; i < l; ++i) {
		if (seen.find(i) == seen.end()) {  // if we haven't visited it yet
			++ans;  // we find a new group
			queue<int> q;
			q.push(i);
			while (q.size()) {
				int cur = q.front();
				q.pop();
				for (auto &i : graph[cur]) {
					if (seen.find(i) == seen.end()) {
						q.push(i);
						seen.insert(i);
					}
				}
			}
		}
	}

	return ans;
}