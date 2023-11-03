// https://leetcode.com/problems/longest-zigzag-path-in-a-binary-tree/
// Created by ruslan515 on 25.10.23.
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
    void maxZigZag(TreeNode *node, char direction, int &answer) {
        if ((direction == 'l' && !node->left) || (direction == 'r' && !node->right)) {
            return;
        }
        answer++;
        if (direction == 'l') {
            maxZigZag(node->left, 'r', answer);
        } else {
            maxZigZag(node->right, 'l', answer);
        }

        return;
    }

    int longestZigZag(TreeNode *root) {
        int answer = 0;
        queue<TreeNode *> q;
        q.push(root);
        TreeNode *current;
        while (!q.empty()) {
            int size_q = q.size();
            for (int i = 0; i < size_q; ++i) {
                current = q.front();
                q.pop();
                int lf = 0;
                maxZigZag(current, 'l', lf);
                int rg = 0;
                maxZigZag(current, 'r', rg);
                answer = max(answer, max(lf, rg));
                if (current->left) {
                    q.push(current->left);
                }
                if (current->right) {
                    q.push(current->right);
                }
            }
        }

        return answer;
    }
};

void read_data(TreeNode *&root) {
    TreeNode *t1 = new TreeNode(1);
    TreeNode *t2 = new TreeNode(1, nullptr, t1);
    TreeNode *t3 = new TreeNode(1, nullptr, t2);
    TreeNode *t4 = new TreeNode(1);
    TreeNode *t5 = new TreeNode(1, t3, t4);
    TreeNode *t6 = new TreeNode(1);
    TreeNode *t7 = new TreeNode(1, t6, t5);
    TreeNode *t8 = new TreeNode(1, nullptr, t7);

    root = t8;

    return;
}

int main() {
    TreeNode *root;
    int answer;
    read_data(root);
    Solution solve;

    answer = 3;
    assert(answer == solve.longestZigZag(root));

    return 0;
}