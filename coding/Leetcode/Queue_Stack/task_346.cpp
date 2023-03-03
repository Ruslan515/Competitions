// https://leetcode.com/problems/moving-average-from-data-stream/description/
// Created by ruslan515 on 03.03.23.
//

// https://leetcode.com/problems/design-circular-queue/description/
// Created by ruslan515 on 01.03.23.
//

#include <bits/stdc++.h>

using namespace std;

class MovingAverage {
public:
    queue<int> q;
    int count;
    int size_q;
    int sum_q;
    MovingAverage(int size) {
        size_q = size;
        sum_q = 0;
        count = 0;
    }

    double next(int val) {
        if (count >= size_q) {
            int f = q.front();
            sum_q -= f;
            q.pop();
        } else {
            ++count;
        }
        q.push(val);
        sum_q += val;
        double ans = (double) sum_q / count;
        return ans;
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */

int main() {
    int size = 3;
    MovingAverage* obj = new MovingAverage(size);
    assert(obj->next(1) == 1.0);
    assert(obj->next(10) == 5.5);
    assert(obj->next(3) == 4.66667);
    assert(obj->next(5) == 6.0);

    return 0;
}