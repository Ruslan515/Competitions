// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-postorder-traversal/description/?envType=daily-question&envId=2025-02-23
// Created by omega515 on 23.02.2025.
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
    TreeNode *constructFromPrePost(vector<int> &preorder, vector<int> &postorder) {
        if (preorder.size() == 0) {
            return nullptr;
        }
        TreeNode *answer = new TreeNode(preorder[0]);
        if (preorder.size() == 1) {
            return answer;
        }
        int n = preorder.size();
        int left_root_val = preorder[1];
        auto left_root_index_iter = find(postorder.begin(), postorder.end(), left_root_val);
        int left_root_index = distance(postorder.begin(), left_root_index_iter);

        vector<int> left_postorder(left_root_index + 1);
        copy(postorder.begin(), postorder.begin() + left_root_index + 1, left_postorder.begin());
        vector<int> right_postorder(n - left_root_index - 2);
        copy(postorder.begin() + left_root_index + 1, postorder.end() - 1, right_postorder.begin());

        vector<int> left_preorder(left_root_index + 1);
        copy(preorder.begin() + 1, preorder.begin() + 2 + left_root_index, left_preorder.begin());
        vector<int> right_preorder(n - left_root_index - 2);
        copy(preorder.begin() + left_root_index + 2, preorder.end(), right_preorder.begin());

        answer->left = constructFromPrePost(left_preorder, left_postorder);
        answer->right = constructFromPrePost(right_preorder, right_postorder);

        return answer;
    }
};

int main() {
    TreeNode *answer;
    vector<int> preorder, postorder;
    Solution solve;

    preorder = {2, 1}, postorder = {1, 2};
    TreeNode *t1 = new TreeNode(1);
    TreeNode *t2 = new TreeNode(2, t1, nullptr);
    answer = t2;
    TreeNode *root = solve.constructFromPrePost(preorder, postorder);
    assert(answer == root);

//    preorder = {1, 2, 4, 5, 3, 6, 7}, postorder = {4, 5, 2, 6, 7, 3, 1};
//    TreeNode *t1 = new TreeNode(4);
//    TreeNode *t2 = new TreeNode(5);
//    TreeNode *t3 = new TreeNode(2, t1, t2);
//
//    TreeNode *t4 = new TreeNode(6);
//    TreeNode *t5 = new TreeNode(7);
//    TreeNode *t6 = new TreeNode(3, t4, t5);
//    TreeNode *t7 = new TreeNode(1, t3, t6);
//    answer = t7;
//    TreeNode *root = solve.constructFromPrePost(preorder, postorder);
//    assert(answer == root);


//    TreeNode *t2 = new TreeNode(-1);
//    TreeNode *t1 = new TreeNode(-1, nullptr, t2);
//    root = t1;
//    FindElements *fe = new FindElements(root);
//    assert(false == fe->find(1));
//    assert(true == fe->find(2));

    return 0;
}

