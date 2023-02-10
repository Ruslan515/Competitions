// https://leetcode.com/problems/count-univalue-subtrees/description/
// Created by ruslan515 on 08.02.23.
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
    int cnt = 0;

    bool uniq_tree(TreeNode *node) {
        if (node->left == nullptr && node->right == nullptr) {
            ++cnt;
            return true;
        }

        bool label = true;

        if (node->left != nullptr) {
            bool left_uniq = uniq_tree(node->left);
            int val_curr = node->val;
            int val_left = node->left->val;
            bool eq_val = val_left == val_curr;
            label = left_uniq && eq_val && label;
        }
        if (node->right != nullptr) {
            bool right_uniq = uniq_tree(node->right);
            int val_curr = node->val;
            int val_right = node->right->val;
            bool eq_val = val_right == val_curr;
            label = right_uniq && eq_val && label;
        }
        if (!label)
            return false;
        ++cnt;
        return true;
    }

    int countUnivalSubtrees(TreeNode *root) {
        if (root == nullptr)
            return 0;
        uniq_tree(root);
        return cnt;
    }
};

void read_data(TreeNode *&root) {
    TreeNode *t1 = new TreeNode(15);
    TreeNode *t2 = new TreeNode(7);
    TreeNode *t3 = new TreeNode(20, t1, t2);
    TreeNode *t4 = new TreeNode(9);
    TreeNode *t5 = new TreeNode(3, t4, t3);
    root = t5;
    return;
}

int main() {
    TreeNode *root;
    read_data(root);
    Solution solve;
    cout << solve.countUnivalSubtrees(root);

    return 0;
}