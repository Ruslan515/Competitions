// https://leetcode.com/problems/implement-trie-prefix-tree/
// Created by ruslan515 on 17.03.23.
//

#include <bits/stdc++.h>

using namespace std;

const int k = 26;

class Trie {
public:
    struct Vertex {
        Vertex *to[k] = {0}; // нулевой указатель означает, что перехода нет
        bool terminal = 0;
    };
    Vertex *root;

    Trie() {
        root = new Vertex();
    }

    void insert(string word) {
        Vertex *v = root;
        for (char c: word) {
            c -= 'a'; // получаем число от 0 до 25
            if (!v->to[c])
                v->to[c] = new Vertex();
            v = v->to[c];
        }
        v->terminal = true;
    }

    bool search(string word) {
        Vertex *v = root;
        for (char c: word) {
            c -= 'a';
            if (!v->to[c])
                return false;
            v = v->to[c];
        }
        return v->terminal;
    }

    bool startsWith(string prefix) {
        Vertex *v = root;
        for (char c: prefix) {
            c -= 'a';
            if (!v->to[c])
                return false;
            v = v->to[c];
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