// https://codeforces.com/contest/1933/problem/B
// Created by ruslan515 on 27.02.2024
//

#include<bits/stdc++.h>

using namespace std;

void solving() {
    int n;
    cin >> n;
    int sum = 0;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sum += a[i];
    }
    int d = sum % 3;
    int answer = 0;
    if (d == 1 && a.size() != 1) {
        answer = 2;
        for (int i = 0; i < n; ++i) {
            int x = (sum - a[i]) % 3;
            if (x == 0) {
                answer = 1;
                break;
            }
        }
    } else if (d == 1 && a.size() == 1) {
        answer = 1;
    } else if (d == 2) {
        answer = 1;
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

