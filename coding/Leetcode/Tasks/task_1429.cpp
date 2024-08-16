//
// Created by omega515 on 30.07.24.
//

#include <bits/stdc++.h>

using namespace std;

class FirstUnique {
public:
    unordered_set<int> unique;
    unordered_set<int> notUnique;
    queue<int> queueUnique;
    int size_q;
    int idx;
    int firstUnique = -1;


    FirstUnique(vector<int> &nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        int n = nums.size();

        for (int num: nums) {
            this->queueUnique.push(num);
            if (this->unique.find(num) == this->unique.end()) {
                // пока не встречался
                this->unique.insert(num);
            } else {
                this->unique.erase(num);
                this->notUnique.insert(num);
            }
        }
        int front;
        while (!this->queueUnique.empty()) {
            front = this->queueUnique.front();
            if (this->unique.find(front) != this->unique.end()) {
                this->firstUnique = front;
                break;
            }
            this->queueUnique.pop();
        }


    }

    int showFirstUnique() {
        return this->firstUnique;
    }

    void add(int value) {
        this->queueUnique.push(value);
        if (value == this->queueUnique.front()) {
            int front;
            this->unique.erase(value);
            if (this->unique.size() == 0) {
                this->firstUnique = -1;
                return;
            }
            this->notUnique.insert(value);
            while (true) {
                front = this->queueUnique.front();
                this->queueUnique.pop();
                if (this->unique.find(front) != this->unique.end()) {
                    this->firstUnique = front;
                    break;
                }
                this->queueUnique.pop();
            }

        } else if (this->unique.find(value) != this->unique.end()) {
            this->unique.erase(value);
            this->notUnique.insert(value);
        } else {
            this->unique.insert(value);
        }
    }
};

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */

int main() {
//    vector<int> nums = {2, 3, 5};
//    FirstUnique *obj = new FirstUnique(nums);
//    assert(2 == obj->showFirstUnique());
//    obj->add(5);
//    assert(2 == obj->showFirstUnique());
//    obj->add(2);
//    assert(3 == obj->showFirstUnique());
//    obj->add(3);
//    assert(-1 == obj->showFirstUnique());

    vector<int> nums = {7, 7, 7, 7, 7, 7};
    FirstUnique *obj = new FirstUnique(nums);
    assert(-1 == obj->showFirstUnique());
    obj->add(7);
    obj->add(3);
    obj->add(3);
    obj->add(7);
    obj->add(17);
    assert(17 == obj->showFirstUnique());

    return 0;
}
