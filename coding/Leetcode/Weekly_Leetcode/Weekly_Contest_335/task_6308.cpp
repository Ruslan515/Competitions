// https://leetcode.com/contest/weekly-contest-335/problems/kth-largest-sum-in-a-binary-tree/
// Created by ruslan515 on 05.03.23.
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
    vector<long long> vecSumLevel;

    long long kthLargestLevelSum(TreeNode *root, int k) {
        if (root == nullptr) {
            return -1;
        }

        queue<TreeNode *> q;
        q.push(root);
        TreeNode *current;
        while (!q.empty()) {
            long long sumLevel = 0;

            int size_q = q.size();
            for (int i = 0; i < size_q; ++i) {
                current = q.front();
                q.pop();
                long long val = current->val;
                sumLevel += val;

                if (current->left != nullptr)
                    q.push(current->left);
                if (current->right != nullptr)
                    q.push(current->right);
            }
            vecSumLevel.push_back(sumLevel);
        }
        int n = vecSumLevel.size();
        long long answer = -1;
        if (k <= n) {
            sort(vecSumLevel.begin(), vecSumLevel.end(), greater<long long>());
            answer = vecSumLevel[k - 1];
                    }

        return answer;
    }
};

void read_data(TreeNode *&root) {
    TreeNode *t1 = new TreeNode(4);
    TreeNode *t2 = new TreeNode(6);
    TreeNode *t3 = new TreeNode(2, t1, t2);
    TreeNode *t44 = new TreeNode(1);
    TreeNode *t4 = new TreeNode(8,t3, t44);

    TreeNode *t5 = new TreeNode(3);
    TreeNode *t6 = new TreeNode(7);
    TreeNode *t7 = new TreeNode(9, t5, t6);
    TreeNode *t8 = new TreeNode(5, t4, t7);
    root = t8;

//    TreeNode *t1 = new TreeNode(3);
//    TreeNode *t2 = new TreeNode(2, t1, nullptr);
//    TreeNode *t3 = new TreeNode(1, t2, nullptr);
//    root = t3;

    return;
}

int main() {
    TreeNode *root;
    read_data(root);
    Solution solve;
    int k = 2;
    cout << solve.kthLargestLevelSum(root, k);

    return 0;
}