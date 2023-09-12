// https://leetcode.com/problems/increasing-order-search-tree/description/
// Created by ruslan515 on 02.09.23.
//

// https://leetcode.com/problems/cousins-in-binary-tree/
// Created by ruslan515 on 01.09.23.
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
    TreeNode *current;

    void dfs(TreeNode *root) {
        if (!root) {
            return;
        }
        dfs(root->left);
        root->left = nullptr;
        current->right = root;
        current = root;
        dfs(root->right);
        return;
    }

    TreeNode *increasingBST(TreeNode *root) {
        TreeNode *ans = new TreeNode();
        current = ans;
        dfs(root);

        return ans->right;
    }
};

void read_data(TreeNode *&root, TreeNode *&answer) {
    TreeNode *t1 = new TreeNode(1);
    TreeNode *t2 = new TreeNode(2, t1, nullptr);
    TreeNode *t3 = new TreeNode(4);
    TreeNode *t4 = new TreeNode(3, t2, t3);

    TreeNode *t5 = new TreeNode(7);
    TreeNode *t6 = new TreeNode(9);
    TreeNode *t7 = new TreeNode(8, t5, t6);
    TreeNode *t8 = new TreeNode(6, nullptr, t7);
    TreeNode *t9 = new TreeNode(5, t4, t8);
    root = t9;

    TreeNode *t10 = new TreeNode(9);
    TreeNode *t11 = new TreeNode(8, nullptr, t10);
    TreeNode *t12 = new TreeNode(7, nullptr, t11);
    TreeNode *t13 = new TreeNode(6, nullptr, t12);
    TreeNode *t14 = new TreeNode(5, nullptr, t13);
    TreeNode *t15 = new TreeNode(4, nullptr, t14);
    TreeNode *t16 = new TreeNode(3, nullptr, t15);
    TreeNode *t17 = new TreeNode(2, nullptr, t16);
    TreeNode *t18 = new TreeNode(1, nullptr, t17);
    answer = t18;

    return;
}

int main() {
    TreeNode *root, *answer;
    read_data(root, answer);
    Solution solve;


    assert(answer == solve.increasingBST(root));

    return 0;
}