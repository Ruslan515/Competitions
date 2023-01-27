// https://leetcode.com/problems/maximum-depth-of-binary-tree/?envType=study-plan&id=data-structure-i
// Created by ruslan515 on 26.01.23.
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
    int sum = 0;
    bool ans = false;

    void pathSum(TreeNode *root, int targetSum) {
        if (root->left == nullptr && root->right == nullptr) {
            sum += root->val;
            if (sum == targetSum) {
                ans = true;
            }
            sum -= root->val;
            return;
        }
        sum += root->val;
        if (root->left != nullptr) {
            pathSum(root->left, targetSum);
            if (ans)
                return;
        }
        if (root->right != nullptr) {
            pathSum(root->right, targetSum);
            if (ans)
                return;

        }
        sum -= root->val;
    }

    bool hasPathSum(TreeNode *root, int targetSum) {
        if (root == nullptr) {
            return false;
        }
        pathSum(root, targetSum);

        return ans;
    }
};

void read_data(TreeNode *&root) {
    TreeNode *t1 = new TreeNode(7);
    TreeNode *t2 = new TreeNode(2);
    TreeNode *t3 = new TreeNode(11, t1, t2);
    TreeNode *t4 = new TreeNode(4, t3, nullptr);

    TreeNode *t5 = new TreeNode(1);
    TreeNode *t6 = new TreeNode(4, nullptr, t5);

    TreeNode *t7 = new TreeNode(13);
    TreeNode *t8 = new TreeNode(8, t7, t6);

    TreeNode *t9 = new TreeNode(5, t4, t8);

    root = t9;
    return;
}

int main() {
    TreeNode *root;
    read_data(root);
    Solution solve;
    int targetSum = 22;
    cout << solve.hasPathSum(root, targetSum);

    return 0;
}