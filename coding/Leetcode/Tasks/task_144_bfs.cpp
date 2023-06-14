// https://leetcode.com/problems/minimum-absolute-difference-in-bst/
// Created by ruslan515 on 14.06.23.
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
    vector<int> ans;

    void bfs(TreeNode *root) {
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode *curr;
            int size_q = q.size();
            for (int i = 0; i < size_q; ++i) {
                curr = q.front();
                q.pop();
                int val = curr->val;
                ans.push_back(val);
                if (curr->left != nullptr) {
                    q.push(curr->left);
                }
                if (curr->right != nullptr) {
                    q.push(curr->right);
                }
            }
        }
    }

    int getMinimumDifference(TreeNode *root) {
        bfs(root);
        sort(ans.begin(), ans.end());
        int n = ans.size();
        int minDiff = INT_MAX;
        int diff;
        for (int i = 1; i < n; ++i) {
            diff = abs(ans[i] - ans[i - 1]);
            minDiff = min(minDiff, diff);
        }
        return minDiff;
    }

};

void read_data(TreeNode *&root) {
    TreeNode *t1 = new TreeNode(3);
    TreeNode *t2 = new TreeNode(2, t1, nullptr);
    TreeNode *t3 = new TreeNode(1, nullptr, t2);
    root = t3;
    return;
}

int main() {
    TreeNode *root;
    read_data(root);
    Solution solve;
    solve.getMinimumDifference(root);

    return 0;
}