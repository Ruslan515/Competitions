// https://contest.yandex.ru/contest/59540/problems/
// Created by omega515 on 10.03.24.
//

#include<bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int k;
    cin >> k;
    int minX = INT_MAX, maxX = -INT_MAX, minY = INT_MAX, maxY = -INT_MAX, x, y;
    for (int i = 0; i < k; ++i) {
        cin >> x >> y;
        minX = min(minX, x);
        maxX = max(maxX, x);
        minY = min(minY, y);
        maxY = max(maxY, y);
    }
    cout << minX << " " << minY << " " << maxX << " " << maxY << "\n";

    return 0;
}
