#include <map>

using namespace std;

struct node {
	int val;
	int key;
	node *prev;
	node *next;
	node(int x, int k) : val(x), key(k), prev(NULL), next(NULL) {};
};

class LRUCache {
public:
	LRUCache(int capacity);

	int get(int key);

	void put(int key, int value);

	int cacheSize;
	map<int, node*> table;
	node* head;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */