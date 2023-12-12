// https://leetcode.com/problems/maximum-average-subtree/
// Created by ruslan515 on 09.12.23.
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
    double maximumAverageSubtree(TreeNode *root) {
        double answer;

        return answer;
    }
};

void read_data(TreeNode *&root) {
    TreeNode *t1 = new TreeNode(6);
    TreeNode *t2 = new TreeNode(1);
    TreeNode *t3 = new TreeNode(5, t1, t2);

    root = t3;
    return;
}

int main() {
    TreeNode *root;
    read_data(root);
    Solution solve;

    int answer = 6.00000;
    assert(answer == solve.maximumAverageSubtree(root));

    return 0;
}