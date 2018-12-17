#include "stdafx.h"
#include "RobotRoomCleaner.h"

bool Robot::move() {
	return true;
}

void Robot::turnLeft() {
	return;
}

void Robot::turnRight() {
	return;
}

void Robot::clean() {
	return;
}

//O(matirx size)
void Solution::cleanRoom(Robot& robot) {
    int cur_dir = 0;
	unordered_map<int, unordered_map<int,int>> cleaned;
    dfs(robot, 0, 0, cur_dir, cleaned);//0->up, 90->right, 180->down, 270->left
}

void Solution::dfs(Robot &robot, int i, int j, int &cur_dir, unordered_map<int, unordered_map<int,int>> cleaned) {
    if(cleaned[i][j] == 1)
        return;
    cleaned[i][j] = 1;
    robot.clean();
    for(int n = 0; n < 4; ++n) {
                
        if(robot.move()) {
            int x = i, y = j;
            switch(cur_dir) {
                case 0:
                    x = i - 1;
                    break;
                case 90:
                    y = j + 1;
                    break;
                case 180:
                    x = i + 1;
                    break;
                case 270:
                    y = j - 1;
                    break;
                default:
                    break;
            }
            dfs(robot, x, y, cur_dir, cleaned);
            robot.turnLeft();
            robot.turnLeft();
            robot.move();
            robot.turnRight();
            robot.turnRight();
        }
                
        robot.turnRight();
        cur_dir += 90;
        cur_dir %= 360;
	}
}