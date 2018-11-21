#include "stdafx.h"
#include "AddBoldTagInString.h"

string Solution::addBoldTag(string s, vector<string>& dict) {
    vector<bool> bold (s.size(), false);
    for (auto & d : dict) {
        int i = s.find(d);
        while (i < s.size() && i != string::npos) {
            for (int j = i; j < i + d.size(); j++) {
				bold[j] = true;
			}
            i = s.find(d, i + 1);
        }
    }
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