#include "stdafx.h"
#include "ExclusiveTimeOfFunctions.h"

#include <stack>
#include <string>

vector<int> Solution::exclusiveTime(int n, vector<string>& logs) {
	int lastTime = 0; // Remember the time in previous log entry
	stack<int> callStack;
	vector<int> runTime(n, 0);
	size_t pos;
	for (int i = 0; i < logs.size(); i++) {
		// Parse the line
		string str = logs[i];
		pos = str.find(":");
		int funcId = stoi(str.substr(0, pos));
		str.erase(0, pos + 1);
		pos = str.find(":");
		string type = str.substr(0, pos);
		str.erase(0, pos + 1);
		int currTime = stoi(str);

		if (type == "start") {
			// If a new function is called top of stack will contain the execution
			// context of this function. Update the runTime using that and push 
			// current function of stack.
			if (callStack.size() > 0) runTime[callStack.top()] += currTime - lastTime;
			callStack.push(funcId);
			lastTime = currTime;
		}
		else {
			// If a function has ended the top of stack will tell us its id
			// Update the runTime using that and pop the function from stack.
			runTime[callStack.top()] += currTime + 1 - lastTime;
			callStack.pop();
			lastTime = currTime + 1;
		}
	}
	return runTime;
}