#include "stdafx.h"
#include "ValidParentheses.h"

#include <stack>

// O(n)
bool Solution::isValid(string s) {
    stack<char> stack;

    if(s.empty()){
        return true;
    }
    if(s.length() == 1){
        return false;
    }
    
	// use a stack to match. If it's an open, pop it on the stack.
	// If it's a close, then the last element on the stack has to be
	// a matching open.
    for(int i =0 ; i < s.length(); i++){
        char c = s[i];
        if(c == '}'|| c == ')' || c == ']'){
            if(stack.size() == 0 ) return false;
            if(c == '}' && stack.top() != '{') return false;
            if(c == ')' && stack.top() != '(') return false;
            if(c == ']' && stack.top() != '[') return false;
            stack.pop();
            
         } else {
            stack.push(c);
        }
    }

    if(stack.size() == 0) return true;
    return false;
}