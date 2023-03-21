// https://leetcode.com/problems/implement-trie-prefix-tree/
// Created by ruslan515 on 17.03.23.
//

#include <bits/stdc++.h>

using namespace std;

class Trie {
public:
    const int k = 26;
    int size;
    vector<vector<int>> next_v;
    vector<bool> isTerminal;

    Trie() {
        for(int i = 0; i < k + 1; ++i) {
            vector<int> temp;
            for(int j = 1; j < k + 1; ++j) {
                temp.push_back(-1);
            }
            next_v.push_back(temp);
        }

        for(int i = 0; i < k + 1; ++i) {
            isTerminal.push_back(false);
        }
        ++size;
    }

    void insert(string word) {
        int v = 0;
        int n = word.size();
        for (int i = 0; i < n; ++i) {
            int c;
            c = word[i] - 'a';
            int temp = next_v[v][c];
            if (temp == -1) {
                next_v[v][c] = size;
                ++size;
            }
            v = next_v[v][c];
        }
        isTerminal[v] = true;
        return;
    }

    bool search(string word) {
        int v = 0;
        int n = word.size();
        int temp;
        for (int i = 0; i < n; ++i) {
            int c;
            c = word[i] - 'a';
            temp = next_v[v][c];
            if (temp == -1) {
                return false;
            }
            v = next_v[v][c];
        }
        bool x = isTerminal[v];
        if (x) {
            return true;
        }
        return false;
    }

    bool startsWith(string prefix) {
        int v = 0;
        int n = prefix.size();
        int temp;
        for (int i = 0; i < n; ++i) {
            int c;
            c = prefix[i] - 'a';
            temp = next_v[v][c];
            if (temp == -1) {
                return false;
            }
            v = next_v[v][c];
        }

        return true;

    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

int main() {
    Trie *tr = new Trie();
    tr->insert("apple");
    assert(tr->search("apple") == true);   // return True
    assert(tr->search("app") == false);     // return False
    assert(tr->startsWith("app") == true); // return True
    tr->insert("app");
    assert(tr->search("app") == true);     // return True

    return 0;
}