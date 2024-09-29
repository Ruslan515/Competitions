// https://leetcode.com/problems/design-circular-deque/description/?envType=daily-question&envId=2024-09-28
// Created by omega515 on 28.09.24.
//

#include <bits/stdc++.h>

using namespace std;

class MyCircularDeque {
public:
    struct Node {
        Node *next;
        Node *prev;
        int val;

        Node(int val) {
            this->val = val;
            this->next = nullptr;
            this->prev = nullptr;
        }
    };

    int size;
    int count;
    Node *head;
    Node *tail;

    MyCircularDeque(int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        this->size = k;
        this->count = 0;
        Node *head = nullptr;
        Node *tail = nullptr;
    }

    void firstInsert(int value) {
        Node *node = new Node(value);
        this->head = node;
        this->tail = node;
    }

    bool insertFront(int value) {
        bool answer = false;
        if (this->count < this->size) {
            if (this->count == 0) {
                this->firstInsert(value);
            } else {
                Node *firstNode = new Node(value);
                firstNode->next = head;
                head->prev = firstNode;
                head = firstNode;
            }
            answer = true;
            ++this->count;
        }
        return answer;
    }

    bool insertLast(int value) {
        bool answer = false;
        if (this->count < this->size) {
            if (this->count == 0) {
                this->firstInsert(value);
            } else {
                Node *lastNode = new Node(value);
                this->tail->next = lastNode;
                lastNode->prev = this->tail;
                tail = lastNode;
            }
            answer = true;
            ++this->count;
        }
        return answer;
    }

    bool deleteFront() {
        bool answer = false;
        if (this->count != 0) {
            answer = true;
            if (this->count == 1) {
                this->head = nullptr;
                this->tail = nullptr;
            } else {
                this->head = this->head->next;
                this->head->prev = nullptr;
            }
            --this->count;
        }

        return answer;
    }

    bool deleteLast() {
        bool answer = false;
        if (this->count != 0) {
            answer = true;
            if (this->count == 1) {
                this->tail = nullptr;
                this->head = nullptr;
            } else {
                this->tail = this->tail->prev;
                this->tail->next = nullptr;
            }
            --this->count;
        }

        return answer;
    }

    int getFront() {
        int answer = -1;
        if (this->count != 0) {
            answer = this->head->val;
        }

        return answer;
    }

    int getRear() {
        int answer = -1;
        if (this->count != 0) {
            answer = this->tail->val;
        }
        return answer;
    }

    bool isEmpty() {
        bool answer = false;
        if (this->count == 0) {
            answer = true;
        }
        return answer;
    }

    bool isFull() {
        bool answer = false;
        if (this->count == this->size) {
            answer = true;
        }
        return answer;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */

int main() {
    MyCircularDeque *myCircularDeque = new MyCircularDeque(4);
    assert(true == myCircularDeque->insertFront(9));
    assert(true == myCircularDeque->deleteLast());
    assert(-1 == myCircularDeque->getRear());
    assert(-1 == myCircularDeque->getFront());
    assert(-1 == myCircularDeque->getFront());
    assert(false == myCircularDeque->deleteFront());
    assert(true == myCircularDeque->insertFront(6));
    assert(true == myCircularDeque->insertLast(5));
    assert(6 == myCircularDeque->getFront());
    assert(true == myCircularDeque->insertFront(6));


//    MyCircularDeque *myCircularDeque = new MyCircularDeque(8);
//    assert(true == myCircularDeque->insertFront(5));
//    assert(5 == myCircularDeque->getFront());
//    assert(false == myCircularDeque->isEmpty());
//    assert(true == myCircularDeque->deleteFront());
//    assert(true == myCircularDeque->insertLast(3));
//    assert(3 == myCircularDeque->getRear());
//    assert(true == myCircularDeque->insertLast(7));
//    assert(true == myCircularDeque->insertFront(7));
//    assert(true == myCircularDeque->deleteLast());
//    assert(true == myCircularDeque->insertLast(4));
//    assert(false == myCircularDeque->isEmpty());

//    MyCircularDeque *myCircularDeque = new MyCircularDeque(3);
//
//    assert(true == myCircularDeque->insertLast(1));  // return True
//    assert(true == myCircularDeque->insertLast(2));  // return True
//    assert(true == myCircularDeque->insertFront(3)); // return True
//    assert(false == myCircularDeque->insertFront(4)); // return False, the queue is full->
//    assert(2 == myCircularDeque->getRear());      // return 2
//    assert(true == myCircularDeque->isFull());       // return True
//    assert(true == myCircularDeque->deleteLast());   // return True
//    assert(true == myCircularDeque->insertFront(4)); // return True
//    assert(4 == myCircularDeque->getFront());     // return 4

    return 0;
}