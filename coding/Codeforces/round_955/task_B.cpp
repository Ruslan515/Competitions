// https://codeforces.com/contest/1982/problem/B
// Created by omega515 on 25.06.24.
//

#include<bits/stdc++.h>

using namespace std;

void solving() {
    int x, y, k;
    cin >> x >> y >> k;
    int d = x % y;
    int z;
    int answer;
    if (d != 0) {
        z = y - d;
    } else {
        answer = x;
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

