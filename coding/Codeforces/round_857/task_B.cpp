// https://codeforces.com/contest/1802/problem/B
// Created by ruslan515 on 04.03.23.
//

#include<bits/stdc++.h>

using namespace std;

void solving() {
    int n;
    cin >> n;
    vector<int> b(n);
    int temp;

    int minAvaries = 0;
    int count = 0;
    int prev = 0;

    for (int i = 0; i < n; ++i) {
        cin >> temp;
        b[i] = temp;

        if (b[i] % 2 == 0) {
            prev = count;
            temp = (prev + 1) / 2;
            minAvaries = max(minAvaries, temp);
        } else {
            ++count;
            if (prev != 0) {
                temp = prev / 2;
                temp += count;
                temp -= prev;
                ++temp;
                minAvaries = max(minAvaries, temp);
            } else {
                ++minAvaries;
            }

        }

    }


//    for (int i = 0; i < n; ++i) {
//        if (b[i] == 2) {
//            prev = count;
//            minAvaries = max(minAvaries, (prev + 1) / 2);
//        } else {
//            ++count;
//            if (prev) {
//                minAvaries = max(minAvaries, prev / 2 + count - prev + 1);
//            } else {
//                ++minAvaries;
//            }
//
//        }
//    }

    cout << minAvaries << "\n";

//    int i = 0;
//    while (i < n) {
//        while (i < n && b[i] == 1) {
//            ++i;
//            ++minAvaries;
//        }
//        if (i < n) {
//            if (b[i] == 2) {
//
//            }
//        }
//
//    }


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

