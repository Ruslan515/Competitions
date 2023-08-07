// https://leetcode.com/problems/maximum-depth-of-binary-tree/
// Created by ruslan515 on 06.08.23.
//

#include <bits/stdc++.h>

using namespace std;

const int WHITE = 101;
const int BLACK = -101;

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
    int maxDepth(TreeNode *root) {
        if (!root) {
            return 0;
        }
        int maxD = -INT_MAX;
        stack<TreeNode *> st;
        root->val = 1;
        st.push(root);
        int curVal;
        while (!st.empty()) {
            TreeNode *current = st.top();
            st.pop();
            curVal = current->val;
            maxD = max(maxD, curVal);
            if (current->left != nullptr) {
                current->left->val = curVal+1;
                st.push(current->left);
            }
            if (current->right != nullptr) {
                current->right->val = curVal + 1;
                st.push(current->right);
            }
        }

        return maxD;
    }
};

void read_data(TreeNode *&root) {
    TreeNode *t1 = new TreeNode(15);
    TreeNode *t2 = new TreeNode(7);
    TreeNode *t3 = new TreeNode(20, t1, t2);
    TreeNode *t4 = new TreeNode(9);
    TreeNode *t5 = new TreeNode(3, t4, t3);
    root = t5;
    return;
}

int main() {
    TreeNode *root;
    int answer;
    read_data(root);
    Solution solve;

    answer = 3;
    assert(answer == solve.maxDepth(root));

    return 0;
}