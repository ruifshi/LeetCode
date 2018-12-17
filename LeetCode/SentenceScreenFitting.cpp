#include "stdafx.h"
#include "SentenceScreenFitting.h"

// O(n)
int Solution::wordsTyping(vector<string>& sentence, int rows, int cols) {
	string s;

	// create a string with spaces from sentence
	for (int i = 0; i < sentence.size(); i++) {
		s += sentence[i] + " ";
	}

	// use a greed algorithm. Just add col to the count and find what the
	// last char of the string is. If it's a space, then that means we filled
	// a row and increment by 1 to go to next row. If it's not a space, then
	// that means it's in the middle of a word and we need to decrement,
	// until it's a space. The final answer is just the count/size of string.
	int size = s.size();
	int count = 0;
	for (int i = 0; i < rows; i++) {
		count += cols;
		if (s[count % size] == ' ') {
			count++;
		}
		else {
			while (count > 0 && s[(count-1) % size] != ' ') {
				count--;
			}
		}
	}

	return count / size;
}