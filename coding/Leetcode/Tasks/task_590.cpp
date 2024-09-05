// https://leetcode.com/problems/n-ary-tree-postorder-traversal/description/?envType=daily-question&envId=2024-08-26
// Created by omega515 on 26.08.24.
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
    void dfs(Node *root, vector<int> &answer) {
        if (root == nullptr) {
            return;
        }
        vector<Node *> children = root->children;
        for (auto child: children) {
            dfs(child, answer);
        }
        answer.push_back(root->val);


    }

    vector<int> postorder(Node *root) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        vector<int> answer;
        dfs(root, answer);

        return answer;
    }
};

void read_data(Node *&root) {
    Node *t1 = new Node(5);
    Node *t2 = new Node(6);
    Node *t3 = new Node(3, {t1, t2});
    Node *t4 = new Node(2);
    Node *t5 = new Node(4);
    Node *t6 = new Node(1, {t3, t4, t5,});
    root = t6;
    return;
}

int main() {
    Node *root;
    read_data(root);
    Solution solve;
    vector<int> answer;

    answer = {5, 6, 3, 2, 4, 1};
    assert(answer == solve.postorder(root));

    return 0;
}