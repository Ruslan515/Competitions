//
// Created by ruslan515 on 29.01.23.
//

#include <bits/stdc++.h>

using namespace std;

void solving() {
    int n;
    cin >> n;
    if (n % 2 == 0) {
        cout << 1 << " " << n / 2 << "\n";
    } else {
        cout << -1 << "\n";
    }
    return;
}

int main() {
    ios::sync_with_stdio(false);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    for(int i = 0; i < t; ++i) {
        solving();
    }

    return 0;
}