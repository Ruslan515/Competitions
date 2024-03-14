// https://contest.yandex.ru/contest/59539/problems/
// Created by ruslan515 on 04.03.2024
//

//#include<bits/stdc++.h>
//
//using namespace std;
//
//int solving(int left, int d1, int right, int d2) {
//    int l1, l2, r1, r2;
//    l1 = left - d1;
//    r1 = left + d1;
//    l2 = right - d2;
//    r2 = right + d2;
//    int answer = 0;
//    if (r1 < l2) {
//        answer = 2 * d1 + 2 * d2 + 2;
//    } else if (r1 == l2) {
//        answer = 2 * d1 + 2 * d2 + 1;
//    } else if (r1 < r2 && l2 < r1) {
//        answer = d1 + (right - left) + d2 + 1;
//    } else if (d1 < d2) {
//        answer = 2 * d2 + 1;
//    } else {
//        answer = 2 * d1 + 1;
//    }
//    return answer;
//
//}
//
//int main() {
//    ios::sync_with_stdio(false);
//    ios_base::sync_with_stdio(false);
//    cin.tie(0);
//
//    int p, v, q, m;
//    cin >> p >> v >> q >> m;
//    int answer = 0;
//    if (p <= q) {
//        answer = solving(p, v, q, m);
//    } else {
//        answer = solving(q, m, p, v);
//    }
//    cout << answer << "\n";
//
//    return 0;
//}
#include<iostream>
#include<algorithm>
using namespace std;

int main() {
    int P, Q, V, M;
    cin >> P >> Q >> V >> M;

    int min_tree = min(P - V, Q - M);
    int max_tree = max(P + V, Q + M);

    cout << max_tree - min_tree + 1;

    return 0;
}
