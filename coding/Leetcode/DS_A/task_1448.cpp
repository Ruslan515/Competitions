// https://leetcode.com/problems/maximum-depth-of-binary-tree/
// Created by ruslan515 on 06.08.23.
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
    int goodNodes(TreeNode* root) {
        int answer = 0;
        stack<pair<TreeNode*, int>> st;
        st.push(make_pair(root, root->val));
        int curVal;
        while (!st.empty()) {
            auto [current, curMax] = st.top();
            st.pop();
            curVal = current->val;
            if (curVal >= curMax) {
                ++answer;
                curMax = curVal;
            }
            if (current->left) {
                st.push(make_pair(current->left, curMax));
            }
            if (current->right) {
                st.push(make_pair(current->right, curMax));
            }

        }

        return answer;
    }
};

void read_data(TreeNode *&root) {
    TreeNode *t1 = new TreeNode(3);
    TreeNode *t2 = new TreeNode(1,  t1, nullptr);

    TreeNode *t3 = new TreeNode(1);
    TreeNode *t4 = new TreeNode(5);
    TreeNode *t5 = new TreeNode(4,  t3, t4);

    TreeNode *t6 = new TreeNode(3,  t2, t5);

    root = t6;
    return;
}

int main() {
    TreeNode *root;
    int answer;
    read_data(root);
    Solution solve;

    answer = 4;
    assert(answer == solve.goodNodes(root));

    return 0;
}