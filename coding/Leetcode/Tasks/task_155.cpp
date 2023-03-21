// https://leetcode.com/problems/min-stack/description/
// Created by ruslan515 on 16.03.23.
//

#include <bits/stdc++.h>

using namespace std;

class MinStack {
public:
    int globalMin;
    stack<pair<int, int>> st;

    MinStack() {

    }

    void push(int val) {
        int currentMin;
        if (st.empty()) {
            currentMin = val;
        } else {
            currentMin = min(val, st.top().second);
        }
        st.push(make_pair(val, currentMin));
        return;
    }

    void pop() {
        st.pop();
    }

    int top() {
        int answer = st.top().first;
        return answer;
    }

    int getMin() {
        int globalMin = st.top().second;
        return globalMin;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

int main() {
    MinStack *mst = new MinStack();
    mst->push(-2);
    mst->push(0);
    mst->push(-3);
    assert(mst->getMin() == -3);
    mst->pop();
    assert(mst->top() == 0);
    assert(mst->getMin() == -2);


    return 0;
}