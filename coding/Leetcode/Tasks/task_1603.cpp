// https://leetcode.com/problems/design-parking-system/
// Created by ruslan515 on 29.05.23.
//

#include <bits/stdc++.h>

using namespace std;

class ParkingSystem {
public:
    map<int, int> countSpace;

    ParkingSystem(int big, int medium, int small) {
        countSpace[1] = big;
        countSpace[2] = medium;
        countSpace[3] = small;
    }

    bool addCar(int carType) {
        bool answer = false;
        if (countSpace[carType] > 0) {
            --countSpace[carType];
            answer = true;
        }
        return answer;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */

int main() {
    ParkingSystem *obj = new ParkingSystem(1, 1, 0);
    assert(obj->addCar(1) == true);
    assert(obj->addCar(2) == true);
    assert(obj->addCar(3) == false);
    assert(obj->addCar(1) == false);

    return 0;
}