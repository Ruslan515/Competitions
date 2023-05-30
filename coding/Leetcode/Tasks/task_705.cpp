// https://leetcode.com/problems/design-hashset/
// Created by ruslan515 on 30.05.23.
//

#include <bits/stdc++.h>

using namespace std;

class MyHashSet {
public:
    int maxElement = pow(10, 6) + 1;
    vector<bool> hash_set;
    MyHashSet() {
        hash_set.resize(maxElement);
    }

    void add(int key) {
        hash_set[key] = true;
    }

    void remove(int key) {
        hash_set[key] = false;
    }

    bool contains(int key) {
        bool answer = false;
        if (hash_set[key]) {
            answer = true;
        }
        return answer;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */

int main() {
    MyHashSet* obj = new MyHashSet();
    obj->add(1);
    obj->add(2);
    assert(obj->contains(1) == true);
    assert(obj->contains(3) == false);
    obj->add(2);
    assert(obj->contains(2) == true);
    obj->remove(2);
    assert(obj->contains(2) == false);

    return 0;
}