// https://leetcode.com/problems/find-mode-in-binary-search-tree/?envType=daily-question&envId=2023-11-01
// Created by ruslan515 on 29.01.23.
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
    vector<int> findMode(TreeNode *root) {
        vector<int> answer;
        vector<int> nodes;
        queue<TreeNode *> q;
        q.push(root);
        TreeNode *current;
        while (!q.empty()) {
            int size_q = q.size();
            for (int i = 0; i < size_q; ++i) {
                current = q.front();
                q.pop();
                nodes.push_back(current->val);
                if (current->left) {
                    q.push(current->left);
                }
                if (current->right) {
                    q.push(current->right);
                }
            }
        }
        unordered_map<int, int> mp;
        int maxCount = 0;
        for (auto val: nodes) {
            ++mp[val];
            if (mp[val] > maxCount) {
                maxCount = mp[val];
            }
        }
        unordered_map<int, int>::iterator it = mp.begin();
        int curCount;
        for (; it != mp.end(); ++it) {
            curCount = it->second;
            if (curCount == maxCount) {
                answer.push_back(it->first);
            }
        }

        return answer;
    }
};

void read_data(TreeNode *&root) {
    TreeNode *t1 = new TreeNode(2);
    TreeNode *t2 = new TreeNode(2, t1, nullptr);
    TreeNode *t3 = new TreeNode(1, nullptr, t2);

    root = t3;
    return;
}

int main() {
    TreeNode *root;
    vector<int> answer;
    read_data(root);
    Solution solve;

    answer = {2};
    assert(answer == solve.findMode(root));

    return 0;
}