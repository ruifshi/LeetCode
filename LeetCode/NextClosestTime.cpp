#include "stdafx.h"
#include "NextClosestTime.h"

#include <unordered_set>
#include <string>

using namespace std;

// O(1), always 24*60 tries worst case
string Solution::nextClosestTime(string time) {
	// convert time in string to an integer
    int cur =  60 * stoi (time.substr(0, 2)) + stoi (time.substr(3,2)); 
	
	// collect current digits in integer form in a set
    unordered_set<int> allowed; 
    for (auto c : time) {
        if (c != ':')
            allowed.insert(c - '0');
	}
        
    while (true){
		// increment time by one and check to see if the new time's 
		// digits are in the set
        cur = (cur + 1) % (24 * 60); 
        int digits[] = {cur/60/10, cur/60%10, cur%60/10, cur%60%10}; 
        bool notAllowed = false;
        for (auto digit : digits) {
            if (allowed.find(digit) == allowed.end()){
                notAllowed = true;
                break;
            }
		}
        if (notAllowed) {
            continue;
		}
        char buffer[5];
        sprintf(buffer, "%02d:%02d", cur/60, cur%60); 
        string s (buffer);
        return s; 
    }
}