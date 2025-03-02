// https://leetcode.com/problems/find-elements-in-a-contaminated-binary-tree/description/?envType=daily-question&envId=2025-02-21
// Created by omega515 on 21.02.2025.
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

class FindElements {
private:
    unordered_set<int> vals;
public:

    FindElements(TreeNode *root) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        this->vals.insert(0);
        root->val = 0;
        queue<TreeNode *> queue1;
        queue1.push(root);
        TreeNode *current;
        int currVal, val;
        while (!queue1.empty()) {
            int sizeQueue = queue1.size();
            for (int i = 0; i < sizeQueue; ++i) {
                current = queue1.front();
                currVal = current->val;
                queue1.pop();
                if (current->left) {
                    val = 2 * currVal + 1;
                    this->vals.insert(val);
                    current->left->val = val;
                    queue1.push(current->left);
                }
                if (current->right) {
                    val = 2 * currVal + 2;
                    this->vals.insert(val);
                    current->right->val = val;
                    queue1.push(current->right);
                }

            }
        }

    }

    bool find(int target) {
        return this->vals.find(target) != this->vals.end();

    }
};


int main() {
    TreeNode *root;

//    TreeNode *t2 = new TreeNode(-1);
//    TreeNode *t1 = new TreeNode(-1, nullptr, t2);
//    root = t1;
//    FindElements *fe = new FindElements(root);
//    assert(false == fe->find(1));
//    assert(true == fe->find(2));


//    TreeNode *t1 = new TreeNode(-1);
//    TreeNode *t2 = new TreeNode(-1);
//    TreeNode *t3 = new TreeNode(-1, t1, t2);
//    TreeNode *t4 = new TreeNode(-1);
//    TreeNode *t5 = new TreeNode(-1, t3, t4);
//    root = t5;
//    FindElements *fe = new FindElements(root);
//    assert(true == fe->find(1));
//    assert(true == fe->find(3));
//    assert(false == fe->find(5));

//    TreeNode *t1 = new TreeNode(-1);
//    TreeNode *t2 = new TreeNode(-1, t1, nullptr);
//    TreeNode *t3 = new TreeNode(-1, t2, nullptr);
//    TreeNode *t4 = new TreeNode(-1, nullptr, t3);
//
//    root = t4;
//    FindElements *fe = new FindElements(root);
//    assert(true == fe->find(2));
//    assert(false == fe->find(3));
//    assert(false == fe->find(4));
//    assert(true == fe->find(5));

    return 0;
}

