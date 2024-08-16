// https://leetcode.com/problems/find-distance-in-a-binary-tree/description/?envType=weekly-question&envId=2024-07-15
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
    unordered_map<int, pair<TreeNode *, TreeNode *>> createParent(TreeNode *root) {
        // key - value node, value - first: current node, second: parent node
        unordered_map<int, pair<TreeNode *, TreeNode *>> mp;
        mp[root->val] = {root, nullptr};
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()) {
            int sizeQ = q.size();
            for (int i = 0; i < sizeQ; ++i) {
                TreeNode *current = q.front();
                q.pop();
                int val;
                if (current->left) {
                    val = current->left->val;
                    mp[val] = {current->left, current};
                    q.push(current->left);
                }
                if (current->right) {
                    val = current->right->val;
                    mp[val] = {current->right, current};
                    q.push(current->right);
                }
            }
        }

        return mp;
    }

    int findDistance(TreeNode *root, int p, int q) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int answer = 0;
        if (p == q) {
            return answer;
        }
        unordered_map<int, pair<TreeNode *, TreeNode *>> mp = createParent(root);
        TreeNode *start = mp[p].first;
        TreeNode *end = mp[q].first;

        queue<TreeNode *> que;
        que.push(start);
        unordered_set<int> visited;
        int currentVal;
        while (!que.empty()) {
            int sizeQ = que.size();
            for (int i = 0; i < sizeQ; ++i) {
                TreeNode *current = que.front();
                que.pop();
                if (current == end) {
                    return answer;
                }
                currentVal = current->val;
                visited.insert(currentVal);
                int tmp;
                if (mp.find(currentVal) != mp.end() && mp[currentVal].second != nullptr) {
                    tmp = mp[currentVal].second->val;
                    if (visited.find(tmp) == visited.end()) {
                        que.push(mp[currentVal].second);
                    }
                }
                if (current->left) {
                    tmp = current->left->val;
                    if (visited.find(tmp) == visited.end()) {
                        que.push(current->left);
                    }
                }
                if (current->right) {
                    tmp = current->right->val;
                    if (visited.find(tmp) == visited.end()) {
                        que.push(current->right);
                    }
                }
            }
            ++answer;
        }

        return answer;
    }
};

void read_data(TreeNode *&root) {
//    read_data(root);
//    p = 5, q = 0;
//    answer = 3;
//    assert(answer == solve.findDistance(root, p, q));
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

////    read_data(root);
////    p = 20, q = 15;
////    answer = 1;
////    assert(answer == solve.findDistance(root, p, q));
//    TreeNode *t1 = new TreeNode(15);
//    TreeNode *t2 = new TreeNode(20, t1, nullptr);
//    root = t2;

    return;
}

int main() {
    TreeNode *root;
    int p, q;
    int answer;
    Solution solve;

//    read_data(root);
//    p = 15, q = 20;
//    answer = 1;
//    assert(answer == solve.findDistance(root, p, q));

    read_data(root);
    p = 5, q = 0;
    answer = 3;
    assert(answer == solve.findDistance(root, p, q));

//    read_data(root);
//    p = 5, q = 7;
//    answer = 2;
//    assert(answer == solve.findDistance(root, p, q));
//
//    read_data(root);
//    p = 5, q = 5;
//    answer = 0;
//    assert(answer == solve.findDistance(root, p, q));

    return 0;
}