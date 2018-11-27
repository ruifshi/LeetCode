#include <unordered_map>

using namespace std;

// This is the robot's control interface.
// You should not implement it, or speculate about its implementation
class Robot {
  public:
    // Returns true if the cell in front is open and robot moves into the cell.
    // Returns false if the cell in front is blocked and robot stays in the current cell.
    bool move();

    // Robot will stay in the same cell after calling turnLeft/turnRight.
    // Each turn will be 90 degrees.
    void turnLeft();
    void turnRight();

    // Clean the current cell.
    void clean();
};

class Solution {
public:
    void cleanRoom(Robot& robot);
	void dfs(Robot &robot, int i, int j, int &cur_dir, unordered_map<int, unordered_map<int,int>> cleaned);
};