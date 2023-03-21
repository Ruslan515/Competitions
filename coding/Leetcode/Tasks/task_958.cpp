// https://leetcode.com/problems/check-completeness-of-a-binary-tree/
// Created by ruslan515 on 15.03.23.
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

//class Solution {
//public:
//    bool isCompleteTree(TreeNode* root) {
//        bool answer = true;
//        if (root == nullptr) {
//            return answer;
//        }
//
//        int level = 0;
//        queue<TreeNode *> q;
//        q.push(root);
//
//        while (!q.empty()) {
//            int size_q = q.size();
//            for (int i = 0; i < size_q; ++i) {
//                TreeNode *current = q.front();
//                q.pop();
//                if (current->left == nullptr && current->right != nullptr) {
//                    answer = false;
//                    return answer;
//                }
//                if (current->left != nullptr)
//                    q.push(current->left);
//                if (current->right != nullptr)
//                    q.push(current->right);
//            }
//            ++level;
//            int countNodes = pow(2, level);
//            bool last = true;
//            for(int i = 0; i < q.size(); ++i) {
//                TreeNode* current = q.front();
//                if (current->left != nullptr || current->right != nullptr) {
//                    last = false;
//                    break;
//                }
//            }
//            if (!last) {
//                int currSizeQueue = q.size();
//                if (countNodes != currSizeQueue) {
//                    answer = false;
//                    return answer;
//                }
//            }
//        }
//
//        return answer;
//    }
//};

class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        bool answer = true;
        if (root == nullptr) {
            return answer;
        }

        int level = 0;
        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty()) {
            int size_q = q.size();
            for (int i = 0; i < size_q; ++i) {
                TreeNode *current = q.front();
                q.pop();
                if (current->left == nullptr && current->right != nullptr) {
                    answer = false;
                    return answer;
                }
                if (current->left != nullptr)
                    q.push(current->left);
                if (current->right != nullptr)
                    q.push(current->right);
            }
            ++level;
            int countNodes = pow(2, level);
            bool last = true;
            for(int i = 0; i < q.size(); ++i) {
                TreeNode* current = q.front();
                if (current->left != nullptr || current->right != nullptr) {
                    last = false;
                    break;
                }
            }
            if (!last) {
                int currSizeQueue = q.size();
                if (countNodes != currSizeQueue) {
                    answer = false;
                    return answer;
                }
            }
        }

        return answer;
    }
};

void read_data(TreeNode *&root) {
    TreeNode *t1 = new TreeNode(5);
    TreeNode *t2 = new TreeNode(2, t1, nullptr);
    TreeNode *t4 = new TreeNode(7);
    TreeNode *t5 = new TreeNode(8);
    TreeNode *t6 = new TreeNode(3, t4, t5);
    TreeNode *t7 = new TreeNode(1, t2, t6);
    root = t7;

//    TreeNode *t1 = new TreeNode(4);
//    TreeNode *t2 = new TreeNode(5);
//    TreeNode *t3 = new TreeNode(2, t1, t2);
////    TreeNode *t4 = new TreeNode(6);
////    TreeNode *t5 = new TreeNode(3, t4, nullptr);
//    TreeNode *t4 = new TreeNode(7);
//    TreeNode *t5 = new TreeNode(3, nullptr, t4);
//    TreeNode *t6 = new TreeNode(1, t3, t5);
//    root = t6;
    return;
}

int main() {
    TreeNode *root;
    read_data(root);
    Solution solve;
    cout << solve.isCompleteTree(root);

    return 0;
}