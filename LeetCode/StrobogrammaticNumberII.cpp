#include "stdafx.h"
#include "StrobogrammaticNumberII.h"

vector<string> Solution::findStrobogrammatic(int n) {
	return helper(n, n);
}

vector<string> Solution::helper(int n, int tot) {
    vector<string> res;
    if (n == 0) {
        res.push_back("");
        return res;
    }
        
    if (n == 1) {
        res.push_back("0");
        res.push_back("1");
        res.push_back("8");
        return res;
    }
        
    auto ret = helper(n - 2, tot);
    for (auto& s : ret) {
        if (n != tot) {
            res.push_back("0" + s + "0");
        }
        res.push_back("1" + s + "1");
        res.push_back("6" + s + "9");
        res.push_back("8" + s + "8");
        res.push_back("9" + s + "6");
    }
        
    return res;
}