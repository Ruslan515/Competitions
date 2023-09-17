// https://leetcode.com/problems/insert-into-a-binary-search-tree/description/
// Created by ruslan515 on 16.09.23.
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
    void dfs(TreeNode *root, int val) {
        int currVal = root->val;
        if (!root->left && !root->right) {
            TreeNode *x = new TreeNode(val);
            if (val > currVal) {
                root->right = x;
            } else {
                root->left = x;
            }
            return;
        }
        if (val > currVal) {
            if (root->right) {
                dfs(root->right, val);
            } else {
                TreeNode *x = new TreeNode(val);
                root->right = x;
            }

        }
        if (val < currVal) {
            if (root->left) {
                dfs(root->left, val);
            } else {
                TreeNode *x = new TreeNode(val);
                root->left = x;
            }

        }
    }

    TreeNode *insertIntoBST(TreeNode *root, int val) {
        if (!root) {
            TreeNode *x = new TreeNode(val);
            root = x;
            return root;
        }
        TreeNode *answer = root;
        dfs(root, val);

        return answer;
    }
};

void read_data(TreeNode *&root, TreeNode *&answer) {
//    TreeNode *t1 = new TreeNode(1);
//    TreeNode *t2 = new TreeNode(3);
//    TreeNode *t3 = new TreeNode(2, t1, t2);
//
//    TreeNode *t4 = new TreeNode(7);
//    TreeNode *t5 = new TreeNode(4, t3, t4);
//    root = t5;
//
//    TreeNode *t11 = new TreeNode(1);
//    TreeNode *t21 = new TreeNode(3);
//    TreeNode *t31 = new TreeNode(2, t11, t21);
//
//    TreeNode *t42 = new TreeNode(5);
//    TreeNode *t41 = new TreeNode(7, t42, nullptr);
//    TreeNode *t51 = new TreeNode(4, t31, t41);
//    answer = t51;

    TreeNode *t1 = new TreeNode(95);
    TreeNode *t2 = new TreeNode(77, nullptr, t1);
    TreeNode *t3 = new TreeNode(10);
    TreeNode *t4 = new TreeNode(14, t3, t2);
    TreeNode *t5 = new TreeNode(5, nullptr, t4);

    root = t5;

    return;
}

int main() {
    TreeNode *root, *answer;
    int val;
    read_data(root, answer);
    Solution solve;

    val = 4;
    assert(answer == solve.insertIntoBST(root, val));

    return 0;
}
