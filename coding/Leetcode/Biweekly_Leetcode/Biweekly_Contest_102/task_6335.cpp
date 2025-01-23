// https://leetcode.com/contest/biweekly-contest-102/problems/cousins-in-binary-tree-ii/
// Created by ruslan515 on 15.04.23.
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
    TreeNode *replaceValueInTree(TreeNode *root) {
        queue<TreeNode *> q, q_copy;
        q.push(root);
        q.push(nullptr);
        q_copy.push(root);
        q_copy.push(nullptr);
        while (!q.empty()) {
            int size_q = q.size();
            vector<int> v_sum;
            int global_sum = 0;
            int temp_sum = 0;
            int x = 0;
            for (int i = 0; i < size_q; ++i) {
                TreeNode *current = q.front();
                q.pop();
                if (current != nullptr) {
                    ++x;
                    int val = current->val;
                    temp_sum += val;
                    global_sum += val;
                    if (current->left != nullptr) {
                        q.push(current->left);
                        q_copy.push(current->left);
                    }
                    if (current->right != nullptr) {
                        q.push(current->right);
                        q_copy.push(current->right);
                    }
                } else {
                    if (x == 2) {
                        v_sum.push_back(temp_sum);
                    }
                    v_sum.push_back(temp_sum);
                    temp_sum = 0;
                    x = 0;
                }
            }

            for (int i = 0; i < size_q; ++i) {
                TreeNode *current = q_copy.front();
                q.pop();
                if (current != nullptr) {
                    current->val = global_sum - v_sum[i];
                }
            }

        }

        return root;
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
    TreeNode *answer = solve.replaceValueInTree(root);

    return 0;
}