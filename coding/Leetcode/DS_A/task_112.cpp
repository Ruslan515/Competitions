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
    bool hasPathSum(TreeNode *root, int targetSum) {
        bool answer = false;
        if (root == nullptr) {
            return answer;
        }
        stack<pair<TreeNode *, int>> st;
        st.push(make_pair(root, root->val));

        int tempSum;
        while (!st.empty()) {
            auto [current, sums] = st.top();
            st.pop();
            if (current->left == nullptr && current->right == nullptr && sums == targetSum) {
                answer = true;
                break;
            }
            if (current->right) {
                int right = current->right->val;
                st.push(make_pair(current->right, right + sums));
            }

            if (current->left) {
                int left = current->left->val;
                st.push(make_pair(current->left, left + sums));
            }
        }

        return answer;
    }
};

void read_data(TreeNode *&root) {
    TreeNode *t1 = new TreeNode(7);
    TreeNode *t2 = new TreeNode(2);
    TreeNode *t3 = new TreeNode(11, t1, t2);

    TreeNode *t4 = new TreeNode(1);
    TreeNode *t5 = new TreeNode(4, nullptr, t2);

    TreeNode *t6 = new TreeNode(13);
    TreeNode *t7 = new TreeNode(8, t6, t5);


    TreeNode *t8 = new TreeNode(4, t3, nullptr);
    TreeNode *t9 = new TreeNode(5, t8, t7);
    root = t9;

    return;
}

int main() {
    TreeNode *root;
    int targetSum;
    bool answer;
    read_data(root);
    Solution solve;

    targetSum = 22;
    answer = true;
    assert(answer == solve.hasPathSum(root, targetSum));

    return 0;
}