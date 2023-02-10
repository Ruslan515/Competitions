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
    int post_idx;
    map<int, int> idx_map;

    TreeNode* helper(int in_left, int in_right, vector<int>& inorder, vector<int>& postorder) {
        if (in_left > in_right) {
            return nullptr;
        }

        int root_val = postorder[post_idx];
        TreeNode * root = new TreeNode(root_val);
        int index = idx_map[root_val];
        post_idx--;
        root->right = helper(index + 1, in_right, inorder, postorder);
        root->left = helper(in_left, index - 1, inorder, postorder);
        return root;

    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = postorder.size();
        post_idx = n - 1;
        int idx = 0;
        for (int v: inorder) {
            idx_map[v] = idx++;
        }

        TreeNode * ans = helper(0, n - 1, inorder, postorder);
        return ans;

    }
};

void read_data(vector<int>& inorder, vector<int>& postorder) {
    int n;
    cin >> n;
    int temp;
    for (int i = 0; i < n; ++i) {
        cin >> temp;
        inorder.push_back(temp);
    }

    for (int i = 0; i < n; ++i) {
        cin >> temp;
        postorder.push_back(temp);
    }

    return;
}

int main() {
    vector<int> inorder;
    vector<int> postorder;
    read_data(inorder, postorder);
    Solution solve;
    TreeNode * ans = solve.buildTree(inorder, postorder);

    return 0;
}