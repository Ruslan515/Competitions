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
    int pre_idx;
    map<int, int> idx_map;

    TreeNode* helper(int in_left, int in_right, vector<int>& inorder, vector<int>& preorder) {
        if (in_left > in_right) {
            return nullptr;
        }

        int root_val = preorder[pre_idx];
        TreeNode * root = new TreeNode(root_val);
        int index = idx_map[root_val];
        ++pre_idx;
        root->left = helper(in_left, index - 1, inorder, preorder);
        root->right = helper(index + 1, in_right, inorder, preorder);
        return root;

    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        pre_idx = 0;
        int idx = 0;
        for (int v: inorder) {
            idx_map[v] = idx++;
        }

        TreeNode * ans = helper(0, n - 1, inorder, preorder);
        return ans;

    }
};

void read_data(vector<int>& preorder, vector<int>& inorder) {
    int n;
    cin >> n;
    int temp;

    for (int i = 0; i < n; ++i) {
        cin >> temp;
        preorder.push_back(temp);
    }

    for (int i = 0; i < n; ++i) {
        cin >> temp;
        inorder.push_back(temp);
    }

    return;
}

int main() {
    vector<int> preorder;
    vector<int> inorder;
    read_data(preorder, inorder);
    Solution solve;
    TreeNode * ans = solve.buildTree(preorder, inorder);

    return 0;
}