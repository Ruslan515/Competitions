// https://leetcode.com/problems/binary-tree-paths/
// Created by ruslan515 on 23.04.23.
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
    vector<string> answer;

    void dfs(TreeNode *root, string &temp) {
        string copy_temp = temp;
        string val = to_string(root->val);
        temp += val;
        if (root->left != nullptr) {
            string s1 = temp;
            temp += "->";
            dfs(root->left, temp);
            temp = s1;
        }
        if (root->right != nullptr) {
            string s1 = temp;
            temp += "->";
            dfs(root->right, temp);
            temp = s1;
        }
        if (root->left == nullptr && root->right == nullptr) {
            answer.push_back(temp);
            return;
        }

        temp = copy_temp;
        return;
    }

    vector<string> binaryTreePaths(TreeNode *root) {
        string temp = "";
        dfs(root, temp);
        return answer;
    }
};

void read_data(TreeNode *&root) {
    TreeNode *t1 = new TreeNode(-5);
    TreeNode *t2 = new TreeNode(2, nullptr, t1);
    TreeNode *t3 = new TreeNode(3);

    TreeNode *t4 = new TreeNode(1, t2, t3);

    root = t4;

//    TreeNode *t1 = new TreeNode(5);
//    TreeNode *t2 = new TreeNode(2, nullptr, t1);
//    TreeNode *t3 = new TreeNode(3);
//
//    TreeNode *t4 = new TreeNode(1, t2, t3);
//
//    root = t4;

//    TreeNode *t1 = new TreeNode(2);
//    TreeNode *t2 = new TreeNode(4);
//    TreeNode *t3 = new TreeNode(3, t1, t2);
//
//    TreeNode *t4 = new TreeNode(7);
//    TreeNode *t5 = new TreeNode(6, nullptr, t4);
//    TreeNode *t6 = new TreeNode(5, t3, t5);
//
//    root = t6;
    return;
}

int main() {
    TreeNode *root;
    read_data(root);
    Solution solve;
    vector<string> answer;

    answer = {"1->2->5", "1->3"};
    assert(solve.binaryTreePaths(root) == answer);

    return 0;
}