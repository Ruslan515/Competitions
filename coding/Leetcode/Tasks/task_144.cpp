// https://leetcode.com/problems/binary-tree-preorder-traversal/?envType=study-plan&id=data-structure-i
// Created by ruslan515 on 25.01.23.
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
    vector<int> ans;
    void recursive(TreeNode* root) {
        if (root != nullptr) {
            int temp = root->val;
            ans.push_back(temp);
        } else {
            return;
        }
        if (root->left != nullptr) {
            recursive(root->left);
        }
        if (root->right != nullptr) {
            recursive(root->right);
        }

        return;
    }

    vector<int> preorderTraversal(TreeNode *root) {
        recursive(root);
        return ans;
    }
};

void read_data(TreeNode*& root) {
    TreeNode* t1 = new TreeNode(3);
    TreeNode* t2 = new TreeNode(2, t1, nullptr);
    TreeNode* t3 = new TreeNode(1, nullptr, t2);
    root = t3;
    return;
}

int main() {
    TreeNode* root;
    read_data(root);
    Solution solve;
    vector<int> ans = solve.preorderTraversal(root);

    return 0;
}