#include "stdafx.h"
#include "ShortestPalindrome.h"

#include <vector>


// O(n)
string Solution::shortestPalindrome(string s) {
	// If you reverse the string and add it to the beginning,
	// it will always create a palindrome. However, you need
	// to remove the unneeded characters. If we use KMP to create
	// a table that shows which prefixes are equal to the suffixes,
	// we can remove the longest suffix from the reversed string 
	// before appending to the end.
    int n = s.size();
    string rev(s);
    reverse(rev.begin(), rev.end());
    string s_new = s + "#" + rev;
    int n_new = s_new.size();
    vector<int> f(n_new, 0);
    for (int i = 1; i < n_new; i++) {
        int t = f[i - 1];
        while (t > 0 && s_new[i] != s_new[t])
            t = f[t - 1];
        if (s_new[i] == s_new[t])
            ++t;
        f[i] = t;
    }
    return rev.substr(0, n - f[n_new - 1]) + s;
}

/* O(n^2)
// Find the palindrome if it exists in the current word by
// comparing the input string against it's reverse. You should 
// get a substring that is the same. You can then append the rest 
// of the string in the reverse string to the original to create a
// new palindrome.

// s = "abcbabcab" --> abcba bcab
// rev = "bacbabcba" --> bacb abcba
string shortestPalindrome(string s)
{
	int n = s.size();
	string rev(s);
	reverse(rev.begin(), rev.end());
	for (int i = 0; i < n; i++) {
		if (s.substr(0, n - i) == rev.substr(i))
			return rev.substr(0, i) + s;
	}
	return "";
}
*/