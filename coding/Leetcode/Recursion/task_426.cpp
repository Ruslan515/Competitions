// https://leetcode.com/problems/convert-binary-search-tree-to-sorted-doubly-linked-list/description/
// Created by ruslan515 on 25.04.23.
//

#include <bits/stdc++.h>

using namespace std;

class Node {
public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node *_left, Node *_right, Node *_next)
            : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node* treeToDoublyList(Node* root) {

    }
};

void read_data(Node *&root) {
    Node *t1 = new Node(4);
    Node *t2 = new Node(5);
    Node *t3 = new Node(2, t1, t2, nullptr);
    Node *t4 = new Node(6);
    Node *t5 = new Node(7);
    Node *t6 = new Node(3, t4, t5, nullptr);
    Node *t7 = new Node(1, t3, t6, nullptr);

    root = t7;
    return;
}

int main() {
    Node *root;
    read_data(root);
    Solution solve;
    Node *ans = solve.connect(root);

    return 0;
}