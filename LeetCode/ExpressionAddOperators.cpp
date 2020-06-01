#include "stdafx.h"
#include "ExpressionAddOperators.h"

#include <string>

void addOperatorsHelper(vector<string> &result, string path, string num, int target, int pos, long cur, long prev) {
	if (pos == num.size()) {
		if (cur == target)   result.push_back(path);
		return;
	}
	for (int i = pos; i < num.size(); i++) {
		/*** corner-case-added-code ***/
		if (num[pos] == '0' && i > pos) break;
		string _str = num.substr(pos, i - pos + 1);
		long _value = stol(_str);
		if (pos == 0) {
			addOperatorsHelper(result, path + _str, num, target, i + 1, _value, _value);
		}
		else {
			addOperatorsHelper(result, path + "+" + _str, num, target, i + 1, cur + _value, _value);
			addOperatorsHelper(result, path + "-" + _str, num, target, i + 1, cur - _value, -_value);
      /*
      Let say the expression string formed so far is 1 + 2 (eval is 3)
      in current step let say we cur is 3 (i.e. the remnant string expression till end)
      we can choose to add, subtract or multiply 3 to the evaluated value (eval)
      however, if we choose multiply 3 (i.e. 1 + 2 * 3), then the answer should be 7
      this is where multed (i.e. 2) shall help us, which is basically the last value that contributed to the current eval
      */
			addOperatorsHelper(result, path + "*" + _str, num, target, i + 1, cur - prev + prev * _value, prev*_value);
		}
	}
}

vector<string> Solution::addOperators(string num, int target) {
	vector<string> result;
	if (num.size() == 0)   return result;
	addOperatorsHelper(result, "", num, target, 0, 0, 0);
	return result;
}