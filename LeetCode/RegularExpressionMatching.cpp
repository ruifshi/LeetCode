#include "stdafx.h"
#include "RegularExpressionMatching.h"

#include <vector>

//https://www.youtube.com/watch?v=l3hda49XcDE
//O(s.size() * p.size())
bool Solution::isMatch(string s, string p) {
	/*
	   | 0 | 1 | 2 | 3 | 4 | 5 | 6
	   | ""| x | a | * | b | . | c
	-------------------------------
	0 ""| T |   |   |   |   |   |
	-------------------------------
	1 x |   |   |   |   |   |   |
	-------------------------------
	2 a |   |   |   |   |   |   |
	-------------------------------
	3 a |   |   |   |   |   |   |
	-------------------------------
	4 b |   |   |   |   |   |   |
	-------------------------------
	5 y |   |   |   |   |   |   |
	*/
	vector<vector<bool>> table(s.size()+1, vector<bool>(p.size()+1, false)); // +1 for NULL string

	table[0][0] = true; // NULL vs NULL is always true

	// compares the NULL string against the pattern
	// deals with * vs the NULL
	for (int i = 1; i < table[0].size(); i++) {
		if (p[i - 1] == '*') {
			table[0][i] = table[0][i - 2];
		}
	}

	//table[i][j] i = text, j = pattern
	// relation:
	// 1) if s[i] == p[j] || p[j] == '.'
	//		T[i-1][j-1] 
	// 2) if p[j] == '*'
	//		T[i][j-2] -> no occurences of the char
	//		T[i-1][j] if s[i] == p[i-1] || p[j-1] == '.'
	// 3) false
	for (int i = 1; i < table.size(); i++) {
		for (int j = 1; j < table[0].size(); j++) {
			if (p[j - 1] == '.' || p[j - 1] == s[i - 1]) {
				table[i][j] = table[i - 1][j - 1];
			}
			else if (p[j - 1] == '*') {
				table[i][j] = table[i][j - 2];
				if (p[j - 2] == '.' || p[j - 2] == s[i - 1]) {
					table[i][j] = table[i][j] | table[i - 1][j];
				}
			}
			else {
				table[i][j] = false;
			}
		}
	}

	return table[s.size()][p.size()];
}