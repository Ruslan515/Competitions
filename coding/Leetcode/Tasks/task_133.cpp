// https://leetcode.com/problems/clone-graph/description/
// Created by ruslan515 on 04.04.23.
//

#include <bits/stdc++.h>

using namespace std;

class Node {
public:
    int val;
    vector<Node *> neighbors;

    Node() {
        val = 0;
        neighbors = vector<Node *>();
    }

    Node(int _val) {
        val = _val;
        neighbors = vector<Node *>();
    }

    Node(int _val, vector<Node *> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    Node *cloneGraph(Node *node) {
        if (node == nullptr) {
            return nullptr;
        }
        map<Node *, Node *> mp;
        int val = node->val;
        Node *root = new Node(val);
        mp[node] = root;
        queue<Node *> q;
        q.push(node);
        while (!q.empty()) {
            Node *current = q.front();
            q.pop();
            vector<Node*> v = current->neighbors;
            int size = v.size();
            for (int i = 0; i < size; ++i) {
                Node * temp = v[i];
                if (mp.count(temp) == 0) {
                    val = temp->val;
                    Node * current_copy = new Node(val);
                    mp[temp] = current_copy;
                    q.push(temp);
                }
                mp[current]->neighbors.push_back(mp[temp]);
            }
        }
        return root;
    }
};


void read_data(Node *&root) {
    Node *t1 = new Node(1);
    Node *t2 = new Node(2);
    Node *t4 = new Node(4);
    Node *t3 = new Node(3);
    t1->neighbors = {t2, t4};
    t2->neighbors = {t1, t3};
    t3->neighbors = {t2, t4};
    t4->neighbors = {t1, t3};

    root = t1;
    return;
}

int main() {
    Node *root;
    read_data(root);
    Solution solve;
    Node *ans = solve.cloneGraph(root);

    return 0;
}