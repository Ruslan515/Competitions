// https://leetcode.com/problems/kth-largest-element-in-a-stream/description/
// Created by ruslan515 on 27.06.23.
//

#include <bits/stdc++.h>

using namespace std;

class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    int kSelf;

    KthLargest(int k, vector<int> &nums) {
        kSelf = k;
        for (auto num: nums) {
            if (pq.size() == kSelf) {
                if (num > pq.top()) {
                    pq.pop();
                    pq.push(num);
                }
            } else {
                pq.push(num);
            }
        }
    }

    int add(int val) {
        if (pq.size() == kSelf) {
            if (val > pq.top()) {
                pq.pop();
                pq.push(val);
            }
        } else {
            pq.push(val);
        }

        int answer = pq.top();

        return answer;
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */

int main() {
    vector<int> nums = {4, 5, 8, 2};
    int k = 3;
    KthLargest *kthLargest = new KthLargest(k, nums);
    assert(4 == kthLargest->add(3)); // return (-2) + 0 + 3 = 1
    assert(5 == kthLargest->add(5)); // return 3 + (-5) + 2 + (-1) = -1
    assert(5 == kthLargest->add(10)); // return (-2) + 0 + 3 + (-5) + 2 + (-1) = -3
    assert(8 == kthLargest->add(9)); // return (-2) + 0 + 3 + (-5) + 2 + (-1) = -3
    assert(8 == kthLargest->add(4)); // return (-2) + 0 + 3 + (-5) + 2 + (-1) = -3

    return 0;
}
