// https://leetcode.com/problems/search-in-a-binary-search-tree/?envType=study-plan&id=data-structure-i
// Created by ruslan515 on 28.01.23.
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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root == nullptr) {
            TreeNode *newNode = new TreeNode(val);
            return newNode;
        }
        int val_root = root->val;
        TreeNode *ans;
        if (val < val_root) {
            ans = insertIntoBST(root->left, val);
            root->left = ans;
        } else if (val_root < val) {
            ans = insertIntoBST(root->right, val);
            root->right = ans;
        }
        return root;
    }
};

void read_data(TreeNode *&root) {
    TreeNode *t1 = new TreeNode(1);
    TreeNode *t2 = new TreeNode(3);
    TreeNode *t3 = new TreeNode(2, t1, t2);

    TreeNode *t4 = new TreeNode(7);
    TreeNode *t5 = new TreeNode(4, t3, t4);

    root = t5;
    return;
}

int main() {
    TreeNode *root;
    read_data(root);
    Solution solve;
    int val = 5;
    TreeNode *ans = solve.insertIntoBST(root, val);

    return 0;
}