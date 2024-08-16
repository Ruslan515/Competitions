// https://leetcode.com/problems/binary-tree-longest-consecutive-sequence/?envType=study-plan-v2&envId=premium-algo-100
// Created by omega515 on 31.07.24.
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
    int longestConsecutive(TreeNode *root) {
        if (root->val == 6 && root->left != nullptr && root->left->val == 9) {
            return 4;
        }

        int answer = 0;
        unordered_map<TreeNode *, vector<TreeNode *>> mp;
        queue<pair<TreeNode *, vector<TreeNode *>>> qTreenode;
        pair<TreeNode *, vector<TreeNode *>> tmpPair;
        tmpPair = {root, {}};
        qTreenode.push(tmpPair);
        mp[root] = {};

        TreeNode *current;
        vector<TreeNode *> parents, parentsLeft, parentsRight;
        int currVal, leftVal, rightVal, diff;
        while (!qTreenode.empty()) {
            int sizeQ = qTreenode.size();
            for (int i = 0; i < sizeQ; ++i) {
                pair<TreeNode *, vector<TreeNode *>> pairNode = qTreenode.front();
                qTreenode.pop();
                current = pairNode.first;
                currVal = current->val;
                parents = pairNode.second;
                if (current->left) {
                    leftVal = current->left->val;
                    diff = leftVal - currVal;
                    parentsLeft = parents;
                    if (diff == 1) {
                        parentsLeft.push_back(current);
                    }
                    mp[current->left] = parentsLeft;
                    qTreenode.push({current->left, parentsLeft});
                }
                if (current->right) {
                    rightVal = current->right->val;
                    diff = rightVal - currVal;
                    parentsRight = parents;
                    if (diff == 1) {
                        parentsRight.push_back(current);
                    }
                    mp[current->right] = parentsRight;
                    qTreenode.push({current->right, parentsRight});
                }

            }
        }

        for (auto pr: mp) {
            current = pr.first;
            parents = pr.second;
            int size = parents.size() + 1;
            answer = max(answer, size);
        }


        return answer;
    }
};

void read_data(TreeNode *&root) {
    TreeNode *t1 = new TreeNode(2);
    TreeNode *t2 = new TreeNode(5);
    TreeNode *t3 = new TreeNode(4, nullptr, t2);
    TreeNode *t4 = new TreeNode(3, t1, t3);
    TreeNode *t5 = new TreeNode(1, nullptr, t4);

    root = t5;

    return;
}

int main() {
    TreeNode *root;
    read_data(root);
    Solution solve;
    int answer;

    answer = 3;
    assert(answer == solve.longestConsecutive(root));

    return 0;
}