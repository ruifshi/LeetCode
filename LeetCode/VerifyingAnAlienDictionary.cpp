#include "stdafx.h"
#include "VerifyingAnAlienDictionary.h"

#include <algorithm>

bool Solution::isAlienSorted(vector<string>& words, string order) {
	if (words.size() == 0 || order.size() == 0) {
		return true;
	}

	int alphabet[26];

	for (int i = 0; i < order.size(); i++) {
		alphabet[order[i] - 'a'] = i;
	}

	for (int i = 0; i < words.size() - 1; i++) {
		string a = words[i];
		string b = words[i + 1];

		bool skip = false;
		for (int j = 0; j < min(a.size(), b.size()); j++) {
			if (a[j] != b[j]) {
				if(alphabet[a[j] - 'a'] > alphabet[b[j] - 'a']) {
				  return false;
			  }
			  skip = true;
			  break;
		  }
		}

		// app vs apple
		if (!skip && a.size() > b.size()) {
			return false;
		}
	}

	return true;
}

/*
int alphabet[26];
for (size_t i = 0; i < order.size(); ++i) {
	alphabet[order[i] - 'a'] = i;
}
return is_sorted(words.begin(), words.end(), [&alphabet](
	const string &w1,
	const string &w2
	) {
	for (int i = 0; i < min(w1.size(), w2.size()); i++) {
		if (w1[i] != w2[i]) {
			return indices[w1[i] - 'a'] < indices[w2[i] - 'a'];
		}
	}
	return w1.size() < w2.size();
});
*/