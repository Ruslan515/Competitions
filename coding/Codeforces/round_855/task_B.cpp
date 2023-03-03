// https://codeforces.com/contest/1800/problem/A
// Created by ruslan515 on 02.03.23.
//

#include<bits/stdc++.h>

using namespace std;

void solving() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    map<char, int> mp;
    set<char> st;
    for (int i = 0; i < n; ++i) {
        char ch = s[i];
        st.insert(ch);
        mp[ch] += 1;
    }

    set<char> :: iterator it = st.begin();
    for (; it != st.end(); ++it) {
        char ch = *it;
        bool up = ch < 'a';
        char change_char;
        if (up) {
            change_char = tolower(ch);
        } else {
            change_char = toupper(ch);
        }
        if (st.count(change_char) == 0) {
            mp.erase(ch);
            st.erase(ch);
            cout << ch << "\n";
        }
    }

    it = st.begin();
    for (; it !)



    return;
}

int main() {
    ios::sync_with_stdio(false);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        solving();
    }

    return 0;
}

