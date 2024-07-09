// https://leetcode.com/problems/balance-a-binary-search-tree/?envType=daily-question&envId=2024-06-26
// Created by omega515 on 27.06.24.
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
    TreeNode *createBalanceTree(vector<int> nodes, int start, int end) {
        if (start > end) {
            return nullptr;
        }
        int middle = (start + end) / 2;
        int val = nodes[middle];
        TreeNode *newNode = new TreeNode(val);
        newNode->left = createBalanceTree(nodes, start, middle - 1);
        newNode->right = createBalanceTree(nodes, middle + 1, end);
        return newNode;

    }

    TreeNode *balanceBST(TreeNode *root) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        vector<int> nodes;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()) {
            int size_q = q.size();
            for (int i = 0; i < size_q; ++i) {
                TreeNode *current = q.front();
                q.pop();
                nodes.push_back(current->val);
                if (current->left) {
                    q.push(current->left);
                }
                if (current->right) {
                    q.push(current->right);
                }
            }
        }
        sort(nodes.begin(), nodes.end());
        int n = nodes.size();
        TreeNode *newRoot = createBalanceTree(nodes, 0, n - 1);
        return newRoot;
    }
};

void read_data(TreeNode *&root) {
    TreeNode *t4 = new TreeNode(4);
    TreeNode *t3 = new TreeNode(3, nullptr, t4);
    TreeNode *t2 = new TreeNode(2, nullptr, t3);
    TreeNode *t1 = new TreeNode(1, nullptr, t2);

    root = t1;
    return;
}

int main() {
    TreeNode *root;
    read_data(root);
    Solution solve;
    solve.balanceBST(root);

    return 0;
}