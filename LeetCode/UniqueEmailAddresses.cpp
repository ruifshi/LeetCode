#include "stdafx.h"
#include "UniqueEmailAddresses.h"

#include <set>
#include <algorithm>

// O(n)
int Solution::numUniqueEmails(vector<string>& emails) {
	set<string> unique;

	// for each email, isolate the local addr and the domain.
	// For local, remove all chars after + if it exists.
	// Also remove all instances of .
	for (int i = 0; i < emails.size(); i++) {
		int atIndex = emails[i].find('@');
		string local = emails[i].substr(0, atIndex);
		string domain = emails[i].substr(atIndex);

		if (emails[i].find('+') != string::npos) {
			local = emails[i].substr(0, emails[i].find("+"));
		}
		
		// remove removes the '.' and shifts the string to the left. Now,
		// we need to erase the left over chars. remove returns an interator
		// to the end of the string so we remove the rest
		local.erase(std::remove(local.begin(), local.end(), '.'), local.end());

		unique.insert(local + domain);
	}

	return unique.size();
}