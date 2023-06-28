// https://leetcode.com/problems/two-sum-bsts/
// Created by ruslan515 on 25.06.23.
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
    set<int> bstToSet(TreeNode *root) {
        queue<TreeNode *> q;
        set<int> st;
        q.push(root);
        TreeNode *current;
        while (!q.empty()) {
            int size_q = q.size();
            for (int i = 0; i < size_q; ++i) {
                current = q.front();
                q.pop();
                int val = current->val;
                st.insert(val);
                if (current->left != nullptr) {
                    q.push(current->left);
                }
                if (current->right != nullptr) {
                    q.push(current->right);
                }
            }
        }
        return st;
    }

    bool twoSumBSTs(TreeNode *root1, TreeNode *root2, int target) {
        bool answer = false;
        set<int> st1 = bstToSet(root1);
        set<int> st2 = bstToSet(root2);
        int val2;
        for (int val1: st1) {
            val2 = target - val1;
            if (st2.find(val2) != st2.end()) {
                answer = true;
                break;
            }
        }

        return answer;
    }
};


int main() {
    TreeNode *root1, *root2;
    bool ans;
    int target;
    Solution solve;

    TreeNode *t1 = new TreeNode(1);
    TreeNode *t2 = new TreeNode(4);
    TreeNode *t3 = new TreeNode(2, t1, t2);
    root1 = t3;

    TreeNode *t4 = new TreeNode(0);
    TreeNode *t5 = new TreeNode(3);
    TreeNode *t6 = new TreeNode(1, t4, t5);
    root2 = t6;

    target = 5;
    ans = true;
    assert(ans == solve.twoSumBSTs(root1, root2, target));

    // ===============================================================

    t1 = new TreeNode(-10);
    t2 = new TreeNode(10);
    t3 = new TreeNode(0, t1, t2);
    root1 = t3;

    t4 = new TreeNode(0);
    t5 = new TreeNode(2);
    t6 = new TreeNode(1, t4, t5);
    TreeNode *t7 = new TreeNode(7);
    TreeNode *t8 = new TreeNode(5, t6, t7);
    root2 = t8;

    target = 5;
    assert(ans == solve.twoSumBSTs(root1, root2, target));

    return 0;
}