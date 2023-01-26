// https://leetcode.com/problems/binary-tree-postorder-traversal/?envType=study-plan&id=data-structure-i
// Created by ruslan515 on 26.01.23.
//

#include <bits/stdc++.h>

const int MY_NULL = - 1000;

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
        if (root == nullptr) {
            return;
        }
        if (root->left != nullptr) {
            recursive(root->left);
        }
        if (root->right != nullptr) {
            recursive(root->right);
        }
        int temp = root->val;
        ans.push_back(temp);

        return;
    }

    vector<int> postorderTraversal(TreeNode *root) {
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
    vector<int> ans = solve.postorderTraversal(root);
    for (int a: ans) {
        cout << a << " ";
    }
    cout << "\n";

    return 0;
}