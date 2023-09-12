// https://leetcode.com/problems/maximum-depth-of-n-ary-tree/
// Created by ruslan515 on 02.09.23.
//

#include <bits/stdc++.h>

using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node *> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node *> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    int maxDepth(Node *root) {

    }
};

void read_data(Node *&root) {
    Node *t1 = new Node(5);
    Node *t2 = new Node(6);
    Node *t3 = new Node(3, {t1, t2});

    Node *t4 = new Node(2);
    Node *t5 = new Node(4);
    Node *t6 = new Node(1, {t4, t3, t5});
    root = t6;

    return;
}

int main() {
    Node *root;
    int answer;
    read_data(root);
    Solution solve;

    answer = 3;
    assert(answer == solve.maxDepth(root));

    return 0;
}