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

//const int NOT_EX = 1001;
//
//class Codec {
//public:
//
//    string my_ser(TreeNode * root, string & s) {
//        if (root == nullptr) {
//            s += "null,";
//        } else {
//            string temp = to_string(root->val);
//            s += temp + ",";
//            s = my_ser(root->left, s);
//            s = my_ser(root->right, s);
//        }
//        return s;
//    }
//
//    // Encodes a tree to a single string.
//    string serialize(TreeNode *root) {
//        string s = "";
//        string ans = my_ser(root, s);
//        return ans;
//    }
//
//    queue<int> split(string data) {
//        queue<int> ans;
//        string delimiter = ",";
//        int size_delimiter = delimiter.length();
//        int pos = 0;
//        string token;
//        while ((pos = data.find(delimiter)) != string::npos) {
//            token = data.substr(0, pos);
//            if (token == "null") {
//                ans.push(NOT_EX);
//            } else {
//                int temp = stoi(token);
//                ans.push(temp);
//            }
//            data.erase(0, pos + size_delimiter);
//        }
//
//        return ans;
//    }
//
//    TreeNode* my_deser(queue<int>& ans) {
//        int top = ans.front();
//        if (top == NOT_EX) {
//            ans.pop();
//            return nullptr;
//        }
//
//        TreeNode * root = new TreeNode(top);
//        ans.pop();
//        root->left = my_deser(ans);
//        root->right = my_deser(ans);
//
//        return root;
//    }
//
//    // Decodes your encoded data to tree.
//    TreeNode *deserialize(string data) {
//        queue<int> ans = split(data);
//        TreeNode * root = my_deser(ans);
//
//        return root;
//    }
//};

class Codec {
public:

    string serialize(TreeNode* root) {
        ostringstream out;
        serialize(root, out);
        return out.str();
    }

    TreeNode* deserialize(string data) {
        istringstream in(data);
        return deserialize(in);
    }

private:

    void serialize(TreeNode* root, ostringstream& out) {
        if (root) {
            out << root->val << ' ';
            serialize(root->left, out);
            serialize(root->right, out);
        } else {
            out << "# ";
        }
    }

    TreeNode* deserialize(istringstream& in) {
        string val;
        in >> val;
        if (val == "#")
            return nullptr;
        TreeNode* root = new TreeNode(stoi(val));
        root->left = deserialize(in);
        root->right = deserialize(in);
        return root;
    }
};

void read_data(TreeNode *&root) {
    TreeNode *t1 = new TreeNode(3);
    TreeNode *t2 = new TreeNode(4);
    TreeNode *t3 = new TreeNode(2, t1, t2);
    TreeNode *t4 = new TreeNode(5);
    TreeNode *t5 = new TreeNode(1, t3, t4);

//    TreeNode *t1 = new TreeNode(4);
//    TreeNode *t2 = new TreeNode(5);
//    TreeNode *t3 = new TreeNode(3, t1, t2);
//    TreeNode *t4 = new TreeNode(2);
//    TreeNode *t5 = new TreeNode(1, t4, t3);

    root = t5;
    return;
}

int main() {
    TreeNode *root;
    read_data(root);
    Codec ser, deser;
    string str_ser = ser.serialize(root);
    TreeNode *ans = deser.deserialize(str_ser);
    cout << "hello \n";
    return 0;
}