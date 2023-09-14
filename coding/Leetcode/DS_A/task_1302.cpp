// https://leetcode.com/problems/deepest-leaves-sum/description/
// Created by ruslan515 on 14.09.23.
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
    int deepestLeavesSum(TreeNode *root) {
        int answer = 0;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()) {
            int size_q = q.size();
            TreeNode *current;
            int tempSum = 0;
            for (int i = 0; i < size_q; ++i) {
                current = q.front();
                q.pop();
                tempSum += current->val;
                if (current->left) {
                    q.push(current->left);
                }
                if (current->right) {
                    q.push(current->right);
                }
            }
            answer = tempSum;
        }
        return answer;
    }
};

void read_data(TreeNode *&root) {
    TreeNode *t1 = new TreeNode(7);
    TreeNode *t2 = new TreeNode(4, t1, nullptr);
    TreeNode *t22 = new TreeNode(5);
    TreeNode *t3 = new TreeNode(2, t2, t22);

    TreeNode *t4 = new TreeNode(8);
    TreeNode *t5 = new TreeNode(6, nullptr, t4);
    TreeNode *t6 = new TreeNode(3, nullptr, t5);

    TreeNode *t7 = new TreeNode(1, t3, t6);

    root = t7;

    return;
}

int main() {
    TreeNode *root;
    int answer;
    read_data(root);
    Solution solve;

    answer = 15;
    assert(answer == solve.deepestLeavesSum(root));

    return 0;
}