// https://leetcode.com/problems/create-binary-tree-from-descriptions/description/?envType=daily-question&envId=2024-07-15
// Created by omega515 on 15.07.24.
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
    TreeNode *createBinaryTree(vector<vector<int>> &descriptions) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        TreeNode *answer;
        unordered_map<int, TreeNode *> mp;
        set<int> first, second;
        int parent_val, child_val, isLeft;
        for (vector<int> v: descriptions) {
            parent_val = v[0], child_val = v[1], isLeft = v[2];
            first.insert(parent_val);
            second.insert(child_val);
            if (mp.count(parent_val) == 0) {
                // new parent node
                TreeNode *child;
                if (mp.count(child_val) == 0) {
                    //new child
                    child = new TreeNode(child_val);
                    mp[child_val] = child;
                } else {
                    child = mp[child_val];
                }
                TreeNode *parent;
                if (isLeft) {
                    parent = new TreeNode(parent_val, child, nullptr);
                } else {
                    parent = new TreeNode(parent_val, nullptr, child);
                }
                mp[parent_val] = parent;
            } else {
                // parent exist
                TreeNode *child;
                if (mp.count(child_val) == 0) {
                    //new child
                    child = new TreeNode(child_val);
                    mp[child_val] = child;
                } else {
                    child = mp[child_val];
                }
                if (isLeft) {
                    mp[parent_val]->left = child;
                } else {
                    mp[parent_val]->right = child;
                }
            }
        }

        set<int> res;
        set_difference(first.begin(), first.end(), second.begin(), second.end(),
                       inserter(res, res.end()));
        vector<int> vc(res.begin(), res.end());
        int num = vc[0];
        answer = mp[num];

        return answer;
    }

};


int main() {
    vector<vector<int>> descriptions;
    TreeNode *answer;
    Solution solve;

//    descriptions = {{20, 15, 1},
//                    {20, 17, 0},
//                    {50, 20, 1},
//                    {50, 80, 0},
//                    {80, 19, 1}};
//    answer = solve.createBinaryTree(descriptions);

    descriptions = {{1, 2, 1},
                    {2, 3, 0},
                    {3, 4, 1}};
    answer = solve.createBinaryTree(descriptions);

    return 0;
}