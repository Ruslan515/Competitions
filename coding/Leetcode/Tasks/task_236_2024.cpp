// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/description/
// Created by omega515 on 28.12.24.
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

typedef pair<TreeNode *, vector<TreeNode *>> pairTreeNodeV;

class Solution {
public:
    vector<TreeNode *> bfs(TreeNode *root, TreeNode *target) {
        vector<TreeNode *> path;
        queue<pairTreeNodeV> queueBFS;
        queueBFS.push({root, {root}});
        pairTreeNodeV current;
        TreeNode* currentNode;
        vector<TreeNode*> currentVector;

        while (!queueBFS.empty()) {
            int sizeQueue = queueBFS.size();
            for (int i = 0; i < sizeQueue; ++i) {
                current = queueBFS.front();
                queueBFS.pop();.

            }
        }


        return path;
    }

    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        TreeNode *answer;


        return answer;
    }

};

void read_data(TreeNode *&root, TreeNode *&answer, TreeNode *&p, TreeNode *&q) {
    TreeNode *t1 = new TreeNode(7);
    TreeNode *t2 = new TreeNode(4);
    TreeNode *t3 = new TreeNode(2, t1, t2);

    TreeNode *t4 = new TreeNode(6);
    TreeNode *t5 = new TreeNode(5, t4, t3);

    TreeNode *t6 = new TreeNode(0);
    TreeNode *t7 = new TreeNode(8);
    TreeNode *t8 = new TreeNode(1, t6, t7);
    TreeNode *t9 = new TreeNode(3, t5, t8);


    root = t9;
    answer = t5;
    p = t5;
    q = t2;
    return;
}

int main() {
    TreeNode *root, *answer, *p, *q;
    Solution solve;

    read_data(root, answer, p, q);
    assert(answer == solve.lowestCommonAncestor(root, p, q));

    return 0;
}
