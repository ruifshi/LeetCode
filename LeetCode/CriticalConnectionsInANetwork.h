#include <vector>
#include <unordered_map>

using namespace std;

struct Vetex {
	int index;  // time_stamp 
	int lowlink; // The earliest point that can be reached by a non-father node
};

class Solution {
private:
	unordered_map< int, vector< int > > graph;
	int time_stamp = 1;
	vector<Vetex> check;
	vector<vector<int>> ans;

public:
	vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections);
	void crithelper(int v, int parent);
};