// https://leetcode.com/problems/serialize-and-deserialize-binary-tree/description/
// Created by ruslan515 on 28.02.23.
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

const int NOT_EX = 1001;

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode *root) {
        string s = "";
        queue<TreeNode *> q;
        string temp = to_string(root->val);
        s += temp + ",";
        q.push(root);
        while (!q.empty()) {
            int size_q = q.size();
            for (int i = 0; i < size_q; ++i) {
                TreeNode* current = q.front();
                q.pop();
                if (current->left != nullptr) {
                    temp = to_string(current->left->val);
                    s += temp + ",";
                    q.push(current->left);
                } else {
                    s += "null,";
                }
                if (current->right != nullptr) {
                    temp = to_string(current->right->val);
                    s += temp + ",";
                    q.push(current->right);
                } else {
                    s += "null,";
                }

            }
        }
        return s;

    }

    vector<int> split(string data) {
        vector<int> ans;
        string delimiter = ",";
        int size_delimiter = delimiter.length();
        int pos = 0;
        string token;
        while ((pos = data.find(delimiter)) != string::npos) {
            token = data.substr(0, pos);
            if (token == "null") {
                ans.push_back(NOT_EX);
            } else {
                int temp = stoi(token);
                ans.push_back(temp);
            }
            data.erase(0, pos + size_delimiter);
        }

        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data) {
        vector<int> ans = split(data);
        TreeNode * root = new TreeNode(ans[0]);
        int n = ans.size();
//        for (int i = 1; i < n - 5; i += 4 ) {
//            if (ans[])
//        }

        return root;
    }
};

void read_data(TreeNode *&root) {
    TreeNode *t1 = new TreeNode(4);
    TreeNode *t2 = new TreeNode(5);
    TreeNode *t3 = new TreeNode(3, t1, t2);
//    TreeNode *t4 = new TreeNode(2);
//    TreeNode *t5 = new TreeNode(-1000, t4, t3);
    TreeNode *t5 = new TreeNode(-1000, nullptr, t3);

    root = t5;
    return;
}

int main() {
    TreeNode *root;
    read_data(root);
    Codec ser, deser;
    TreeNode *ans = deser.deserialize(ser.serialize(root));

    return 0;
}