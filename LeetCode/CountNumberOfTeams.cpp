#include "stdafx.h"
#include "CountNumberOfTeams.h"

int Solution::numTeams(vector<int>& rating) {
  int n = rating.size();
  int result = 0;
  for (int i = 1; i < n - 1; i++) {
    int leftSmall = 0, leftLarge = 0;
    int rightSmall = 0, rightLarge = 0;
    //left part
    for (int j = 0; j < i; j++) {
      if (rating[j] < rating[i]) {
        leftSmall++;
      }
      if (rating[j] > rating[i]) {
        leftLarge++;
      }
    }
    //right part
    for (int j = i + 1; j < n; j++) {
      if (rating[j] < rating[i]) {
        rightSmall++;
      }
      if (rating[j] > rating[i]) {
        rightLarge++;
      }
    }
    result += leftSmall * rightLarge + leftLarge * rightSmall;  //number of smaller and larger on left and right that can form
  }
  return result;
}

/*
class Solution {
public:
    int numTeams(vector<int>& r) {
        int n = r.size();
        int result = 0;
        for(int i = 0 ; i < n-2 ; i++){
            for(int j = i+1 ; j < n-1 ; j++){
                for(int k = j+1 ; k < n ; k++){
                    if(((r[i] < r[j]) && (r[j] < r[k])) || ((r[i] > r[j]) && (r[j] > r[k]))){
                        result++;
                    }
                }
            }
        }
        return result;
    }
};
*/