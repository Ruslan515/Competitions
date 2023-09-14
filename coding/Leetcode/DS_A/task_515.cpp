// https://leetcode.com/problems/find-largest-value-in-each-tree-row/description/
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
    vector<int> largestValues(TreeNode *root) {
        vector<int> answer;
        if (!root) {
            return answer;
        }
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int maxE = INT_MIN;
            int size_q = q.size();
            for (int i = 0; i < size_q; ++i) {
                TreeNode* current = q.front();
                q.pop();
                int val = current->val;
                maxE  = max(maxE, val);
                if (current->left) {
                    q.push(current->left);
                }
                if (current->right) {
                    q.push(current->right);
                }
            }
            answer.push_back(maxE);
        }

        return answer;
    }
};

void read_data(TreeNode *&root) {
    TreeNode *t1 = new TreeNode(5);
    TreeNode *t11 = new TreeNode(3);
    TreeNode *t2 = new TreeNode(3, t1, t11);
    TreeNode *t3 = new TreeNode(9);
    TreeNode *t4 = new TreeNode(2, nullptr, t3);
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

    answer = {1, 3, 9};
    assert(answer == solve.largestValues(root));

    return 0;
}