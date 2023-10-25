// https://leetcode.com/problems/delete-leaves-with-a-given-value/
// Created by ruslan515 on 13.10.23.
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
    void solve(TreeNode *&root, int tar) {
        if (!root) return;

        solve(root->left, tar);
        solve(root->right, tar);

        if (!root->left && !root->right && root->val == tar) {
            root = NULL;
        }
    }

    TreeNode *removeLeafNodes(TreeNode *root, int target) {
        solve(root, target);
        return root;
    }
};

void read_data(TreeNode *&root, TreeNode *&answer) {
    TreeNode *t1 = new TreeNode(2);
    TreeNode *t2 = new TreeNode(2, t1, nullptr);
    TreeNode *t3 = new TreeNode(2);
    TreeNode *t4 = new TreeNode(4);
    TreeNode *t5 = new TreeNode(3, t3, t4);
    TreeNode *t6 = new TreeNode(1, t2, t5);
    root = t6;

    return;
}

int main() {
    TreeNode *root, *answer;
    int target;

    read_data(root, answer);
    Solution solve;

    target = 2;
    assert(answer == solve.removeLeafNodes(root, target));

    return 0;
}