#include "stdafx.h"
#include "LetterCombinationsOfAPhoneNumber.h"

vector<vector<char>> dial =
{ {' '},				//0
  {},					//1
  {'a', 'b', 'c'},		//2
  {'d', 'e', 'f'},		//3
  {'g', 'h', 'i'},		//4
  {'j', 'k', 'l'},		//5
  {'m', 'n', 'o'},		//6
  {'p', 'q', 'r', 's'},	//7
  {'t', 'u', 'v'},		//8
  {'w', 'x', 'y', 'z'}};//9

// O(4^n), n = number of chars in digits
vector<string> Solution::letterCombinations(string digits) {
	vector<string> ans;
	if(digits.size() == 0) {
		return ans;
	}

	string curr;
	letterCombinationsHelper(digits, curr, 0, ans);
	return ans;
}

// backtrack and try each dial combination
void Solution::letterCombinationsHelper(string &digits, string &curr, int curr_digit, vector<string> &ans) {
	if (curr_digit == digits.size()) {
		ans.push_back(curr);
		return;
	}

	// for each char in digits, try a letter from the dial and move onto the next digit
	// when we return, unchoose the char and move onto the next value on the dial
	for (char c : dial[digits[curr_digit] - '0']) {
		curr.push_back(c);
		letterCombinationsHelper(digits, curr, curr_digit + 1, ans);
		curr.pop_back();
	}

	return;
}