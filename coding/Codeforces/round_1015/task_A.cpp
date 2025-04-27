//
// Created by omega515 on 05.04.2025.
//

#include <bits/stdc++.h>

using namespace std;

void solving() {
    unordered_map<int, int> mp{
            {0, 3},
            {1, 1},
            {2, 2},
            {3, 1},
            {5, 1}
    };
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int answer = 0;
    for (int i = 0; i < n; ++i) {
        if (mp.find(a[i]) != mp.end()) {
            if (--mp[a[i]] == 0) {
                mp.erase(a[i]);
            }
        }
        if (mp.empty()) {
            answer = i + 1;  // Индексация с 1
            break;
        }
    }
    cout << (mp.empty() ? answer : 0) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solving();
    }
    return 0;
}