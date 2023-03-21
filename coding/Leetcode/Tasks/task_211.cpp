// https://leetcode.com/problems/design-add-and-search-words-data-structure/
// Created by ruslan515 on 19.03.23.
//

#include <bits/stdc++.h>

using namespace std;

const int k = 26;

class WordDictionary {
public:
    map<int, set<string>> mp;

    WordDictionary() {

    }

    void addWord(string word) {
        int n = word.size();
        mp[n].insert(word);
    }

    bool search(string word) {
        int n = word.size();
        bool ans = false;
        if (mp.count(n)) {
            set<string > st;
            st = mp[n];
            set<string> :: iterator it = st.begin();
            for(; it != st.end(); ++it) {
                string temp = *it;
                int i = 0;
                while (i < n && word[i] == temp[i] || word[i] == '.') {
                    ++i;
                }
                if (i == n) {
                    ans = true;
                    break;
                }
            }
        }
        return ans;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */

int main() {
    WordDictionary *wd = new WordDictionary();
    wd->addWord("bad");
    wd->addWord("dad");
    wd->addWord("mad");
    assert(wd->search("pad") == false);
    assert(wd->search("bad") == true);
    assert(wd->search(".ad") == true);
    assert(wd->search("b..") == true);

    return 0;
}