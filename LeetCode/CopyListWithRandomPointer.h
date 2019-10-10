#include <unordered_map>

using namespace std;

// Definition for a Node.
class Node {
public:
	int val;
	Node* next;
	Node* random;

	Node() {}

	Node(int _val, Node* _next, Node* _random) {
		val = _val;
		next = _next;
		random = _random;
	}
};

class Solution {
private:
	unordered_map<Node*, Node*> hmap;
public:
	Node* copyRandomList(Node* head);
};