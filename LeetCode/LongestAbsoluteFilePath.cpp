#include "stdafx.h"
#include "LongestAbsoluteFilePath.h"

#include <vector>

/*
depLen is used to record the length of absolute path at different depths on the current searching way. 
We update the value of depLen every time we explore a new node at level 'depth'.
When the current node is directory, count adds isDir(==1) to indicate the '/' after the directory name.
*/
int Solution::lengthLongestPath(string input) {
	if (input.empty()) return 0;

	vector<int> depLen;
	int result = 0, count = 0, depth = 0, isDir = 1;

	for (int i = 0; i < input.length() + 1; ++i) {
		switch (input[i]) {
			/* No need for extra code after whole loop */
			case '\0':
			case '\n':
				count = !depth ? count + isDir : depLen[depth - 1] + count + isDir;
				if (depLen.size() > depth) depLen[depth] = count;
				else depLen.push_back(count);

				if (!isDir) result = count > result ? count : result;

				depth = count = 0;
				isDir = 1;
				break;
			case '\t':
				++depth;
				break;
			case '.':
				isDir = 0;
			default:
				++count;
		}
	}
	return result;
}