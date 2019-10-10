#include <unordered_map>
#include <set>

using namespace std;

struct CacheNode {
	int key;
	int value;
	int freq;
	long tick;

	// Defines the order, smaller one will be evicted first
	bool operator <(const CacheNode& rhs) const {
		if (freq < rhs.freq) return true;
		if (freq == rhs.freq) return tick < rhs.tick;
		return false;
	}
};

class LFUCache {
private:
	long tick_;
	int capacity_;
	unordered_map<int, CacheNode> m_;
	set<CacheNode> cache_;

public:
	LFUCache(int capacity);

	int get(int key);

	void put(int key, int value);

	void touch(CacheNode& node);
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */