// https://leetcode.com/problems/binary-tree-right-side-view/description/
// Created by ruslan515 on 12.09.23.
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
    vector<int> rightSideView(TreeNode *root) {
        vector<int> answer;
        if (!root) {
            return answer;
        }
        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty()) {
            int size_q = q.size();
            for (int i = 0; i < size_q; ++i) {
                TreeNode *current = q.front();
                if (i == size_q - 1) {
                    answer.push_back(current->val);
                }
                q.pop();
                if (current->left) {
                    q.push(current->left);
                }
                if (current->right) {
                    q.push(current->right);
                }
            }
        }

        return answer;
    }
};

void read_data(TreeNode *&root) {
    TreeNode *t1 = new TreeNode(5);
    TreeNode *t2 = new TreeNode(2, nullptr, t1);
    TreeNode *t3 = new TreeNode(4);
    TreeNode *t4 = new TreeNode(3, nullptr, t3);
    TreeNode *t5 = new TreeNode(1, t2, t4);

    root = t5;

    return;
}

int main() {
    TreeNode *root;
    int x;
    int y;
    vector<int> answer;
    read_data(root);
    Solution solve;

    answer = {1, 3, 4};

    assert(answer == solve.rightSideView(root));

    return 0;
}