// https://leetcode.com/problems/design-circular-queue/description/
// Created by ruslan515 on 01.03.23.
//

#include <bits/stdc++.h>

using namespace std;

class MyCircularQueue {
    vector<int> q;
    int head, tail;
    int capacity;
    int count;
public:
    MyCircularQueue(int k) {
        for (int i = 0; i < k; ++i) {
            q.push_back(-1);
        }
        head = 0;
        tail = 0;
        capacity = k;
        count = 0;
    }

    bool enQueue(int value) {
        bool ans = true;
        if (!isFull()){
            tail = head + count;
            tail %= capacity;
            q[tail] = value;
            ++count;
        } else {
            ans = false;
        }
        return ans;
    }

    bool deQueue() {
        bool ans = false;
        if (!isEmpty()) {
            ans = true;
            q[head] = -1;
            ++head;
            head %= capacity;
            --count;
        }
        return ans;
    }

    int Front() {
        int t1 = -1;
        if (!isEmpty()) {
            t1 = q[head];
        }
        return t1;
    }

    int Rear() {
        int t1 = -1;
        if (!isEmpty()) {
            t1 = q[tail];
        }
        return t1;
    }

    bool isEmpty() {
        bool ans = false;
        if (count == 0) {
            ans = true;
        }
        return ans;

    }

    bool isFull() {
        bool ans = capacity == count;
        return ans;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */

int main() {
    MyCircularQueue* myCircularQueue = new MyCircularQueue(8);
    assert(myCircularQueue->enQueue(3) == true);
    assert(myCircularQueue->enQueue(9) == true);
    assert(myCircularQueue->enQueue(5) == true);
    assert(myCircularQueue->enQueue(0) == true);
    assert(myCircularQueue->deQueue() == true);
    assert(myCircularQueue->deQueue() == true);
    assert(myCircularQueue->isEmpty() == false);
    assert(myCircularQueue->isEmpty() == false);
    assert(myCircularQueue->Rear() == 0);
    assert(myCircularQueue->Rear() == 0);
    assert(myCircularQueue->deQueue() == true);


//    MyCircularQueue* myCircularQueue = new MyCircularQueue(3);
//    bool param1 = myCircularQueue->enQueue(1); // return True
//    assert(param1 == true);
//    param1 = myCircularQueue->enQueue(2); // return True
//    assert(param1 == true);
//    param1 = myCircularQueue->enQueue(3); // return True
//    assert(param1 == true);
//    param1 = myCircularQueue->enQueue(4); // return False
//    assert(param1 == false);
//    int param2 = myCircularQueue->Rear();     // return 3
//    assert(param2 == 3);
//    param1 = myCircularQueue->isFull();   // return True
//    assert(param1 == true);
//    param1 = myCircularQueue->deQueue();  // return True
//    assert(param1 == true);
//    param1 = myCircularQueue->enQueue(4); // return True
//    assert(param1 == true);
//    param2 = myCircularQueue->Rear();     // return 4
//    assert(param2 == 4);

//    MyCircularQueue* myCircularQueue = new MyCircularQueue(6);
//    assert(myCircularQueue->enQueue(6) == true);
//    assert(myCircularQueue->Rear() == 6);
//    assert(myCircularQueue->Rear() == 6);
//    assert(myCircularQueue->deQueue() == true);
//    assert(myCircularQueue->enQueue(5) == true);
//    assert(myCircularQueue->Rear() == 5);
//    assert(myCircularQueue->deQueue() == true);
//    assert(myCircularQueue->Front() == -1);
//    assert(myCircularQueue->deQueue() == false);
//    assert(myCircularQueue->deQueue() == false);
//    assert(myCircularQueue->deQueue() == false);

//    param1 = myCircularQueue->enQueue(2); // return True
//    assert(param1 == true);
//    param1 = myCircularQueue->enQueue(3); // return True
//    assert(param1 == true);
//    param1 = myCircularQueue->enQueue(4); // return False
//    assert(param1 == false);
//    int param2 = myCircularQueue->Rear();     // return 3
//    assert(param2 == 3);
//    param1 = myCircularQueue->isFull();   // return True
//    assert(param1 == true);
//    param1 = myCircularQueue->deQueue();  // return True
//    assert(param1 == true);
//    param1 = myCircularQueue->enQueue(4); // return True
//    assert(param1 == true);
//    param2 = myCircularQueue->Rear();     // return 4
//    assert(param2 == 4);

    return 0;
}