#include "stdafx.h"
#include "MinWindow.h"

#include <map>

// O(n)
// Initialize a vector called remaining, which contains the needed
// matching numbers of each character in s.
// If there are still
// characters needed to be contained(increment i in this case),
// decrease the matching number of that character and check if it is
// still non - negative.If it is, then it is the character in t, so
// decrease the total required number required.
// If there is no more
// characters required(increment start in this case), record min
// and left if a smaller length is found.Recover the number of this
// character in the remaining and if it is a character in t
// increase required.
string minWindow(string s, string t) {
    if (s.size() == 0 || t.size() == 0) {
		return "";
	}

    map<char, int> remaining;
    int required = t.size();

    for (int i = 0; i < required; i++) { 
		remaining[t[i]]++;
	}

    // left is the start end of the min-length substring ever found
    int min = INT_MAX, start = 0, left = 0, end = 0;

    while(end <= s.size() && start < s.size()) {
        if(required) {
            if (end == s.size()) {
				break;
			}
            remaining[s[end]]--;
            if (remaining[s[end]] >= 0) {
				required--;
			}
            end++;
        } else {
            if (end - start < min) {
                min = end -start;
                left = start;
            }
            remaining[s[start]]++;
            if (remaining[s[start]] > 0) {
				required++;
			}
            start++;
        }
    }
    return min == INT_MAX? "" : s.substr(left, min);
}