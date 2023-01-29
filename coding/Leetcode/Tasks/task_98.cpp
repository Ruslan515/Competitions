//
// Created by ruslan515 on 29.01.23.
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
    bool validate(TreeNode* root, TreeNode* low, TreeNode* high) {
        // Empty trees are valid BSTs.
        if (root == nullptr) {
            return true;
        }

        // The current node's value must be between low and high.
        if ((low != nullptr and root->val <= low->val) or
            (high != nullptr and root->val >= high->val)) {
            return false;
        }

        // The left and right subtree must also be valid.
        return validate(root->right, root, high) and
               validate(root->left, low, root);
    }

    bool isValidBST(TreeNode* root) {
        return validate(root, nullptr, nullptr);
    }
};

void read_data(TreeNode *&root) {
//    TreeNode *t1 = new TreeNode(1);
//    TreeNode *t2 = new TreeNode(1, nullptr, t1);
//
//    root = t2;

    TreeNode *t1 = new TreeNode(2);
    TreeNode *t2 = new TreeNode(4);
    TreeNode *t3 = new TreeNode(3, t1, t2);

    TreeNode *t4 = new TreeNode(7);
    TreeNode *t5 = new TreeNode(6, nullptr, t4);
    TreeNode *t6 = new TreeNode(5, t3, t5);

    root = t6;
    return;
}

int main() {
    TreeNode *root;
    read_data(root);
    Solution solve;
    cout << solve.isValidBST(root);

    return 0;
}