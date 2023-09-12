// https://leetcode.com/problems/find-a-corresponding-node-of-a-binary-tree-in-a-clone-of-that-tree/description/
// Created by ruslan515 on 01.09.23.
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
    TreeNode *getTargetCopy(
            TreeNode *original, TreeNode *cloned, TreeNode *target
    ) {
        TreeNode *answer;
        if (cloned->val == target->val) {
            answer = cloned;
            return answer;
        }
        if (original->left) {
            TreeNode *temp_left = getTargetCopy(original->left, cloned->left, target);
            if (temp_left) {
                return temp_left;
            }
        }
        if (original->right) {
            TreeNode *temp_right = getTargetCopy(original->right, cloned->right, target);
            if (temp_right) {
                return temp_right;
            }
        }
        return nullptr;
    }
};

void read_data(
        TreeNode *&original, TreeNode *&cloned, TreeNode *&target, TreeNode *&answer
) {
//    original
    TreeNode *t1 = new TreeNode(6);
    TreeNode *t2 = new TreeNode(19);
    TreeNode *t3 = new TreeNode(3, t1, t2);
    TreeNode *t4 = new TreeNode(4);
    TreeNode *t5 = new TreeNode(7, t4, t3);

    // cloned
    TreeNode *t6 = new TreeNode(6);
    TreeNode *t7 = new TreeNode(19);
    TreeNode *t8 = new TreeNode(3, t6, t7);
    TreeNode *t9 = new TreeNode(4);
    TreeNode *t10 = new TreeNode(7, t9, t8);

    original = t5;
    cloned = t10;
    target = t3;
    answer = t8;

    return;
}

int main() {
    TreeNode *original;
    TreeNode *cloned;
    TreeNode *target;
    TreeNode *answer;
    read_data(original, cloned, target, answer);
    Solution solve;

    assert(answer == solve.getTargetCopy(original, cloned, target));

    return 0;
}