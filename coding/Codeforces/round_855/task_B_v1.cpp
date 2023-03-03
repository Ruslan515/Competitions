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
    map<char, int> upper_ch;
    map<char, int> lower_ch;
    for (int i = 0; i < n; ++i) {
        char ch = s[i];
        if (isupper(ch)) {
            upper_ch[ch] += 1;
        } else {
            lower_ch[ch] += 1;
        }
    }

    int answer = 0;
    map<char, int> :: iterator it = upper_ch.begin();
    for (; it != upper_ch.end(); ++it) {
        char ch = it->first;
        char ch_lower = tolower(ch);
        while (lower_ch.find(ch_lower) != lower_ch.end() && lower_ch[ch_lower] > 0 && upper_ch[ch] > 0) {
            ++answer;
            --lower_ch[ch_lower];
            --upper_ch[ch];
        }
    }

    it = lower_ch.begin();
    for(; it != lower_ch.end(); ++it) {
        char ch = it->first;
        while (lower_ch[ch] >= 2 and k > 0) {
            --k;
            ++answer;
            lower_ch[ch] -= 2;
        }
    }

    cout << answer << "\n";
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

