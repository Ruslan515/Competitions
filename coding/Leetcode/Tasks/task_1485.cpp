// https://leetcode.com/problems/clone-binary-tree-with-random-pointer/
// Created by ruslan515 on 20.03.23.
//

#include <bits/stdc++.h>

using namespace std;

struct Node {
    int val;
    Node *left;
    Node *right;
    Node *random;

    Node() : val(0), left(nullptr), right(nullptr), random(nullptr) {}

    Node(int x) : val(x), left(nullptr), right(nullptr), random(nullptr) {}

    Node(int x, Node *left, Node *right, Node *random) : val(x), left(left), right(right), random(random) {}
};

struct NodeCopy {
    int val;
    NodeCopy *left;
    NodeCopy *right;
    NodeCopy *random;

    NodeCopy() : val(0), left(nullptr), right(nullptr), random(nullptr) {}

    NodeCopy(int x) : val(x), left(nullptr), right(nullptr), random(nullptr) {}

    NodeCopy(int x, NodeCopy *left, NodeCopy *right, NodeCopy *random) : val(x), left(left), right(right),
                                                                         random(random) {}
};

class Solution {
public:
    NodeCopy *copyRandomBinaryTree(Node *root) {
        if (root == nullptr) {
            return nullptr;
        }
        NodeCopy *ans = new NodeCopy();
        Node *root_copy = root;
        queue<Node *> q;
        queue<NodeCopy *> qCopy;
        q.push(root_copy);
        qCopy.push(ans);

        map<Node *, NodeCopy *> mp;
        int val;

        while (!q.empty()) {
            int queue_size = q.size();
            for (int i = 0; i < queue_size; ++i) {
                Node *current = q.front();
                NodeCopy *currentCopy = qCopy.front();
                mp[current] = currentCopy;
                qCopy.pop();
                q.pop();
                val = current->val;
                currentCopy->val = val;
                if (current->left != nullptr) {
                    q.push(current->left);
                    NodeCopy *left = new NodeCopy();
                    currentCopy->left = left;
                    qCopy.push(left);
                }
                if (current->right != nullptr) {
                    q.push(current->right);
                    NodeCopy *right = new NodeCopy();
                    currentCopy->right = right;
                    qCopy.push(right);
                }
            }
        }

        q.push(root);
        qCopy.push(ans);
        while (!q.empty()) {
            int queue_size = q.size();
            for (int i = 0; i < queue_size; ++i) {
                Node *current = q.front();
                NodeCopy *currentCopy = qCopy.front();
                q.pop();
                qCopy.pop();
                Node *random_key = current->random;
                if (random_key != nullptr){
                    NodeCopy *random_value;
                    random_value = mp[random_key];
                    currentCopy->random = random_value;
                }
                if (current->left != nullptr) {
                    q.push(current->left);
                    qCopy.push(currentCopy->left);
                }
                if (current->right != nullptr) {
                    q.push(current->right);
                    qCopy.push(currentCopy->right);
                }
            }

        }

        return ans;

    }
};

void read_data(Node *&root) {
    Node *t3 = new Node(7);
    Node *t2 = new Node(4, t3, nullptr, t3);
    Node *t1 = new Node(1, nullptr, t2, nullptr);
    t3->random = t1;
    root = t1;

    return;
}

int main() {
    Node *root;
    read_data(root);
    Solution solve;
    NodeCopy *ans = solve.copyRandomBinaryTree(root);
    cout << "yes\n";

    return 0;
}