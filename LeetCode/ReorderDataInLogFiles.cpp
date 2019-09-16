#include "stdafx.h"
#include "ReorderDataInLogFiles.h"

#include <algorithm>

/*
bool comp(string a, string b) {
	int i = a.find(' ');
	int j = b.find(' ');
	
	return a.substr(i + 1) < b.substr(j + 1);
}

vector<string> Solution::reorderLogFiles(vector<string>& logs) {
	vector<string> letter;

	for (int i = 0; i < logs.size(); i++) {
		int indx = logs[i].find(' ');
		if (!isdigit(logs[i][indx+1])) {
			letter.push_back(logs[i]);
			logs.erase(logs.begin() + i);
			i--;
		}
	}

	stable_sort(letter.begin(), letter.end(), comp);

	for (int i = 0; i < letter.size(); i++) {
		logs.insert(logs.begin() + i, letter[i]);
	}

	return logs;
}
*/

bool cmp(string s1, string s2) {
	int p1 = s1.find(' '), p2 = s2.find(' ');
	if (!isdigit(s1[p1 + 1]) && !isdigit(s2[p2 + 1])) {
		if (s1.substr(p1 + 1) == s2.substr(p2 + 1)) {
			return s1.substr(0, p1 + 1) < s2.substr(0, p2 + 1);
		}
		else {
			return s1.substr(p1 + 1) < s2.substr(p2 + 1);
		}
	}
	else {
		if (!isdigit(s1[p1 + 1])) return true;
		return false;
	}
	return false;
}

vector<string> Solution::reorderLogFiles(vector<string>& logs) {
	stable_sort(logs.begin(), logs.end(), cmp);
	return logs;
}