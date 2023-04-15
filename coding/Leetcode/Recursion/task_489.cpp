// https://leetcode.com/problems/robot-room-cleaner/description/
// Created by ruslan515 on 15.04.23.
//

#include <bits/stdc++.h>

using namespace std;

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
    void cleanCell(Robot &robot) {
        if (robot.move()) {
            robot.clean();
            cleanCell(robot);
        } else {
            robot.turnRight();
            cleanCell(robot);
            robot.turnLeft();
        }
    }

    void cleanRoom(Robot &robot) {
        robot.clean();
        cleanCell(robot);

    }
};

int main() {

    return 0;
}