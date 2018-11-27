#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

struct Node {
	Node* parent;
	double value;
	Node()  {parent = this;}
};

class Solution {
public:
	double Helper(string A, string B, unordered_map<string, unordered_map<string, double>> graph, unordered_set<string> visited);

    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries);

    void unionNodes(Node* node1, Node* node2, double num, unordered_map<string, Node*>& map);
	Node* findParent(Node* node);
};