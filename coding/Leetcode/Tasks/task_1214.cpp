// https://leetcode.com/problems/two-sum-bsts/
// Created by ruslan515 on 22.06.23.
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
    void graphToVector(TreeNode *root, vector<int> &v) {
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()) {
            int size_q = q.size();
            for (int i = 0; i < size_q; ++i) {
                TreeNode *curr = q.front();
                q.pop();
                v.push_back(curr->val);
                if (curr->left != nullptr) {
                    q.push(curr->left);
                }
                if (curr->right != nullptr) {
                    q.push(curr->right);
                }
            }
        }

    }

    bool twoSumBSTs(TreeNode *root1, TreeNode *root2, int target) {
        vector<int> v1, v2;
        graphToVector(root1, v1);
        graphToVector(root2, v2);
        int n1 = v1.size(), n2 = v2.size();
        bool answer = false;
        for (int i = 0; i < n1; ++i) {
            int val = target - v1[i];
            for (int j = 0; j < n2; ++j) {
                if (v2[j] == val) {
                    answer = true;
                    return answer;
                }
            }
        }

        return answer;
    }
};


int main() {
    TreeNode *root1, *root2;
    bool ans;
    int target;
    Solution solve;

    TreeNode *t1 = new TreeNode(1);
    TreeNode *t2 = new TreeNode(4);
    TreeNode *t3 = new TreeNode(2, t1, t2);
    root1 = t3;

    TreeNode *t4 = new TreeNode(0);
    TreeNode *t5 = new TreeNode(3);
    TreeNode *t6 = new TreeNode(1, t4, t5);
    root2 = t6;

    target = 5;
    ans = true;
    assert(ans == solve.twoSumBSTs(root1, root2, target));

    // ===============================================================

    t1 = new TreeNode(-10);
    t2 = new TreeNode(10);
    t3 = new TreeNode(0, t1, t2);
    root1 = t3;

    t4 = new TreeNode(0);
    t5 = new TreeNode(2);
    t6 = new TreeNode(1, t4, t5);
    TreeNode *t7 = new TreeNode(7);
    TreeNode *t8 = new TreeNode(5, t6, t7);
    root2 = t8;

    target = 5;
    assert(ans == solve.twoSumBSTs(root1, root2, target));

    return 0;
}