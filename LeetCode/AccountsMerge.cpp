#include "stdafx.h"
#include "AccountsMerge.h"

#include <unordered_map>
#include <queue>
#include <set>

vector<vector<string>> Solution::accountsMerge(vector<vector<string>>& accounts) {
	vector<vector<string>> res;
	int n = accounts.size();
	unordered_map<string, vector<int>> address2name;
	vector<int> visited(n, 0);

	// mapping of addresses to name index
	for (int i = 0; i < n; ++i) {
		for (int j = 1; j < accounts[i].size(); ++j) {
			address2name[accounts[i][j]].push_back(i);
		}
	}

	for (int i = 0; i < n; ++i) {
		if (visited[i] != 0) continue;
		queue<int> q{ {i} };
		set<string> s;
		while (!q.empty()) {
			int name_indx = q.front(); q.pop();
			visited[name_indx] = 1;
			vector<string> mails(accounts[name_indx].begin() + 1, accounts[name_indx].end());

			// link mail addresses to same name from the map 
			for (string mail : mails) {
				s.insert(mail);
				for (int name : address2name[mail]) {
					if (visited[name] != 0) continue;
					q.push(name);	// if these emails are linked to another name index, examine that next
					visited[name] = 1;
				}
			}
		}
		vector<string> out(s.begin(), s.end());
		out.insert(out.begin(), accounts[i][0]);
		res.push_back(out);
	}
	return res;
}