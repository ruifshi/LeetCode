// Test.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
//#include "ValidNumber.h"
//#include "ValidParentheses.h"
//#include "ImageSmoother.h"
//#include "IntersectionOfTwoArrays.h"
//#include "MaxConsecutiveOnesFlip.h"
#include "ShortestPalindrome.h"

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

	string out = output.shortestPalindrome("ananab");

	return 0;
}