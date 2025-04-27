// https://codeforces.com/contest/2096/problem/A
// Created by omega515 on 19.04.2025.
//

#include <bits/stdc++.h>

using namespace std;

void solving() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    deque<int> dq;
    dq.push_back(1);
    for (int i = 0; i < n - 1; ++i) {
        if (s[i] == '<') {
            dq.push_front(i + 2);
        } else {
            dq.push_back(i + 2);
        }
    }
    vector<int> answer(n, 0);
    int idx;
    for (int i = 0; i < n; ++i) {
        idx = dq[i];
        answer[idx - 1] = i + 1;
    }
    for (int i = 0; i < n; ++i) {
        cout << answer[i] << " ";
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

//    ios::sync_with_stdio(false);
//    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solving();
    }
    return 0;
}