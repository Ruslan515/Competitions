// https://leetcode.com/problems/design-hashmap/description/?envType=daily-question&envId=2023-10-04
// Created by ruslan515 on 04.10.23.
//

#include <bits/stdc++.h>

using namespace std;

class MyHashMap {
public:
    const int MAX_CNT = pow(10, 6) + 1;
    vector<int> thisMap;

    MyHashMap() {
        thisMap.resize(MAX_CNT, -1);
    }

    void put(int key, int value) {
        thisMap[key] = value;
    }

    int get(int key) {
        return thisMap[key];
    }

    void remove(int key) {
        thisMap[key] = -1;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */

int main() {
    MyHashMap *myHashMap = new MyHashMap();
    myHashMap->put(1, 1); // The map is now [[1,1]]
    myHashMap->put(2, 2); // The map is now [[1,1], [2,2]]
    assert(1 == myHashMap->get(1));    // return 1, The map is now [[1,1], [2,2]]
    assert(-1 == myHashMap->get(3));    // return -1 (i.e., not found), The map is now [[1,1], [2,2]]
    myHashMap->put(2, 1); // The map is now [[1,1], [2,1]] (i.e., update the existing value)
    assert(1 == myHashMap->get(2));    // return 1, The map is now [[1,1], [2,1]]
    myHashMap->remove(2); // remove the mapping for 2, The map is now [[1,1]]
    assert(-1 == myHashMap->get(2));    // return -1 (i.e., not found), The map is now [[1,1]]

    return 0;
}