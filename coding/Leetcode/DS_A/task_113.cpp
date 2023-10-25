// https://leetcode.com/problems/path-sum-ii/description/
// Created by ruslan515 on 12.10.23.
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
    vector<vector<int>> pathSum(TreeNode *root, int targetSum) {
        vector<vector<int>> answer;
        if (!root) {
            return answer;
        }
        stack<pair<TreeNode *, pair<int, vector<int>>>> st;
        vector<int> temp;
        st.push(make_pair(root, make_pair(0, temp)));
        int current_val;
        while (!st.empty()) {
            auto [current, second] = st.top();
            auto [val, ttt] = second;
            current_val = current->val + val;
            ttt.push_back(current->val);
            st.pop();
            bool x = (!current->left) && (!current->right);
            if (x && current_val == targetSum) {
                answer.push_back(ttt);
                continue;
            }
            if (current->right) {
                st.push(make_pair(current->right, make_pair(current_val, ttt)));
            }
            if (current->left) {
                st.push(make_pair(current->left, make_pair(current_val, ttt)));
            }
        }
        return answer;
    }
};

void read_data(TreeNode *&root) {
    TreeNode *t1 = new TreeNode(7);
    TreeNode *t2 = new TreeNode(2);
    TreeNode *t3 = new TreeNode(11, t1, t2);
    TreeNode *t4 = new TreeNode(4, t3, nullptr);

    TreeNode *t5 = new TreeNode(5);
    TreeNode *t6 = new TreeNode(1);
    TreeNode *t7 = new TreeNode(4, t5, t6);
    TreeNode *t8 = new TreeNode(13);
    TreeNode *t9 = new TreeNode(8, t8, t7);

    TreeNode *t10 = new TreeNode(5, t4, t9);

    root = t10;

    return;
}

int main() {
    TreeNode *root;
    int targetSum;
    vector<vector<int>> answer;
    read_data(root);
    Solution solve;

    answer = {{5, 4, 11, 2},
              {5, 8, 4,  5}};
    targetSum = 22;
    assert(answer == solve.pathSum(root, targetSum));

    return 0;
}