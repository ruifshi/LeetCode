#include "stdafx.h"
#include "FizzBuzz.h"

#include <map>

/*
Having a condition for every mapping is not feasible or may be we can say the code might get ugly and tough to maintain.

What if tomorrow we have to change a mapping or may be delete a mapping? Are we going to change the code every time we have a modification in the mappings?

We don't have to. We can put all these mappings in a Hash Table.
*/
vector<string> Solution::fizzBuzz(int n) {
	map<int, string> table;

	table[3] = "Fizz";
	table[5] = "Buzz";

	vector<string> ans;

	for (int i = 1; i <= n; i++) {
		string s = "";
		bool in_table = false;

		for (auto x : table) {
			if (i % x.first == 0) {
				s += x.second;
				in_table = true;
			}
		}

		if (!in_table) {
			s += to_string(i);
		}

		ans.push_back(s);
	}

	return ans;
}