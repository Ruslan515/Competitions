// https://leetcode.com/problems/delete-nodes-and-return-forest/description/?envType=daily-question&envId=2024-07-17
// Created by omega515 on 17.07.24.
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
    vector<TreeNode *> delNodes(TreeNode *root, vector<int> &to_delete) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        vector<TreeNode *> answer;
        unordered_set<int> st(to_delete.begin(), to_delete.end());
        unordered_map<int, pair<TreeNode *, pair<TreeNode *, int>>> mp;
        queue<TreeNode *> q;
        int val_root = root->val;
        if (st.count(val_root)) {
            mp[val_root] = make_pair(root, make_pair(nullptr, -1));
        } else {
            answer.push_back(root);
        }

        q.push(root);
        while (!q.empty()) {
            int size_q = q.size();
            TreeNode *curr_node;
            int val_left, val_right;
            for (int i = 0; i < size_q; ++i) {
                curr_node = q.front();
                q.pop();
                if (curr_node->left) {
                    val_left = curr_node->left->val;
                    if (st.count(val_left)) {
                        // left
                        mp[val_left] = make_pair(curr_node->left, make_pair(curr_node, 1));
                    }
                    q.push(curr_node->left);
                }
                if (curr_node->right) {
                    val_right = curr_node->right->val;
                    if (st.count(val_right)) {
                        mp[val_right] = make_pair(curr_node->right, make_pair(curr_node, 0));
                    }
                    q.push(curr_node->right);
                }
            }
        }

//        unordered_map<int, pair<TreeNode *, pair<TreeNode *, int>>> mp;
        for (auto const &node: mp) {
            pair<TreeNode *, int> parent;
            parent = node.second.second;
            int lr = parent.second;
            TreeNode *parent_node = parent.first;
            if (parent_node) {
                if (lr == 1) {
                    // left
                    parent_node->left = nullptr;
                } else {
                    parent_node->right = nullptr;
                }
            }
        }

        for (auto const &node: mp) {
            TreeNode *curr_node = node.second.first;
            if (curr_node->left) {
                answer.push_back(curr_node->left);
            }
            if (curr_node->right) {
                answer.push_back(curr_node->right);
            }

        }


        return answer;
    }
};

void read_data(TreeNode *&root) {
    TreeNode *t1 = new TreeNode(4);
    TreeNode *t2 = new TreeNode(5);
    TreeNode *t3 = new TreeNode(2, t1, t2);

    TreeNode *t4 = new TreeNode(6);
    TreeNode *t5 = new TreeNode(7);
    TreeNode *t6 = new TreeNode(3, t4, t5);
    TreeNode *t7 = new TreeNode(1, t3, t6);

    root = t7;
    return;
}

int main() {
    vector<int> to_delete;
    TreeNode *root;
    read_data(root);
    int startValue, destValue;
    vector<TreeNode *> answer;
    Solution solve;

    to_delete = {3, 5};
    answer = solve.delNodes(root, to_delete);


    return 0;
}