// https://leetcode.com/problems/binary-search-tree-iterator/description/?envType=problem-list-v2&envId=design
// Created by omega515 on 20.09.24.
//

#include <bits/stdc++.h>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

struct LinkedList {
    int val;
    LinkedList *next;

    LinkedList() : val(0), next(nullptr) {}

    LinkedList(int x) : val(x), next(nullptr) {}

    LinkedList(int x, LinkedList *next) : val(x), next(next) {}
};

class BSTIterator {
public:
    vector<int> vals;
    LinkedList *first;

    void bfs(TreeNode *root) {
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()) {
            int sizeQ = q.size();
            TreeNode *current;
            int val;
            for (int i = 0; i < sizeQ; ++i) {
                current = q.front();
                q.pop();
                val = current->val;
                this->vals.push_back(val);
                if (current->left) {
                    q.push(current->left);
                }
                if (current->right) {
                    q.push(current->right);
                }
            }
        }
    }

    void createLinkendList() {
        int firstVal = this->vals[0] - 1;
        LinkedList *prev = new LinkedList(firstVal);
        this->first = prev;
        for (int i = 0; i < this->vals.size(); ++i) {
            LinkedList *current = new LinkedList(this->vals[i]);
            prev->next = current;
            prev = current;
        }
    }

    BSTIterator(TreeNode *root) {
        bfs(root);
        sort(vals.begin(), vals.end());
        createLinkendList();

    }

    int next() {
        this->first = this->first->next;
        int val = this->first->val;
        return val;
    }

    bool hasNext() {
        bool answer = false;
        if (this->first->next != nullptr) {
            answer = true;
        }
        return answer;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */

void readData(TreeNode *&root) {
    TreeNode *t1 = new TreeNode(3);
    TreeNode *t2 = new TreeNode(9);
    TreeNode *t3 = new TreeNode(20);
    TreeNode *t4 = new TreeNode(15, t2, t3);
    TreeNode *t5 = new TreeNode(7, t1, t4);
    root = t5;
}

int main() {


    TreeNode *root;
    readData(root);

    BSTIterator *bst = new BSTIterator(root);

    assert(3 == bst->next());
    assert(7 == bst->next());
    assert(true == bst->hasNext());
    assert(9 == bst->next());
    assert(true == bst->hasNext());
    assert(15 == bst->next());
    assert(true == bst->hasNext());
    assert(20 == bst->next());
    assert(false == bst->hasNext());


    return 0;
}
