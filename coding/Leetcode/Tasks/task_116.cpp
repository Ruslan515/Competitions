// https://leetcode.com/problems/populating-next-right-pointers-in-each-node/description/
// Created by ruslan515 on 19.02.23.
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
    Node *connect(Node *root) {
        if (root == nullptr) {
            return root;
        }
        queue<Node*> q;
        q.push(root);
        Node * current;
        while (!q.empty()) {
            int size_q = q.size();
            vector<Node*> vec;
            for (int i = 0; i < size_q; ++i) {
                current = q.front();
                q.pop();
                if (current->left != nullptr) {
                    vec.push_back(current->left);
                    vec.push_back(current->right);

                    q.push(current->left);
                    q.push(current->right);
                }
            }
            int size_vec = vec.size() - 1;
            for (int i = 0; i < size_vec; ++i) {
                current = vec[i];
                Node * next = vec[i + 1];
                current->next = next;
            }
        }
        return root;
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