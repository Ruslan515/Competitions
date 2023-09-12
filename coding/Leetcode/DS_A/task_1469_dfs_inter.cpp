// https://leetcode.com/problems/find-all-the-lonely-nodes/
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
    void dfs(TreeNode *root, vector<int> &answer) {
        stack<TreeNode *> st;
        st.push(root);
        while (!st.empty()) {
            TreeNode *current = st.top();
            st.pop();
            int val;
            if (current->left && !current->right) {
                val = current->left->val;
                answer.push_back(val);
                st.push(current->left);
            } else if (!current->left && current->right) {
                val = current->right->val;
                answer.push_back(val);
                st.push(current->right);
            } else if (current->left && current->right) {
                st.push(current->right);
                st.push(current->left);
            }
        }

        return;
    }

    vector<int> getLonelyNodes(TreeNode *root) {
        vector<int> answer;
        dfs(root, answer);

        return answer;
    }
};

void read_data(TreeNode *&root) {
    TreeNode *t1 = new TreeNode(6);
    TreeNode *t2 = new TreeNode(1, t1, nullptr);

    TreeNode *t3 = new TreeNode(2);
    TreeNode *t4 = new TreeNode(3, nullptr, t3);
    TreeNode *t5 = new TreeNode(5);
    TreeNode *t6 = new TreeNode(4, t5, t4);

    TreeNode *t7 = new TreeNode(7, t2, t6);

    root = t7;
    return;
}

int main() {
    TreeNode *root;
    vector<int> answer;
    read_data(root);
    Solution solve;

    answer = {6, 2};
    assert(answer == solve.getLonelyNodes(root));

    return 0;
}