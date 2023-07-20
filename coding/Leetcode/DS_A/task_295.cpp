// https://leetcode.com/problems/find-median-from-data-stream/description/
// Created by Ruslan Khalikov on 19.07.2023.
//

#include <bits/stdc++.h>

using namespace std;

class MedianFinder {
public:
    vector<int> v;

    MedianFinder() {

    }

    void addNum(int num) {
        v.push_back(num);
    }

    double findMedian() {
        double ans;
        sort(v.begin(), v.end());
        if (this->v.size() % 2 == 0) {
            ans = (double) v[v.size() / 2 - 1];
            ans += v[v.size() / 2];
            ans /= 2;
        } else {
            ans = (double) v[v.size() / 2];
        }
        return ans;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
int main() {
    double answer;
    MedianFinder *medianFinder = new MedianFinder();
    medianFinder->addNum(1);    // arr = [1]
    medianFinder->addNum(2);    // arr = [1, 2]
    assert(1.5 == medianFinder->findMedian()); // return 1.5 (i.e., (1 + 2) / 2)
    medianFinder->addNum(3);    // arr[1, 2, 3]
    assert(2.0 == medianFinder->findMedian()); // return 2.0

    return 0;
}