#include "stdafx.h"
#include "DesignSnakeGame.h"

/*
int w, h, pos;
vector<pair<int, int>> food;
unordered_set<pair<int, int>> hist;
deque<pair<int, int>> q;
*/

SnakeGame::SnakeGame(int width, int height, vector<vector<int>>& food) {
	this->food = food;
	w = width, h = height, pos = 0;
	q.push_back(make_pair(0, 0));
}

// deque keeps tracks of the head and tail. Everytime we make a move, we delete the tail (front) and add to head (back).
// if we are out of bounds or hit ourselves (hist), then return -1
// if we find a food, then add to tail (front) and body (hist)
// pos variable is here bc we have to get the food in order and only one appears at a time
int SnakeGame::move(string direction) {
	int row = q.back().first, col = q.back().second;
	pair<int, int> d = q.front(); q.pop_front();
	hist.erase(d);

	if (direction == "U")
		row--;
	else if (direction == "D")
		row++;
	else if (direction == "L")
		col--;
	else if (direction == "R")
		col++;

	if (row < 0 || col < 0 || col >= w || row >= h || hist.find(make_pair(row, col)) != hist.end())
		return -1;

	hist.insert(make_pair(row, col));
	q.push_back(make_pair(row, col));

	if (pos >= food.size())
		return q.size() - 1;

	if (row == food[pos][0] && col == food[pos][1]) {
		pos++;
		q.push_front(d);
		hist.insert(d);
	}

	return q.size() - 1;
}