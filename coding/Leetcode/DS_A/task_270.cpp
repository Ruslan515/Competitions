//
// Created by ruslan515 on 17.09.23.
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
    int closestValue(TreeNode *root, double target) {
        int answer = INT_MAX;
        stack<TreeNode*> st;
        double minDist = INT_MAX;
        st.push(root);
        while (!st.empty()) {
            TreeNode * current = st.top();
            st.pop();
            int val = current->val;
            double curDist  = abs(target - val);
            if (curDist < minDist) {
                minDist = curDist;
                answer = val;
            } else if (curDist == minDist) {
                if (answer > val) {
                    answer = val;
                }
            }
            if (val > target && current->left) {
                st.push(current->left);
            }
            if (val < target && current->right) {
                st.push(current->right);
            }

        }

        return answer;
    }
};

void read_data(TreeNode *&root) {
//    TreeNode *t1 = new TreeNode(1);
//    TreeNode *t2 = new TreeNode(3);
//    TreeNode *t3 = new TreeNode(2, t1, t2);
//    TreeNode *t4 = new TreeNode(5);
//    TreeNode *t5 = new TreeNode(4, t3, t4);
//    root = t5;

//    TreeNode *t1 = new TreeNode(1);
//    root = t1;

    TreeNode *t1 = new TreeNode(2);
    TreeNode *t2 = new TreeNode(1, nullptr, t1);
    root = t2;

    return;
}

int main() {
    TreeNode *root;
    int answer;
    double target;
    read_data(root);
    Solution solve;

    target = 3.4;
    answer= 2;
    assert(answer == solve.closestValue(root, target));

    return 0;
}
