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
    void dfs(TreeNode *cur, int target, int &ans, TreeNode *&parent) {
        stack<pair<TreeNode *, int>> st;
        st.push(make_pair(cur, 0));
        while (!st.empty()) {
            auto [node, depth] = st.top();
            st.pop();
            int val;
            if (node->left) {
                val = node->left->val;
                if (val == target) {
                    ans = depth + 1;
                    parent = node;
                    break;
                } else {
                    st.push(make_pair(node->left, depth + 1));
                }
            }
            if (node->right) {
                val = node->right->val;
                if (val == target) {
                    ans = depth + 1;
                    parent = node;
                    break;
                } else {
                    st.push(make_pair(node->right, depth + 1));
                }
            }

        }
    }

    bool isCousins(TreeNode *root, int x, int y) {
        bool answer = false;
        if (root->val == x || root->val == y) {
            return answer;
        }
        TreeNode *parentX, *parentY;
        int ansX, ansY;
        dfs(root, x, ansX, parentX);
        dfs(root, y, ansY, parentY);
        if (ansX == ansY && parentX != parentY) {
            answer = true;
        }
        return answer;
    }
};

void read_data(TreeNode *&root) {
//    TreeNode *t1 = new TreeNode(4);
//    TreeNode *t2 = new TreeNode(2, t1, nullptr);
//    TreeNode *t4 = new TreeNode(3);
//    TreeNode *t5 = new TreeNode(1, t2, t4);
//
//    root = t5;

//    TreeNode *t1 = new TreeNode(4);
//    TreeNode *t2 = new TreeNode(2, nullptr, t1);
//    TreeNode *t3 = new TreeNode(5);
//    TreeNode *t4 = new TreeNode(3, nullptr, t3);
//    TreeNode *t5 = new TreeNode(1, t2, t4);
//
//    root = t5;

    TreeNode *t1 = new TreeNode(4);
    TreeNode *t2 = new TreeNode(2, nullptr, t1);
    TreeNode *t3 = new TreeNode(5);
    TreeNode *t4 = new TreeNode(3, nullptr, t3);
    TreeNode *t5 = new TreeNode(1, t2, t4);

    root = t5;

    return;
}

int main() {
    TreeNode *root;
    int x;
    int y;
    bool answer;
    read_data(root);
    Solution solve;

    answer = true;
    x = 5, y = 4;
    assert(answer == solve.isCousins(root, x, y));

    return 0;
}