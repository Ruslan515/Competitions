// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/description/
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
    vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
        vector<vector<int>> answer;
        if (!root) {
            return answer;
        }
        queue<TreeNode*> q;
        q.push(root);
        int idx = 0 ;
        while (!q.empty()) {
            int size_q = q.size();
            vector<int> temp;
            TreeNode * current;
            for (int i = 0; i < size_q; ++i) {
                current = q.front();
                q.pop();
                temp.push_back(current->val);
                if (current->left) {
                    q.push(current->left);
                }
                if (current->right) {
                    q.push(current->right);
                }
            }
            if (idx % 2 != 0) {
                reverse(temp.begin(), temp.end());
            }
            answer.push_back(temp);
            ++idx;
        }

        return answer;
    }
};

void read_data(TreeNode *&root) {
    TreeNode *t1 = new TreeNode(9);
    TreeNode *t2 = new TreeNode(15);
    TreeNode *t3 = new TreeNode(7);
    TreeNode *t4 = new TreeNode(20, t2, t3);
    TreeNode *t5 = new TreeNode(3, t1, t4);

    root = t5;

    return;
}

int main() {
    TreeNode *root;
    vector<vector<int>> answer;
    read_data(root);
    Solution solve;

    answer = {{3},
              {20, 9},
              {15, 7}};
    assert(answer == solve.zigzagLevelOrder(root));

    return 0;
}
