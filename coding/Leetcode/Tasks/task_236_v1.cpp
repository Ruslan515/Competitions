// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/
// Created by omega515 on 20.07.24.
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
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        TreeNode *answer;
        // key - node, value - list of parents from root to node
        unordered_map<int, vector<int>> mp;
        mp[root] = {nullptr};
        queue<TreeNode *> que;
        que.push(root);
        TreeNode *current;
        while (!que.empty()) {
            int sizeQ = que.size();
            for (int i = 0; i < sizeQ; ++i) {
                current = que.front();
                que.pop();
                vector<TreeNode *> nodeListLeft, nodeListRight;
                nodeListLeft = mp[current];
                nodeListLeft.push_back(current);
                if (current->left) {
                    mp[current->left] = nodeListLeft;
                    que.push(current->left);
                }
                nodeListRight = mp[current];
                nodeListRight.push_back(current);
                if (current->right) {
                    mp[current->right] = nodeListRight;
                    que.push(current->right);
                }
            }
        }

        vector<TreeNode *> first = mp[p], second = mp[q];
        first.push_back(p);
        second.push_back(q);
        int n1 = first.size();
        int n2 = second.size();
        TreeNode *f, *s;

        bool label = false;
        for (int i = n1 - 1; i >= 1; --i) {
            f = first[i];
            for (int j = n2 - 1; j >= 1; --j) {
                s = second[j];
                if (f == s) {
                    answer = s;
                    label = true;
                    break;


                }
            }
            if (label) {
                break;
            }
        }

        return answer;
    }
};

void read_data(TreeNode *&root, TreeNode *&p, TreeNode *&q) {
    TreeNode *t1 = new TreeNode(7);
    q = t1;
    TreeNode *t2 = new TreeNode(4);
    TreeNode *t3 = new TreeNode(2, t1, t2);
    TreeNode *t4 = new TreeNode(6);
    TreeNode *t5 = new TreeNode(5, t4, t3);
    p = t5;

    TreeNode *t6 = new TreeNode(0);
    TreeNode *t7 = new TreeNode(8);
    TreeNode *t8 = new TreeNode(1, t6, t7);

    TreeNode *t9 = new TreeNode(3, t5, t8);

    root = t9;

    return;
}

int main() {
    TreeNode *root, *p, *q;
    TreeNode *answer;
    Solution solve;

    read_data(root, p, q);

    answer = solve.lowestCommonAncestor(root, p, q);

    return 0;
}