#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> findStrobogrammatic(int n);
	vector<string> helper(int n, int tot);
};