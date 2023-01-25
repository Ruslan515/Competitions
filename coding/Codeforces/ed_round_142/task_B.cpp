// https://codeforces.com/contest/1792/problem/B?locale=ru
// Created by ruslan515 on 24.01.23.
//

#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    for (int cnt = 0; cnt < t; ++cnt) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        int alice, bob, temp, jok;
        bob = alice = jok = a;
        while (b > 0 || c > 0 || d > 0) {
            if (bob > 0 and b > 0) {
                temp = min(b, bob);
                bob -= temp;
                alice += temp;
                jok += temp;
                b -= temp;
            } else if (alice > 0 and c > 0) {
                temp = min(c, alice);
                alice -= temp;
                bob += temp;
                jok += temp;
                c -= temp;
            } else if (alice > 0 and bob > 0 and d > 0) {
                temp = min(d, min(alice, bob));
                jok += temp;
                alice -= temp;
                bob -= bob;
                d -= temp;
            } else {
                if (b != 0 || c != 0 || d != 0)
                    ++jok;
                break;
            }
        }
        cout << jok << "\n";
    }



//        if ((a + b + c + d) == 0) {
//            cout << 0 << "\n";
//            continue;
//        }
//        if (a == 0) {
//            cout << 1 << "\n";
//            continue;
//        }
//        int p = a + 2 * min(b, c) + min((max(c, b) - min(b, c)), a);
//        if (p % 2 == 0) {
//            cout << 0 << "\n";
//        } else {
//            p %= 3;
//            cout << p << "\n";
//        }
//}

    return 0;
}