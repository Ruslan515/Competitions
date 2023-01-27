// https://leetcode.com/problems/invert-binary-tree/?envType=study-plan&id=data-structure-i
// Created by ruslan515 on 27.01.23.
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
    void invert(TreeNode *root) {
        if (root == nullptr) {
            return;
        }
        TreeNode *left;
        TreeNode *right;
        left = root->left;
        right = root->right;
        root->left = right;
        root->right = left;
        invert(root->left);
        invert(root->right);
    }

    TreeNode *invertTree(TreeNode *root) {
        if (root == nullptr) {
            return root;
        }
        invert(root);
        return root;
    }
};

void read_data(TreeNode *&root) {
    TreeNode *t1 = new TreeNode(1);
    TreeNode *t2 = new TreeNode(3);
    TreeNode *t3 = new TreeNode(2, t1, t2);

    TreeNode *t4 = new TreeNode(6);
    TreeNode *t5 = new TreeNode(9);
    TreeNode *t6 = new TreeNode(7, t4, t5);

    TreeNode *t7 = new TreeNode(4, t3, t6);
    root = t7;
    return;
}

int main() {
    TreeNode *root;
    read_data(root);
    Solution solve;
    TreeNode *ans = solve.invertTree(root);

    return 0;
}