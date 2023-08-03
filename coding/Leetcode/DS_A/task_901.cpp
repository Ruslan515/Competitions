// https://leetcode.com/problems/online-stock-span/description/
// Created by Ruslan Khalikov on 01.08.2023.
//

#include <bits/stdc++.h>

using namespace std;

class StockSpanner {
public:
    vector<int> v;

    StockSpanner() {

    }

    int next(int price) {
        int answer = 0;
        v.push_back(price);
        int n = v.size();
        int i = n - 1;
        while (i >= 0 && price >= v[i]) {
            ++answer;
            --i;
        }

        return answer;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */

int main() {
    StockSpanner *stockSpanner = new StockSpanner();
    assert(1 == stockSpanner->next(100)); // return 1
    assert(1 == stockSpanner->next(80));  // return 1
    assert(1 == stockSpanner->next(60));  // return 1
    assert(2 == stockSpanner->next(70));  // return 2
    assert(1 == stockSpanner->next(60));  // return 1
    assert(4 == stockSpanner->next(75));  // return 4,
    assert(6 == stockSpanner->next(85));  // return 6

    return 0;
}