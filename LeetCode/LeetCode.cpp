// Test.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
//#include "kEmptySlot.h"
//#include "ValidNumber.h"
//#include "ValidParentheses.h"
//#include "ImageSmoother.h"
//#include "IntersectionOfTwoArrays.h"
//#include "MaxConsecutiveOnesFlip.h"
//#include "ShortestPalindrome.h"
//#include "FirstMissingPositive.h"
//#include "FirstUniqueCharacterInAString.h"
//#include "MoveZeroes.h"
//#include "RemoveDuplicatesFromSortedArray.h"
//#include "MergeKSortedLists.h"
//#include "InsertIntoACyclicSortedList.h"
//#include "EvaluateDivision.h"
//#include "RedundantConnectionII.h"
//#include "CourseSchedule.h"
//#include "ValidateBinarySearchTree.h"
//#include "WorldSquares.h"
//#include "StrobogrammaticNumberII.h"
//#include "WordSearchII.h"
//#include "AndroidUnlockPatterns.h"
//#include "MinWindow.h"
//#include "ShortestDistanceFromAllBuildings.h"
//#include "FindKthSmallestPairDistance.h"
//#include "FindKPairsWithSmallestSums.h"
//#include "RangeModule.h"
//#include "RangeModule.h"
//#include "LongestPalindromicSubstring.h"
//#include "DiagonalTraverse.h"
//#include "NextGreaterElementI.h"
//#include "PacificAtlanticWaterFlow.h"
//#include "DecodeWays.h"
#include "WordBreak.h"
//#include "SentenceScreenFitting.h"
//#include "MaximumVacationDays.h"
//#include "MinimumPathSum.h"
//#include "MovingAverageFromDataStream.h"
//#include "BinarySearchTreeIterator.h"

int _tmain(int argc, _TCHAR* argv[])
{
	Solution output;

	/*
	bool out = output.isNumber(" 99e2.5 ");
	out = output.isNumber("53.5e93");
	out = output.isNumber(" --6");
	*/

	//bool out = output.isValid("({[))]}");

	/*
	int array[3] = {1,1,1};
	int array1[3] = {1,0,1};
	int array2[3] = {1,1,1};
	vector<int> row(array, array+3);
	vector<int> row1(array1, array1+3);
	vector<int> row2(array2, array2+3);
	vector<vector<int>> input;

	input.push_back(row);
	input.push_back(row1);
	input.push_back(row2);

	vector<vector<int>> out = output.imageSmoother(input);
	*/

	/*
	int array[1] = {1};
	int array2[1] = {1};

	vector<int> vec(array, array + 1);
	vector<int> vec1(array2, array2 + 1);

	vector<int> out = output.intersection(vec, vec1);
	*/

	/*
	int array[5] = {1,0,1,1,0};
	vector<int> input(array, array+5);

	int out = output.findMaxConsecutiveOnesFlip(input);
	*/

	//string out = output.shortestPalindrome("ananab");

	/*
	int array[5] = {7,8,9,11,12};
	vector<int> input(array, array+5);

	int out = output.firstMissingPositive(input);
	*/

	//int out = output.firstUniqChar("leetcode");

	/*
	int array[6] = {1,1,1,0,0,12};
	vector<int> input(array, array+6);
	output.moveZeroes(input);
	*/

	/*
	int array[10] = {0,0,1,1,1,2,2,3,3,4};
	vector<int> input(array, array + 10);
	int out = output.removeDuplicates(input);
	*/

	/*
	ListNode a(1);
	ListNode b(4);
	ListNode c(5);
	a.next = &b;
	b.next = &c;
	c.next = NULL;

	ListNode d(1);
	ListNode e(3);
	ListNode f(4);
	d.next = &e;
	e.next = &f;
	f.next = NULL;

	vector<ListNode*> lists;

	lists.push_back(&a);
	lists.push_back(&d);
	
	output.mergeKLists(lists);
	*/

	/*
	Node a(1, NULL);
	Node b(4, NULL);
	Node c(3, NULL);
	a.next = &b;
	b.next = &c;
	c.next = &a;

	Node* d = output.insert(&a, 2);
	*/

	/*
	vector<pair<string, string>> equations;
	equations.push_back(make_pair("a", "b"));
	equations.push_back(make_pair("b", "c"));

	vector<double> values;
	values.push_back(2.0);
	values.push_back(3.0);

	vector<pair<string, string>> queries;
	queries.push_back(make_pair("a", "c"));
	queries.push_back(make_pair("b", "a"));
	queries.push_back(make_pair("a", "e"));
	queries.push_back(make_pair("a", "a"));
	queries.push_back(make_pair("x", "x"));

	vector<double> out = output.calcEquation(equations, values, queries);
	*/

	/*
	vector<int> a;
	a.push_back(2);
	a.push_back(1);

	vector<int> b;
	b.push_back(3);
	b.push_back(1);

	vector<int> c;
	c.push_back(4);
	c.push_back(2);

	vector<int> d;
	d.push_back(1);
	d.push_back(4);

	//vector<int> e;
	//e.push_back(4);
	//e.push_back(3);

	vector<vector<int>> edges;
	edges.push_back(a);
	edges.push_back(b);
	edges.push_back(c);
	edges.push_back(d);
	//edges.push_back(e);

	vector<int> out = output.findRedundantDirectedConnection(edges);
	*/

	/*
	vector<pair<int, int>> prerequisites;
	prerequisites.push_back(pair<int,int>(1,0));
	prerequisites.push_back(pair<int,int>(2,0));
	prerequisites.push_back(pair<int,int>(0,2));

	bool out = output.canFinish(3, prerequisites);
	*/
	
	/*
	TreeNode root(INT_MIN);
	TreeNode a(INT_MIN);
	root.left = &a;
	bool out = output.isValidBST(&root);
	*/

	/*
	vector<string> words;
	words.push_back("abat");
	words.push_back("baba");
	words.push_back("atan");
	words.push_back("atal");

	vector<vector<string>> out = output.wordSquares(words);
	*/

	//vector<string> out = output.findStrobogrammatic(4);

	/*
	vector<string> words;
	words.push_back("ab");
	words.push_back("abb");
	//words.push_back("eat");
	//words.push_back("rain");

	vector<vector<char>> board;
	char array[2] = {'a', 'b'};
	vector<char> vec(array, array + 2);
	char array1[2] = {'c', 'd'};
	vector<char> vec1(array1, array1 + 2);
	//char array2[4] = {'i','h','k','r'};
	//vector<char> vec2(array2, array2 + 4);
	//char array3[4] = {'i','f','l','v'};
	//vector<char> vec3(array3, array3 + 4);
	board.push_back(vec);
	board.push_back(vec1);
	//board.push_back(vec2);
	//board.push_back(vec3);

	vector<string> out = output.findWords(board, words);
	*/

	//int out = output.numberOfPatterns(1,9);

	//string s = minWindow("ADOBECODEBANC", "ABC");

	/*
	int array[5] = {1,0,2,0,1};
	vector<int> vec(array, array+5);
	int array1[5] = {0,0,0,0,0};
	vector<int> vec1(array1, array1+5);
	int array2[5] = {0,0,1,0,0};
	vector<int> vec2(array2, array2+5);

	vector<vector<int>> grid;
	grid.push_back(vec);
	grid.push_back(vec1);
	grid.push_back(vec2);

	int out = output.shortestDistance(grid);
	*/

	/*
	int array[3] = {1,3,1};
	vector<int> vec(array, array+3);

	int out = output.smallestDistancePair(vec, 1);
	*/

	/*
	int array[11] = {10,-4,0,0,6,6,6,7,10,22,100};
	vector<int> vec1(array, array+11);
	int array1[6] = {3,5,6,7,8,100};
	vector<int> vec2(array1, array1+6);

	vector<pair<int, int>> out = output.kSmallestPairs(vec1, vec2, 20);
	*/

	/*
	RangeModule input;

	input.addRange(10, 20);
	input.addRange(30, 35);
	input.addRange(34, 40);
	input.removeRange(14, 16);
	bool out = input.queryRange(10, 14);
	out = input.queryRange(13, 15);
	out = input.queryRange(16, 17);
	*/

	//string s = output.longestPalindrome("ccc");

	/*
	int array[3] = {1,2,3};
	int array1[3] = {4,5,6};
	int array2[3] = {7,8,9};
	vector<int> vec(array, array+3);
	vector<int> vec1(array1, array1+3);
	vector<int> vec2(array2, array2+3);

	vector<vector<int>> input;
	input.push_back(vec);
	input.push_back(vec1);
	input.push_back(vec2);

	vector<int> out = output.findDiagonalOrder(input);
	*/

	/*
	int array[3] = {4,1,2};
	vector<int> input(array, array+3);
	int array1[4] = {1,3,4,2};
	vector<int> input1(array1, array1+3);

	vector<int> out = output.nextGreaterElement(input, input1);
	*/

	/*
	int array[5] = {1,2,2,3,5};
	int array1[5] = {3,2,3,4,4};
	int array2[5] = {2,4,5,3,1};
	int array3[5] = {6,7,1,4,5};
	int array4[5] = {5,1,1,2,4};

	vector<int> vec(array, array+5);
	vector<int> vec1(array1, array1+5);
	vector<int> vec2(array2, array2+5);
	vector<int> vec3(array3, array3+5);
	vector<int> vec4(array4, array4+5);

	vector<vector<int>> matrix;

	matrix.push_back(vec);
	matrix.push_back(vec1);
	matrix.push_back(vec2);
	matrix.push_back(vec3);
	matrix.push_back(vec4);

	vector<pair<int, int>> out = output.pacificAtlantic(matrix);
	*/

	//int ways = output.numDecodings("226");
	
	vector<string> Dict = { "go","goal","goals","special" };

	bool contains = output.wordBreak("goalspecial", Dict);

	/*
	vector<string> intput = {"a", "bcd", "e"};
	int out = output.wordsTyping(intput, 3, 6);
	*/

	/*
	vector<vector<int>> flights = { {0,1,1}, {1,0,1}, {1,1,0} };
	vector<vector<int>> days = { {1,3,1}, {6,0,3}, {3,3,3} };

	int vaca = output.maxVacationDays(flights, days);
	*/

	/*
	vector<vector<int>> grid = { {1,3,1}, {1,5,1}, {4,2,1} };

	int out = output.minPathSum(grid);
	*/

	/*
	MovingAverage move(3);
	move.next(1);
	move.next(10);
	move.next(3);
	move.next(5);
	*/

	/*
	TreeNode a(1);
	TreeNode b(2);
	TreeNode c(3);

	a.left = &b;
	a.right = &c;

	BSTIterator it(&a);
	int val = it.next();
	*/

	return 0;
}