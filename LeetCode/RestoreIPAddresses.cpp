#include "stdafx.h"
#include "RestoreIPAddresses.h"

#include <string>

vector<string> Solution::restoreIpAddresses(string s) {
  vector<string> ret;
  string ans;

  for (int a = 1; a <= 3; a++)
    for (int b = 1; b <= 3; b++)
      for (int c = 1; c <= 3; c++)
        for (int d = 1; d <= 3; d++)
          if (a + b + c + d == s.length()) {
            int A = stoi(s.substr(0, a));
            int B = stoi(s.substr(a, b));
            int C = stoi(s.substr(a + b, c));
            int D = stoi(s.substr(a + b + c, d));
            if (A <= 255 && B <= 255 && C <= 255 && D <= 255)
              if ((ans = to_string(A) + "." + to_string(B) + "." + to_string(C) + "." + to_string(D)).length() == s.length() + 3)
                ret.push_back(ans);
          }

  return ret;
}

/*
vector<string> restoreIpAddresses(string s) {
  vector<string> result;
  string ip;
  dfs(s, 0, 0, ip, result); //paras:string s,start index of s,step(from0-3),intermediate ip,final result
  return result;
}
void dfs(string s, int start, int step, string ip, vector<string>& result) {
  if (start == s.size() && step == 4) {
    ip.erase(ip.end() - 1); //remove the last '.' from the last decimal number
    result.push_back(ip);
    return;
  }
  
  //An IP address contains four 8-bit unsigned integers, which means they range from 0 to 255, 
  //which means 1 to 3 digits, but 4 digits if we include the dot. The first if statement checks 
  //whether it exceeds the amount of digits possible left for an IP address, 
  //and the second if statement checks whether we have enough digits left given the current progress.

  if (s.size() - start > (4 - step) * 3) return;
  if (s.size() - start < (4 - step)) return;
  int num = 0;
  for (int i = start;i < start + 3;i++) {
    num = num * 10 + (s[i] - '0');
    if (num <= 255) {
      ip += s[i];
      dfs(s, i + 1, step + 1, ip + '.', result);
    }
    if (num == 0) break;
  }
}
*/