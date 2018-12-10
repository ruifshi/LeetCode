#include "stdafx.h"
#include "SentenceScreenFitting.h"

int Solution::wordsTyping(vector<string>& sentence, int rows, int cols) {
	string s;

	for (int i = 0; i < sentence.size(); i++) {
		s += sentence[i] + " ";
	}

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