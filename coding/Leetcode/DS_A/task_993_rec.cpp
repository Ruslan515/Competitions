// https://leetcode.com/problems/cousins-in-binary-tree/
// Created by ruslan515 on 01.09.23.
//

#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    void dfs(TreeNode *cur, int target, int &depth, int &ans, TreeNode *&parent) {
        if (!cur) {
            return;
        }
        int val;
        if (cur->left) {
            val = cur->left->val;
            if (val == target) {
                parent = cur;
                ++depth;
                ans = depth;
                return;
            }
            ++depth;
            dfs(cur->left, target, depth, ans, parent);
            --depth;
        }
        if (cur->right) {
            val = cur->right->val;
            if (val == target) {
                parent = cur;
                ++depth;
                ans = depth;
                return;
            }
            ++depth;
            dfs(cur->right, target, depth, ans, parent);
            --depth;
        }
    }

    bool isCousins(TreeNode *root, int x, int y) {
        bool answer = false;
        if (root->val == x || root->val == y) {
            return answer;
        }
        TreeNode *parentX, *parentY;
        int depthX = 0, depthY = 0;
        int ansX, ansY;
        dfs(root, x, depthX, ansX, parentX);
        dfs(root, y, depthY, ansY, parentY);
        if (ansX == ansY && parentX != parentY) {
            answer = true;
        }
        return answer;
    }
};

void read_data(TreeNode *&root) {
//    TreeNode *t1 = new TreeNode(4);
//    TreeNode *t2 = new TreeNode(2, t1, nullptr);
//    TreeNode *t4 = new TreeNode(3);
//    TreeNode *t5 = new TreeNode(1, t2, t4);
//
//    root = t5;

//    TreeNode *t1 = new TreeNode(4);
//    TreeNode *t2 = new TreeNode(2, nullptr, t1);
//    TreeNode *t3 = new TreeNode(5);
//    TreeNode *t4 = new TreeNode(3, nullptr, t3);
//    TreeNode *t5 = new TreeNode(1, t2, t4);
//
//    root = t5;

    TreeNode *t1 = new TreeNode(4);
    TreeNode *t2 = new TreeNode(2, nullptr, t1);
    TreeNode *t3 = new TreeNode(5);
    TreeNode *t4 = new TreeNode(3, nullptr, t3);
    TreeNode *t5 = new TreeNode(1, t2, t4);

    root = t5;

    return;
}

int main() {
    TreeNode *root;
    int x;
    int y;
    bool answer;
    read_data(root);
    Solution solve;

    answer = true;
    x = 5, y = 4;
    assert(answer == solve.isCousins(root, x, y));

    return 0;
}