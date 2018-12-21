#include "stdafx.h"
#include "SerializeAndDeserializeBinaryTree.h"

// Encodes a tree to a single string.
// O(n), visits each node once
string Codec::serialize(TreeNode* root) {
	string s;
	serializeHelper(root, s);
	return s;
}

// visit the nodes preoder and use spaces to represent NULL
// use ',' to differentiate between different numbers
void Codec::serializeHelper(TreeNode* root, string &s) {
	if (root == NULL) {
		s += " ,";
		return;
	}

	s += to_string(root->val) +',';
	serializeHelper(root->left, s);
	serializeHelper(root->right, s);

	return;
}

// Decodes your encoded data to tree.
TreeNode* Codec::deserialize(string data) {
	return deserializeHelper(data);
}

// keep taking the first val to make a node and then
// delete it and the next val is a leaf
TreeNode* Codec::deserializeHelper(string &data) {
	if (data[0] == ' ') {
		data.erase(0, 2);
		return NULL;
	}

	// handle conversion from string to int
	// use ',' to find the different vals and use stoi
	// to convert to int.
	int index = data.find(',');
	int val = stoi(data.substr(0, index));
	data.erase(0, index+1);
	TreeNode* root = new TreeNode(val);
	root->left = deserializeHelper(data);
	root->right = deserializeHelper(data);

	return root;
}