// https://codeforces.com/contest/1790/problem/A
// Created by ruslan515 on 27.01.23.
// https://youtu.be/UkCUHd26NUM?t=3715

#include <bits/stdc++.h>

using namespace std;

#define vii vector<long long >
#define FOR(i, s, e) for (long long i = s; i <=e; ++i)

long long const max2d = 1e4 + 7;
long long const N = 1e6 + 7;
long long const inf = 1e9 + 7;

int n;
bool viv[N];

void solving() {
    memset(viv, false, sizeof (viv));
    cin >> n;

//    vii a(n + 1, 0);
//    FOR(i, 1, n) {
//        cin >> a[i];
//    }
//
//    sort(a.begin() + 1, a.end());
//    int cnt = 0;
//    FOR(i, 1, n) {
//        if (!viv[i]) {
//            cnt++;
//            int idx = i + 1;
//            int pre = a[i];
//            while (idx <= n) {
//                if (viv[idx] || a[idx] != pre + 1) {
//                    idx++;
//                    continue;
//                }
//                viv[idx] = true;
//                pre = a[idx];
//                ++idx;
//            }
//        }
//    }
//    cout << cnt << "\n";

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