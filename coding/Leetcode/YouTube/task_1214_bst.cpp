// https://leetcode.com/problems/two-sum-bsts/
// Created by ruslan515 on 25.06.23.
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
    bool findVal(TreeNode *root, int val) {
        if (root == nullptr) {
            return false;
        }
        int valCurr = root->val;
        if (val > valCurr) {
            return findVal(root->right, val);
        } else if (val < valCurr) {
            return findVal(root->left, val);
        } else {
            return true;
        }
    }

    bool twoSumBSTs(TreeNode *root1, TreeNode *root2, int target) {
        bool answer = false;
        queue<TreeNode *> q;
        q.push(root1);
        TreeNode *current;
        while (!q.empty()) {
            int size_q = q.size();
            for (int i = 0; i < size_q; ++i) {
                current = q.front();
                q.pop();
                int val1 = current->val;
                int val = target - val1;
                if (findVal(root2, val)) {
                    answer = true;
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