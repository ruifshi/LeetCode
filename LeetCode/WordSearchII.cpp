#include "stdafx.h"
#include "WordSearchII.h"

vector<string> Solution::findWords(vector<vector<char>>& board, vector<string>& words) {
	if(board.size() == 0 || board[0].size() == 0) {
		return ans;
	}

	found.assign(words.size(), false);
	TrieNode *root = buildTrie(words);

	vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));

	for(int i = 0; i < board.size(); i++) {
		for(int j = 0; j < board[i].size(); j++) {
			helper(board, words, root, i, j, visited);
		}
	}

	return ans;
}

TrieNode* Solution::buildTrie(vector<string>& words) {
	TrieNode *root = new TrieNode();
	for(int i = 0; i < words.size(); i++) {
		TrieNode *p = root;
		for(int j = 0; j < words[i].size(); j++) {
			if(p->children[words[i][j]] == NULL) {
				p->children[words[i][j]] = new TrieNode();
			}
			p = p->children[words[i][j]];
		}
		p->index = i;
		p->end = true;
	}

	return root;
}

void Solution::helper(vector<vector<char>>& board, vector<string>& words, TrieNode *root, int row, int col, vector<vector<bool>> visited) {
	if(row == board.size() || col == board[0].size() || row < 0 || col < 0 || root == NULL || visited[row][col]) {
		return;
	}

	visited[row][col] = true;
	
	if(root->children[board[row][col]] != NULL) {
		helper(board, words, root->children[board[row][col]], row + 1, col, visited);
		helper(board, words, root->children[board[row][col]], row, col + 1, visited);
		helper(board, words, root->children[board[row][col]], row - 1, col, visited);
		helper(board, words, root->children[board[row][col]], row, col - 1, visited);
		if(root->children[board[row][col]]->end && found[root->children[board[row][col]]->index] == false) {
			ans.push_back(words[root->children[board[row][col]]->index]);
			found[root->children[board[row][col]]->index] = true;
		}
	}

	visited[row][col] = false;

	return;
}