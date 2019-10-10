#include "stdafx.h"
#include "DesignInMemoryFileSystem.h"

#include <algorithm>

vector<string> getStrs(string path) {
	vector<string> str;

	int j = 0;
	for (int i = 1; i < path.length(); i++) {
		j = path.find("/", i) == string::npos ? path.length() : path.find("/", i);
		str.push_back(path.substr(i, j - i));
		i = j;
	}

	return str;
}

// current node is the directory and it's children are subdirs
FileSystem::FileSystem() {
	root = new TrieNode();
}

vector<string> FileSystem::ls(string path) {
	TrieNode *p = root;
	vector<string> strs = getStrs(path);
	vector<string> ans;

	// reach end of the passed path
	for (auto s : strs) {
		p = p->node[s];
	}

	// if it's a file, then just return the file dir name
	if (p->isFile) {
		return { strs.back() };
	}

	// return all the subdirs in this directory
	for (auto n : p->node) {
		ans.push_back(n.first);
	}

	sort(ans.begin(), ans.end());

	return ans;
}

void FileSystem::mkdir(string path) {
	TrieNode *p = root;
	vector<string> strs = getStrs(path);

	// create new node in Trie if it doesn't exist
	for (auto s : strs) {
		if (!p->node[s]) {
			p->node[s] = new TrieNode();
		}
		p = p->node[s];
	}

	return;
}

void FileSystem::addContentToFile(string filePath, string content) {
	TrieNode *p = root;
	vector<string> strs = getStrs(filePath);

	// update isFile and content for the file to end of Trie
	for (auto s : strs) {
		if (!p->node[s]) {
			p->node[s] = new TrieNode();
		}
		p = p->node[s];
	}

	p->isFile = true;
	p->content += content;

	return;
}


string FileSystem::readContentFromFile(string filePath) {
	TrieNode *p = root;
	vector<string> strs = getStrs(filePath);

	for (auto s : strs) {
		p = p->node[s];
	}

	return p->content;
}

/*
class FileSystem {
public:

	unordered_map<string, set<string>> dTable;  // dir name to contents
	unordered_map<string, string> fTable; //file name to contents


public:
	FileSystem() {
		dTable["/"];
	}

	vector<string> ls(string path) {
		vector<string> res;
		if (fTable.find(path) != fTable.end())
		{
			int i = path.length() - 1;

			while (i >= 0 && path[i] != '/') --i;

			res.push_back(path.substr(i + 1));
			return res;
		}

		if (dTable.find(path) != dTable.end())
		{
			for (auto s : dTable[path])
				res.push_back(s);
		}

		return res;
	}

	void mkdir(string path) {
		string prev = "/";
		int prevPos = 1;
		for (int i = 1; i <= path.size(); ++i)
		{
			if (path[i] == '/' || path[i] == 0)
			{
				dTable[prev].insert(path.substr(prevPos, i - prevPos));
				prevPos = i+1;
				prev = path.substr(0, i);
			}
		}
	}

	void addContentToFile(string filePath, string content) {

		int i = filePath.length() - 1;

		while (i >= 0 && filePath[i] != '/') --i;

		string path = filePath.substr(0, i);
		string file = filePath.substr(i + 1);

		if (path.empty()) path = "/";

		if (dTable.find(path) == dTable.end())
			mkdir(path);

		dTable[path].insert(file);

		fTable[filePath].append(content);

	}

	string readContentFromFile(string filePath) {
		if (fTable.find(filePath) != fTable.end())
			return fTable[filePath];
		return "";
	}
};
*/