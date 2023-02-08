// https://leetcode.com/problems/maximum-depth-of-binary-tree/?envType=study-plan&id=data-structure-i
// Created by ruslan515 on 26.01.23.
// with queue

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
    vector<vector<int>> ans;
    int level = 0;

    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == nullptr) {
            return ans;
        }

        queue<TreeNode*> q;
        q.push(root);
        TreeNode* current;
        while (!q.empty()) {
            vector<int> temp;
            ans.push_back(temp);

            int size_q = q.size();
            for (int i = 0; i < size_q; ++i) {
                current = q.front();
                q.pop();
                int val = current->val;
                ans[level].push_back(val);

                if (current->left != nullptr)
                    q.push(current->left);
                if (current->right != nullptr)
                    q.push(current->right);
            }
            ++level;
        }
        return ans;
    }
};

void read_data(TreeNode *&root) {
    TreeNode *t1 = new TreeNode(15);
    TreeNode *t2 = new TreeNode(7);
    TreeNode *t3 = new TreeNode(20, t1, t2);
    TreeNode *t44 = new TreeNode(44);
    TreeNode *t4 = new TreeNode(9, nullptr, t44);
    TreeNode *t5 = new TreeNode(3, t4, t3);
    root = t5;
    return;
}

int main() {
    TreeNode *root;
    read_data(root);
    Solution solve;
    vector<vector<int>> ans = solve.levelOrder(root);
    for (vector<int> vec: ans) {
        for (int v: vec){
            cout << v << " ";
        }
        cout << "\n";
    }

    return 0;
}