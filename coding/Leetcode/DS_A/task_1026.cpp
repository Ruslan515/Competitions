// https://leetcode.com/problems/maximum-difference-between-node-and-ancestor/
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
    void maxDiff(TreeNode *root, int maxVal, int minVal) {
        if (root == nullptr) {
            return;
        }
        int val = root->val;
        int temp = max(abs(val - maxVal), abs(val - minVal));
        answer = max(answer, temp);
        maxVal = max(maxVal, val);
        minVal = min(minVal, val);
        maxDiff(root->left, maxVal, minVal);
        maxDiff(root->right, maxVal, minVal);
        return;
    }

    int maxAncestorDiff(TreeNode *root) {
        if (!root) {
            return 0;
        }
        maxDiff(root,root->val, root->val);
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

    answer = 7;
    assert(answer == solve.maxAncestorDiff(root));

    return 0;
}