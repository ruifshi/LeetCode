#include "stdafx.h"
#include "AddBoldTagInString.h"

// O(n)
string Solution::addBoldTag(string s, vector<string>& dict) {
    vector<bool> bold (s.size(), false);

	// for each word in the dict, iterate through each char in the input string
	// and mark it as to be bold if it matches
    for (auto & d : dict) {
        int i = s.find(d);
        while (i < s.size() && i != string::npos) {
            for (int j = i; j < i + d.size(); j++) {
				bold[j] = true;
			}
            i = s.find(d, i + 1);
        }
    }

	// iterate through the bool vector and use flags to determine where to place
	// the bold marks
    string res;
    bool pre = false;
    for (int i = 0; i < bold.size(); i++) {
        if (!bold[i] && pre) {
            res += "</b>";
            pre = false;
        }
        else if (bold[i] && !pre){
            res += "<b>";
            pre = true;
        }
        res += s[i];
    }
    if (pre) {
		res += "</b>";
	}
        
    return res;
}