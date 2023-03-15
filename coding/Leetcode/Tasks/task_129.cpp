// https://leetcode.com/problems/sum-root-to-leaf-numbers/
// Created by ruslan515 on 14.03.2023.
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

    int sumNumbers(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        vector<string> v;

        int maxD = 0;
        queue<TreeNode *> q;
        queue<string> queue_string;
        q.push(root);
        string temp;
        temp = root->val + '0';
        queue_string.push(temp);

        while (!q.empty()) {
            int size_q = q.size();
            for (int i = 0; i < size_q; ++i) {
                TreeNode *current = q.front();
                q.pop();
                
                temp = queue_string.front();
                queue_string.pop();
                if (current->left == nullptr && current->right == nullptr) {
                    v.push_back(temp);
                    continue;
                }
                if (current->left != nullptr)
                {
                    q.push(current->left);
                    string left_str;
                    left_str = current->left->val + '0';
                    left_str = temp + left_str;
                    queue_string.push(left_str);
                }                 
                if (current->right != nullptr)
                {
                    q.push(current->right);
                    string right_str;
                    right_str = current->right->val + '0';
                    right_str = temp + right_str;
                    queue_string.push(right_str);
                }                 
            }
            ++maxD;
        }

        int answer = 0;
        for(string s: v) {
            int t;
            t = stoi(s);
            answer += t;
        }

        return answer;

    }
};

void read_data(TreeNode *&root) {
    TreeNode *t1 = new TreeNode(5);
    TreeNode *t2 = new TreeNode(1);
    TreeNode *t3 = new TreeNode(9, t1, t2);
    TreeNode *t4 = new TreeNode(0);
    TreeNode *t5 = new TreeNode(4, t3, t4);
    root = t5;
    return;
}

int main() {
    TreeNode *root;
    read_data(root);
    Solution solve;
    cout << solve.sumNumbers(root);

    return 0;
}