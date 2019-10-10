#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

struct TrieNode {
	unordered_map<string, TrieNode*> node;
	bool isFile;
	string content;
	TrieNode() : isFile(false) {}
};

class FileSystem {
private:
	TrieNode *root;

public:
	FileSystem();

	vector<string> ls(string path);

	void mkdir(string path);

	void addContentToFile(string filePath, string content);

	string readContentFromFile(string filePath);
};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem* obj = new FileSystem();
 * vector<string> param_1 = obj->ls(path);
 * obj->mkdir(path);
 * obj->addContentToFile(filePath,content);
 * string param_4 = obj->readContentFromFile(filePath);
 */