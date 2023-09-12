// https://leetcode.com/problems/diameter-of-binary-tree/description/
// Created by ruslan515 on 31.08.23.
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
    int answer = 0;

    int maxDepth(TreeNode *root) {
        if (!root) {
            return 0;
        }
        int maxLeft = 1 + maxDepth(root->left);
        int maxRight = 1 + maxDepth(root->right);
        int ans = max(maxLeft, maxRight);
        return ans;

    }

    int diameterOfBinaryTree(TreeNode *root) {
        if (!root) {
            return 0;
        }
        int leftDepth = maxDepth(root->left);
        int rightDepth = maxDepth(root->right);
        int diameter = leftDepth + rightDepth;
        int dLeft = 0, dRigth = 0;
        if (!root->left) {
             dLeft= diameterOfBinaryTree(root->left);
        }
        if (!root->right) {
            dRigth = diameterOfBinaryTree(root->right);
        }

        answer = max(answer, max(diameter, max(dLeft, dRigth)));


        return answer;
    }

};

void read_data(TreeNode *&root) {
    TreeNode *t1 = new TreeNode(4);
    TreeNode *t2 = new TreeNode(7);
    TreeNode *t3 = new TreeNode(6, t1, t2);
    TreeNode *t4 = new TreeNode(1);
    TreeNode *t5 = new TreeNode(3, t4, t3);
    TreeNode *t6 = new TreeNode(13);
    TreeNode *t7 = new TreeNode(14, t6, nullptr);
    TreeNode *t8 = new TreeNode(10, nullptr, t7);
    TreeNode *t9 = new TreeNode(8, t5, t8);
    root = t9;

    return;
}

int main() {
    TreeNode *root;
    int answer;
    read_data(root);
    Solution solve;

    answer = 6;
    assert(answer == solve.diameterOfBinaryTree(root));

    return 0;
}