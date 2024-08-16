// https://leetcode.com/problems/kth-largest-element-in-a-stream/description/?envType=daily-question&envId=2024-08-12
// Created by omega515 on 12.08.24.
//

#include <bits/stdc++.h>

using namespace std;

class KthLargest {
public:
    priority_queue<int> pq;
    int k;

    KthLargest(int k, vector<int> &nums) {
        this->k = k;
        int n = nums.size();
        if (nums.size() != 0) {
            sort(nums.begin(), nums.end(), greater<int>());
            for (int i = 0; i < min(k, n); ++i) {
                this->pq.push((-1) * nums[i]);
            }
        }
    }

    int add(int val) {
        int answer;
        if (this->pq.size() != 0) {
            answer = (-1) * this->pq.top();
            if (val > answer && this->pq.size() == this->k) {
                this->pq.pop();
                this->pq.push((-1) * val);
                answer = (-1) * this->pq.top();
            } else if (this->pq.size() != this->k) {
                this->pq.push((-1) * val);
                answer = (-1) * this->pq.top();
            }
        } else {
            answer = val;
            this->pq.push((-1) * val);
        }

        return answer;
    }
};

int main() {
    int k;
    vector<int> nums;
    KthLargest *kl;

    k = 2;
    nums = {0};
    kl = new KthLargest(k, nums);
    assert(-1 == kl->add(-1));
    assert(0 == kl->add(1));
    assert(0 == kl->add(-2));
    assert(0 == kl->add(-4));
    assert(1 == kl->add(3));

    k = 1;
    nums = {};
    kl = new KthLargest(k, nums);
    assert(-3 == kl->add(-3));
    assert(-2 == kl->add(-2));
    assert(-2 == kl->add(-4));
    assert(0 == kl->add(0));
    assert(4 == kl->add(4));

    k = 3;
    nums = {4, 5, 8, 2};
    kl = new KthLargest(k, nums);
    assert(4 == kl->add(3));
    assert(5 == kl->add(5));
    assert(5 == kl->add(10));
    assert(8 == kl->add(9));
    assert(8 == kl->add(4));

    return 0;
}
