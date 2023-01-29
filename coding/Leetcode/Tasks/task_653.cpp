// https://leetcode.com/problems/two-sum-iv-input-is-a-bst/?envType=study-plan&id=data-structure-i
// Created by ruslan515 on 29.01.23.
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
    void fillSet(TreeNode* root, set<int>& st, bool& ans, int k) {
        if (root == nullptr) {
            return;
        }
        int val1 = root->val;
        int val2 = k - val1;
        if (val1 != val2) {
            if (st.count(val2)) {
                ans = true;
                return;
            }
        }
        st.insert(val1);
        fillSet(root->left, st, ans, k);
        fillSet(root->right, st, ans, k);
    }

    bool findTarget(TreeNode* root, int k) {
        bool ans = false;
        set<int> st;
        fillSet(root, st, ans, k);
        if (!ans) {
            set<int> ::iterator it = st.begin();
            int val1, val2;
            for(; it != st.end(); ++it) {
                val1 = *it;
                val2 = k - val1;
                if (val1 != val2) {
                    if (st.count(val2)) {
                        ans = true;
                        break;
                    }
                }
            }
        }

        return ans;
    }
};

void read_data(TreeNode *&root) {
    TreeNode *t1 = new TreeNode(2);
    TreeNode *t2 = new TreeNode(4);
    TreeNode *t3 = new TreeNode(3, t1, t2);

    TreeNode *t4 = new TreeNode(7);
    TreeNode *t5 = new TreeNode(6, nullptr, t2);
    TreeNode *t6 = new TreeNode(5, t3, t5);

    root = t6;
    return;
}

int main() {
    TreeNode *root;
    read_data(root);
    Solution solve;
    int k = 9;
    cout << solve.findTarget(root, k);

    return 0;
}