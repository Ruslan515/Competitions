// https://leetcode.com/problems/average-of-levels-in-binary-tree/description/
// Created by ruslan515 on 29.10.23.
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
    vector<double> averageOfLevels(TreeNode *root) {
        vector<double> answer;
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* current;
        while (!q.empty()) {
            int size_q = q.size();
            double avg = 0;
            for (int i = 0; i < size_q; ++i){
                current = q.front();
                q.pop();
                avg += current->val;
                if (current->left) {
                    q.push(current->left);
                }
                if (current->right) {
                    q.push(current->right);
                }
            }
            avg /= size_q;
            answer.push_back(avg);
        }

        return answer;
    }
};

void read_data(TreeNode *&root) {
    TreeNode *t1 = new TreeNode(9);
    TreeNode *t4 = new TreeNode(15);
    TreeNode *t5 = new TreeNode(7);
    TreeNode *t6 = new TreeNode(20, t4, t5);
    TreeNode *t7 = new TreeNode(3, t1, t6);
    root = t7;

    return;
}

int main() {
    TreeNode *root;
    vector<double> answer;
    read_data(root);
    Solution solve;

    answer = {3.00000, 14.50000, 11.00000};
    assert(answer == solve.averageOfLevels(root));

    return 0;
}