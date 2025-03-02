// https://leetcode.com/problems/design-most-recently-used-queue/description/?envType=weekly-question&envId=2025-02-15
// Created by omega515 on 18.02.2025.
//

#include <bits/stdc++.h>

using namespace std;

class MRUQueue {
private:
    vector<int> vec;
public:


    MRUQueue(int n) {
        for (int i = 1; i <= n; ++i) {
            vec.push_back(i);
        }
    }

    int fetch(int k) {
        int val = this->vec[k - 1];
        this->vec.erase(this->vec.begin() + k - 1);
        this->vec.push_back(val);
        return val;

    }
};

int main() {
    MRUQueue *mruQueue = new MRUQueue(8);
    assert(3 == mruQueue->fetch(3));
    assert(6 == mruQueue->fetch(5));
    assert(2 == mruQueue->fetch(2));
    assert(2 == mruQueue->fetch(8));

    return 0;
}
