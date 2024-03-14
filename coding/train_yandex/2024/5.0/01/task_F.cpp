// https://contest.yandex.ru/contest/59539/problems/F/
// Created by ruslan515 on 07.03.2024
//

#include<bits/stdc++.h>

using namespace std;


int main() {
    ios::sync_with_stdio(false);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    long long ans = 0;
    cin >> ans;
    long long a = 0;
    bool x1, x2;
    for (int i = 0; i < n - 1; ++i) {
        cin >> a;
        x1 = ans % 2 == 0;
        x2 = a % 2 == 0;
        if (x1 && x2) {// two odd
            cout << '+';
            ans += a;
        } else if (x1 && !x2) {  // первое четно и второе нечетное
            cout << '+';
            ans += a;
        } else if (!x1 && x2) {  // первое нечетное и второ четное
            cout << '+';
            ans += a;
        } else {
            cout << 'x';
            ans *= a;
        }
    }
    cout << '\n';


    return 0;
}
