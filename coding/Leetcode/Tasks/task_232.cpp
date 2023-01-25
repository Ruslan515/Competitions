// https://leetcode.com/problems/implement-queue-using-stacks/?envType=study-plan&id=data-structure-i
// Created by ruslan515 on 25.01.23.
//

#include <bits/stdc++.h>
#include <stack>

using namespace  std;

class MyQueue {
private:
    stack<int> st1, st2;
    int size;
    void transfusion(stack<int>& s1, stack<int>& s2) {
        int x;
        for(int i = 0; i < size; ++i) {
            x = s1.top();
            s1.pop();
            s2.push(x);
        }
    }

public:
    MyQueue() {
        size = 0;
    }

    void push(int x) {
        st1.push(x);
        ++size;
    }

    int pop() {
        transfusion(st1, st2);

        int ans = st2.top();
        st2.pop();
        --size;

        transfusion(st2, st1);
        return ans;
    }

    int peek() {
        transfusion(st1, st2);

        int ans = st2.top();

        transfusion(st2, st1);
        return ans;
    }

    bool empty() {
        bool ans = st1.empty();
        return ans;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */


int main() {
    MyQueue* myQ = new MyQueue();
    myQ->push(1);
    myQ->push(2);
    int val1 = myQ->peek();
    int val2 = myQ->pop();
    if (val1 != val2) {
        cout << "not equal\n";
    } else {
        cout << "equal\n";
    }
    bool ans = myQ->empty();
    cout << ans << "\n";

    return 0;
}