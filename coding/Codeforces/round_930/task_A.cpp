// https://codeforces.com/contest/1933/problem/A
// Created by ruslan515 on 27.02.2024
//

#include<bits/stdc++.h>

using namespace std;

void solving() {
    int n;
    cin >> n;
    int answer = 0;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        answer += abs(a[i]);
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

