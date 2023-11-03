// https://contest.yandex.ru/contest/8458/problems/C/
// Created by ruslan515 on 25.10.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void solving(int n) {
        set<int> mySet;
        int temp;
        for (int i = 0; i < n; ++i) {
            cin >> temp;
            if (mySet.count(temp) == 0) {
                cout << temp << "\n";
                mySet.insert(temp);
            }
        }
    }
//    void solving(int n){
//        int prev, current;
//        cin >> prev;
//        if (n == 1) {
//            cout << prev;
//            return;
//        }
//        for (int i = 1; i < n; ++i) {
//            cin >> current;
//            if (prev != current) {
//                cout << prev << "\n";
//                prev = current;
//            }
//        }
//        cout << prev;
//    }
};

int main() {
    int n;
    cin >> n;
    Solution solve;
    solve.solving(n);

    return 0;
}