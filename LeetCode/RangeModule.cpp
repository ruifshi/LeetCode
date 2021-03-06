#include "stdafx.h"
#include "RangeModule.h"

#include <algorithm>

// O(n)
void RangeModule::addRange(int left, int right) {
    int n = invals.size();
    vector<pair<int, int>> tmp;
    for (int i = 0; i <= n; i++) {
        if (i == n || invals[i].first > right) {
            tmp.push_back(pair<int,int>(left, right));
            while (i < n)
				tmp.push_back(invals[i++]);

        }
        else if (invals[i].second < left) 
            tmp.push_back(invals[i]);
        else {
            left = min(left, invals[i].first);
            right = max(right, invals[i].second);
        }
    }
    invals.swap(tmp);
}

// O(logn)
bool RangeModule::queryRange(int left, int right) {
    int n = invals.size(), l = 0, r = n-1;
    while (l <= r) {
        int m = l+(r-l)/2;
        if (invals[m].first >= right)
            r = m-1;
        else if (invals[m].second <= left)
            l = m+1;
        else 
            return invals[m].first <= left && invals[m].second >= right;
    }
    return false;
}

// O(n)
void RangeModule::removeRange(int left, int right) {
    int n = invals.size();
    vector<pair<int, int>> tmp;
    for (int i = 0; i < n; i++) {
        if (invals[i].second <= left || invals[i].first >= right)
            tmp.push_back(invals[i]);
        else {
            if (invals[i].first < left)
				tmp.push_back(pair<int,int>(invals[i].first, left));
            if (invals[i].second > right)
				tmp.push_back(pair<int,int>(right, invals[i].second));
        }
    }
    invals.swap(tmp);
}