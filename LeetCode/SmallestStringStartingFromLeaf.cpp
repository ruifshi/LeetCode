#include "stdafx.h"
#include "SmallestStringStartingFromLeaf.h"

using namespace std;

/* Returns the lexicographically smallest string starting from leaf and ending at root*/
string Solution::smallestFromLeaf(TreeNode* root)
{
	// Create the string to store the answer
	string currentAnswer = "";

	// If the root is null, no string can be formed
	if (!root) return currentAnswer;

	// Store the letter of the root
	char rootLetter = root->val + 'a';

	// Recursively calculate the smallest string ending at the left and the right subtree
	string leftAnswer = smallestFromLeaf(root->left);
	string rightAnswer = smallestFromLeaf(root->right);

	// If the leftSubtree does not exist, append root to smallest string of right subtree
	if (leftAnswer.size() == 0) return (rightAnswer + rootLetter);

	// If the rightSubtree does not exist, append root to smallest string of left subtree
	else if (rightAnswer.size() == 0) return (leftAnswer + rootLetter);

	// Now assume that both the subtrees exist
	else
	{
		// If the left is lexicographically smaller, append root to make the new best string
		if (leftAnswer < rightAnswer)
			currentAnswer = leftAnswer + rootLetter;
		else
			currentAnswer = rightAnswer + rootLetter;
	}

	// Return the best of the 2 possible concatenations
	return currentAnswer;
}