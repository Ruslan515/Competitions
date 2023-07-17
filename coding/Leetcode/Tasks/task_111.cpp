// https://leetcode.com/problems/minimum-depth-of-binary-tree/
// Created by ruslan515 on 10.07.23.
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
    int minDepth(TreeNode *root) {
        if (root == nullptr) {
            return 0;
        }
        queue<TreeNode *> q;
        q.push(root);
        TreeNode *current;

        int answer = 0;
        while (!q.empty()) {
            ++answer;
            int size_q = q.size();
            for (int i = 0; i < size_q; ++i) {
                current = q.front();
                q.pop();
                if (current->left == nullptr && current->right == nullptr) {
                    return answer;
                }
                if (current->left != nullptr) {
                    q.push(current->left);
                }
                if (current->right != nullptr) {
                    q.push(current->right);
                }
            }

        }
        return answer;
    }
};

void read_data(TreeNode *&root) {
//    TreeNode *t6 = new TreeNode(6);
//    TreeNode *t5 = new TreeNode(5, nullptr, t6);
//    TreeNode *t4 = new TreeNode(4, nullptr, t5);
//    TreeNode *t3 = new TreeNode(3, nullptr, t4);
//    TreeNode *t2 = new TreeNode(2, nullptr, t3);
//
//    root = t2;

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
    int answer = 2;
    assert(answer == solve.minDepth(root));

    return 0;
}