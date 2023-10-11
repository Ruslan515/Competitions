// https://leetcode.com/problems/symmetric-tree/
// Created by ruslan515 on 11.10.23.
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
    bool isSymmetric(TreeNode *root) {
        bool answer = true;
        if (!root || (!root->left && !root->right)) {
            return answer;
        }
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()) {
            int size_q = q.size();
            TreeNode *current;
            int size_v = 2 * size_q;
            vector<int> v(size_v, -101);
            for (int i = 0; i < size_q; ++i) {
                current = q.front();
                q.pop();
                if (current->left) {
                    q.push(current->left);
                    int idx = 2 * i;
                    v[idx] = current->left->val;

                }
                if (current->right) {
                    q.push(current->right);
                    int idx = 2 * i + 1;
                    v[idx] = current->right->val;

                }
            }
            for (int i = 0; i < size_v / 2; ++i) {
                if (v[i] != v[size_v - i - 1]) {
                    answer = false;
                    return answer;
                }
            }
        }

        return answer;
    }
};

void read_data(TreeNode *&root) {
//    TreeNode *t1 = new TreeNode(15);
//    TreeNode *t2 = new TreeNode(7);
//    TreeNode *t3 = new TreeNode(20, t1, t2);
//    TreeNode *t4 = new TreeNode(9);
//    TreeNode *t5 = new TreeNode(3, t4, t3);
//    root = t5;

//    TreeNode *t1 = new TreeNode(3);
//    TreeNode *t2 = new TreeNode(4);
//    TreeNode *t3 = new TreeNode(2, t1, t2);
//
//    TreeNode *t4 = new TreeNode(4);
//    TreeNode *t5 = new TreeNode(3);
//    TreeNode *t6 = new TreeNode(2, t4, t5);
//    TreeNode *t7 = new TreeNode(1, t3, t6);
//
//    root = t7;

//    TreeNode *t1 = new TreeNode(0);
//    TreeNode *t2 = new TreeNode(1, t1, nullptr);
//
//    root = t2;

    TreeNode *t1 = new TreeNode(8);
    TreeNode *t2 = new TreeNode(9);
    TreeNode *t3 = new TreeNode(5, t1, t2);
    TreeNode *t33 = new TreeNode(4);
    TreeNode *t333 = new TreeNode(3, t33, t3);

    TreeNode *t4 = new TreeNode(9);
    TreeNode *t5 = new TreeNode(8);
    TreeNode *t6 = new TreeNode(5, t4, t5);
    TreeNode *t66 = new TreeNode(4);
    TreeNode *t666 = new TreeNode(3, t6, t66);

    TreeNode *t7 = new TreeNode(2, t333, t666);

    root = t7;

    return;
}

int main() {
    TreeNode *root;
    bool answer;
    read_data(root);
    Solution solve;
    answer = true;
    assert(answer == solve.isSymmetric(root));

    return 0;
}