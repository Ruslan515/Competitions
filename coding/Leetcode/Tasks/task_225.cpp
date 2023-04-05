// https://leetcode.com/problems/implement-stack-using-queues/description/
// Created by ruslan515 on 05.04.23.
//

#include <bits/stdc++.h>

using namespace std;

class MyStack {
private:
    queue<int> q1, q2;
    int size;
public:
    MyStack() {
        size = 0;
    }

    void push(int x) {
        q1.push(x);
        ++size;
        return;
    }

    void pour(queue<int> &source, queue<int> &target, int n) {
        int temp;
        for (int i = 0; i < n; ++i) {
            temp = source.front();
            source.pop();
            target.push(temp);
        }
        return;
    }

    int pop() {
        pour(q1, q2, size - 1);

        int ans = q1.front();
        q1.pop();
        --size;

        pour(q2, q1, size);

        return ans;
    }

    int top() {
        pour(q1, q2, size - 1);

        int ans = q1.front();
        q1.pop();
        q2.push(ans);
        pour(q2, q1, size);

        return ans;
    }

    bool empty() {
        bool ans = q1.empty();
        return ans;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */

int main() {
    MyStack *myS = new MyStack();
    myS->push(1);
    myS->push(2);
    int val1 = myS->top();
    int val2 = myS->pop();
    assert(val1 == val2);
    assert(myS->empty() == false);

    return 0;
}