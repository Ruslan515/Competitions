// https://leetcode.com/problems/step-by-step-directions-from-a-binary-tree-node-to-another/description/?envType=daily-question&envId=2024-07-16
// Created by omega515 on 16.07.24.
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
    string getDirections(TreeNode *root, int startValue, int destValue) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        string answer;
        TreeNode *root_copy = root;
        // find start path
        vector<TreeNode *> root_start;
        queue<pair<TreeNode *, vector<TreeNode *>>> q;
        vector<TreeNode *> v;
        v.push_back(root);
        q.push(make_pair(root, v));
        while (!q.empty()) {
            int size_q = q.size();
            for (int i = 0; i < size_q; ++i) {
                auto curr_pair = q.front();
                q.pop();
                TreeNode *curr = curr_pair.first;
                vector<TreeNode *> v_curr = curr_pair.second;
                int val = curr->val;
                if (val == startValue) {
                    root_start = v_curr;
                    break;
                }
                if (curr->left) {
                    vector<TreeNode *> v_left = v_curr;
                    v_left.push_back(curr->left);
                    q.push(make_pair(curr->left, v_left));
                }
                if (curr->right) {
                    vector<TreeNode *> v_right = v_curr;
                    v_right.push_back(curr->right);
                    q.push(make_pair(curr->right, v_right));
                }
            }
        }

        // find dest
        vector<pair<TreeNode *, string >> destRoot;
        queue<pair<TreeNode *, vector<pair<TreeNode *, string >>>> destQ;
        vector<pair<TreeNode *, string >> destV;
        destV.push_back(make_pair(root, ""));
        destQ.push(make_pair(root, destV));
        while (!destQ.empty()) {
            int size_q = destQ.size();
            for (int i = 0; i < size_q; ++i) {
                auto curr_pair = destQ.front();
                destQ.pop();
                TreeNode *curr = curr_pair.first;
                vector<pair<TreeNode *, string >> v_curr;
                int val = curr->val;
                if (val == destValue) {
                    destRoot = v_curr;
                    break;
                }
                if (curr->left) {
                    vector<pair<TreeNode *, string >> v_left = v_curr;
                    v_left.push_back(make_pair(curr->left, "L"));
                    destQ.push(make_pair(curr->left, v_left));
                }
                if (curr->right) {
                    vector<pair<TreeNode *, string >> v_right = v_curr;
                    v_right.push_back(make_pair(curr->right, "R"));
                    destQ.push(make_pair(curr->right, v_right));
                }

            }
        }


        return answer;
    }
};

void read_data(TreeNode *&root) {
    TreeNode *t1 = new TreeNode(3);
    TreeNode *t2 = new TreeNode(1, t1, nullptr);
    TreeNode *t3 = new TreeNode(6);
    TreeNode *t4 = new TreeNode(4);
    TreeNode *t5 = new TreeNode(2, t3, t4);
    TreeNode *t6 = new TreeNode(5, t2, t5);

    root = t6;
    return;
}

int main() {
    TreeNode *root;
    read_data(root);
    int startValue, destValue;
    string answer;
    Solution solve;

    startValue = 3, destValue = 6;
    answer = "UURL";
    assert(answer == solve.getDirections(root, startValue, destValue));

//    startValue = 2, destValue = 1;
//    answer = "L";
//    assert(answer == solve.getDirections(root, startValue, destValue));

    return 0;
}

