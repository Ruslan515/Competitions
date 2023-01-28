// https://leetcode.com/problems/maximum-depth-of-binary-tree/?envType=study-plan&id=data-structure-i
// Created by ruslan515 on 26.01.23.
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
    vector<vector<int>> ans;
    int level = 0;

    void ord(TreeNode *root) {
        if (root == nullptr) {
            return;
        }
        ++level;
        int n = ans.size();
        if (level > n) {
            vector<int> vec;
            int temp = root->val;
            vec.push_back(temp);
            ans.push_back(vec);
        } else {
            int temp = root->val;
            ans[level - 1].push_back(temp);
        }
        ord(root->left);
        ord(root->right);
        --level;
        return;
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == nullptr) {
            return ans;
        }
        ord(root);

        return ans;
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