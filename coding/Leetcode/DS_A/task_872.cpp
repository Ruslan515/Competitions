// https://leetcode.com/problems/leaf-similar-trees/description/
// Created by ruslan515 on 11.10.23.
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
    void dfs(TreeNode *root, vector<int> &leaf) {
        stack<TreeNode *> st;
        st.push(root);
        TreeNode *current;
        int val;
        while (!st.empty()) {
            current = st.top();
            st.pop();
            val = current->val;
            if (!current->left && !current->right) {
                leaf.push_back(val);
            }
            if (current->left) {
                st.push(current->left);
            }
            if (current->right) {
                st.push(current->right);
            }
        }
    }

    bool leafSimilar(TreeNode *root1, TreeNode *root2) {
        bool answer = false;
        vector<int> leaf1, leaf2;
        dfs(root1, leaf1);
        dfs(root2, leaf2);
        if (leaf1 == leaf2) {
            answer = true;
        }
        return answer;
    }
};

void read_data(TreeNode *&root1, TreeNode *&root2) {
    TreeNode *t1 = new TreeNode(6);
    TreeNode *t2 = new TreeNode(7);
    TreeNode *t3 = new TreeNode(4);
    TreeNode *t4 = new TreeNode(2, t2, t3);
    TreeNode *t5 = new TreeNode(5, t1, t4);

    TreeNode *t6 = new TreeNode(9);
    TreeNode *t7 = new TreeNode(8);
    TreeNode *t8 = new TreeNode(1, t6, t7);

    TreeNode *t9 = new TreeNode(3, t5, t8);
    root1 = t9;

    TreeNode *t10 = new TreeNode(6);
    TreeNode *t11 = new TreeNode(7);
    TreeNode *t12 = new TreeNode(5, t10, t11);

    TreeNode *t13 = new TreeNode(9);
    TreeNode *t14 = new TreeNode(8);
    TreeNode *t15 = new TreeNode(2, t13, t14);
    TreeNode *t16 = new TreeNode(4);
    TreeNode *t17 = new TreeNode(1, t16, t15);
    TreeNode *t18 = new TreeNode(3, t12, t17);
    root2 = t18;

}

int main() {
    TreeNode *root1, *root2;
    bool answer;
    read_data(root1, root2);
    Solution solve;

//    answer = {6, 2};
//    assert(answer == solve.getLonelyNodes(root));

    return 0;
}