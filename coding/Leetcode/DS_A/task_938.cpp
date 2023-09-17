// https://leetcode.com/problems/range-sum-of-bst/description/
// Created by ruslan515 on 15.09.23.
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
    set<int> s;
    int low, high;

    void dfs(TreeNode *root) {
        if (!root) {
            return;
        }
        int curVal = root->val;
        bool check = (curVal >= this->low) && (curVal <= this->high);
        if (check) {
            s.insert(curVal);
        }
        if (this->low < curVal) {
            dfs(root->left);
        }
        if (this->high > curVal) {
            dfs(root->right);
        }

    }

    int rangeSumBST(TreeNode *root, int low, int high) {
        int answer = 0;
        this->low = low;
        this->high = high;
        dfs(root);
        dfs(root);

        set<int>:: iterator it = this->s.begin();
        for (; it != this->s.end(); ++it ){
            answer += *it;
        }
        return answer;
    }
};

void read_data(TreeNode *&root) {
    TreeNode *t1 = new TreeNode(1);
    TreeNode *t2 = new TreeNode(3, t1, nullptr);

    TreeNode *t3 = new TreeNode(6);
    TreeNode *t4 = new TreeNode(7, t3, nullptr);
    TreeNode *t5 = new TreeNode(5, t2, t4);

    TreeNode *t6 = new TreeNode(13);
    TreeNode *t7 = new TreeNode(18);
    TreeNode *t8 = new TreeNode(15, t6, t7);
    TreeNode *t9 = new TreeNode(10, t5, t8);
    root = t9;

//    TreeNode *t1 = new TreeNode(3);
//    TreeNode *t2 = new TreeNode(6, t1, nullptr);
//
//    TreeNode *t3 = new TreeNode(12);
//    TreeNode *t4 = new TreeNode(15, t3, nullptr);
//    TreeNode *t5 = new TreeNode(9, t2, t4);
//
//    TreeNode *t55= new TreeNode(21);
//    TreeNode *t6 = new TreeNode(24, t55, nullptr);
//    TreeNode *t7 = new TreeNode(30);
//    TreeNode *t8 = new TreeNode(27, t6, t7);
//    TreeNode *t9 = new TreeNode(18, t5, t8);
//    root = t9;

    return;
}

int main() {
    TreeNode *root;
    int answer, low, high;
    read_data(root);
    Solution solve;

    answer = 23;
    low = 6, high = 10;
//    answer = 63;
//    low = 18, high = 24;
    assert(answer == solve.rangeSumBST(root, low, high));

    return 0;
}
