// https://codeforces.com/contest/1766/problem/A
// Created by ruslan515 on 14.12.22.
//

#include <iostream>

using namespace std;

int extremely_round(int n) {
    int ans = 0;
    if (n <= 10) {
        ans = n;
    } else {
        int delta = 9;
        int count = 0;
        while (n / 10 != 0) {
            n /= 10;
            ++count;
        }
        ans = delta * count;
        ans += n;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t, n;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        cin >> n;
        int ans = extremely_round(n);
        cout << ans << "\n";
    }

    return 0;
}