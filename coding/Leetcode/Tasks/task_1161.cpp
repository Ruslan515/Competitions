// https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/
// Created by ruslan515 on 15.06.23.
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
    int maxLevelSum(TreeNode *root) {
        int currLevel = 0;
        int maxLevel = 0;
        int maxSum = -INT_MAX;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()) {
            ++currLevel;
            int size_q = q.size();
            int tempSum = 0;
            for (int i = 0; i < size_q; ++i) {
                TreeNode * current = q.front();
                q.pop();
                tempSum += current->val;
                if (current->left != nullptr) {
                    q.push(current->left);
                }
                if (current->right != nullptr) {
                    q.push(current->right);
                }
            }
            if (tempSum > maxSum) {
                maxSum = tempSum;
                maxLevel = currLevel;
            }
        }

        return maxLevel;
    }
};

void read_data(TreeNode *&root) {
    TreeNode *t1 = new TreeNode(7);
    TreeNode *t2 = new TreeNode(-8);
    TreeNode *t3 = new TreeNode(7, t1, t2);

    TreeNode *t4 = new TreeNode(0);
    TreeNode *t5 = new TreeNode(1, t3, t4);

    root = t5;
    return;
}

int main() {
    TreeNode *root;
    read_data(root);
    Solution solve;

    int answer = 2;
    assert(answer == solve.maxLevelSum(root));

    return 0;
}