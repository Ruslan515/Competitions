// https://codeforces.com/contest/1982/problem/0
// Created by omega515 on 25.06.24.
//

#include<bits/stdc++.h>

using namespace std;

void solving() {
    int x1, x2, y1, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    string answer = "NO";
    if (x1 == x2 && y1 == y2) {
        answer = "Yes";
    } else if (x1 < y1) {
        if (x2 < y2) {
            answer = "YES";
        }
    } else if (x1 > y1) {
        if (x2 > y2) {
            answer = "YES";
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

