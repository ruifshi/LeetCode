#include "stdafx.h"
#include "EvaluateReversePolishNotation.h"

#include <stack>

// O(number of tokens)
int Solution::evalRPN(vector<string>& tokens) {
	stack<int> stk;

	if(tokens.size() == 0) {
		return 0;
	}

	for(int i = 0; i < tokens.size(); i++) {
		if(tokens[i] != "+" && tokens[i] != "-" && tokens[i] != "*" && tokens[i] != "/") {
			stk.push(stoi(tokens[i]));
		}
		else {
			char opter = tokens[i][0];
			int b = stk.top();
			stk.pop();
			int a = stk.top();
			stk.pop();
			switch(opter) {
			case '+':
				stk.push(a + b);
				break;

			case '-':
				stk.push(a - b);
				break;

			case '*':
				stk.push(a * b);
				break;

			case '/':
				stk.push(a / b);
				break;

			}
		}
	}

	return stk.top();
}