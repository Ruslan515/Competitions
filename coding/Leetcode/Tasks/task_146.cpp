// https://leetcode.com/problems/lru-cache/description/
// Created by Ruslan Khalikov on 18.07.2023.
//

#include <bits/stdc++.h>

using namespace std;

struct Node {
    int key;
    int val;
    Node *next;
    Node *prev;
    Node(int key, int val) : key(key), val(val), next(nullptr), prev(nullptr) {}
};

class LRUCache {
public:
    int capacity;
    unordered_map<int, Node*> dic;
    Node *head = new Node(-1, -1);
    Node *tail = new Node(-1, -1);
    LRUCache(int capacity) {
        this->capacity = capacity;
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (dic.find(key) == dic.end()) {
            return -1;
        }

        Node *node = dic[key];
        remove(node);
        add(node);
        return node->val;
    }

    void put(int key, int value) {
        if (dic.find(key) != dic.end()) {
            Node *oldNode = dic[key];
            remove(oldNode);
        }

        Node *node = new Node(key, value);
        dic[key] = node;
        add(node);

        if (dic.size() > capacity) {
            Node *nodeToDelete = head->next;
            remove(nodeToDelete);
            dic.erase(nodeToDelete->key);
        }
    }

    void add(Node *node) {
        Node *previousEnd = tail->prev;
        previousEnd->next = node;
        node->prev = previousEnd;
        node->next = tail;
        tail->prev = node;
    }

    void remove(Node *node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main() {
    LRUCache *lRUCache = new LRUCache(2);
    lRUCache->put(1, 1);
    lRUCache->put(2, 2); // cache is {1=1, 2=2}
    assert(1 == lRUCache->get(1));    // return 1
    lRUCache->put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
    assert(-1 == lRUCache->get(2));    // returns -1 (not found)
    lRUCache->put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
    assert(-1 == lRUCache->get(1));    // return -1 (not found)
    assert(3 == lRUCache->get(3));    // return 3
    assert(4 == lRUCache->get(4));    // return 4

    return 0;
}