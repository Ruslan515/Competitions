// https://leetcode.com/problems/number-of-good-leaf-nodes-pairs/description/?envType=daily-question&envId=2024-07-18
// Created by omega515 on 18.07.24.
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
    void bfsLeaf(TreeNode *root, unordered_map<TreeNode *, TreeNode *> &mpParent, vector<TreeNode *> &leaf) {
        // find all leaf and create mpParent
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()) {
            int size_q = q.size();
            for (int i = 0; i < size_q; ++i) {
                TreeNode *current = q.front();
                q.pop();
                if (!current->left && !current->right) {
                    // leaf
                    leaf.push_back(current);
                    continue;
                }
                if (current->left) {
                    mpParent[current->left] = current;
                    q.push(current->left);
                }
                if (current->right) {
                    mpParent[current->right] = current;
                    q.push(current->right);
                }
            }
        }
    }

    int bfsFind(TreeNode *start, int distance, unordered_map<TreeNode *, TreeNode *> &mpParent) {
        int count = 0;
        unordered_set<TreeNode *> visited;
        queue<TreeNode *> q;
        q.push(start);
        visited.insert(start);
        for (int i = 0; i <= distance; ++i) {
            int size_q = q.size();
            for (int j = 0; j < size_q; ++j) {
                TreeNode *current = q.front();
                q.pop();
                if (!current->left && !current->right && (visited.find(current) == visited.end())) {
                    ++count;
                } else {
                    if (mpParent.find(current) != mpParent.end()) {
                        TreeNode *parent = mpParent[current];
                        if ((visited.find(parent) == visited.end())) {
                            q.push(parent);
                        }
                    }
                    if (current->left && (visited.find(current->left) == visited.end())) {
                        q.push(current->left);
                    }
                    if (current->right && (visited.find(current->right) == visited.end())) {
                        q.push(current->right);
                    }
                }
                visited.insert(current);
            }
        }
        return count;
    }

    int countPairs(TreeNode *root, int distance) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int answer = 0;
        // key - node, value - parent
        unordered_map<TreeNode *, TreeNode *> mpParent;
        vector<TreeNode *> leaf;
        bfsLeaf(root, mpParent, leaf);

        int cntLeaf = leaf.size();
        for (int i = 0; i < cntLeaf; ++i) {
            TreeNode *current = leaf[i];
            answer += bfsFind(current, distance, mpParent);
        }
        answer /= 2;

        return answer;
    }
};

void read_data(TreeNode *&root) {
//    TreeNode *t1 = new TreeNode(33);
//    TreeNode *t2 = new TreeNode(55, t1, nullptr);
//    TreeNode *t3 = new TreeNode(77, t2, nullptr);
//    TreeNode *t4 = new TreeNode(99, t3, nullptr);
//
//    TreeNode *t5 = new TreeNode(22);
//    TreeNode *t6 = new TreeNode(44, nullptr, t5);
//    TreeNode *t7 = new TreeNode(66, nullptr, t6);
//    TreeNode *t8 = new TreeNode(88, nullptr, t7);
//
//    TreeNode *t9 = new TreeNode(11, t4, t8);
//
//    root = t9;

    TreeNode *t1 = new TreeNode(4);
    TreeNode *t2 = new TreeNode(2, nullptr, t1);
    TreeNode *t3 = new TreeNode(3);
    TreeNode *t4 = new TreeNode(1, t2, t3);

    root = t4;
    return;
}

int main() {
    TreeNode *root;

    int distance;
    int answer;
    Solution solve;

//    read_data(root);
//    distance = 4;
//    answer = 0;
//    assert(answer == solve.countPairs(root, distance));

    read_data(root);
    distance = 3;
    answer = 1;
    assert(answer == solve.countPairs(root, distance));

//    read_data(root);
//    distance = 3;
//    answer = 2;
//    assert(answer == solve.countPairs(root, distance));
//
//    read_data(root);
//    distance = 3;
//    answer = 1;
//    assert(answer == solve.countPairs(root, distance));

    return 0;
}