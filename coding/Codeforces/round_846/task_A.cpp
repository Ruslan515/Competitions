// https://codeforces.com/contest/1780/problem/A
// Created by ruslan515 on 25.01.23.
//

#include <bits/stdc++.h>

using namespace std;

void solving() {
    int n;
    cin >> n;
    vector<int > a;
    vector<int> vec_even, vec_odd;
    int temp;
    int cnt_even = 0, cnt_odd = 0;
    for (int i = 0; i < n; ++i) {
        cin >> temp;
        if (temp % 2 == 0) {
            ++cnt_even;
            vec_even.push_back(i + 1);
        } else {
            ++cnt_odd;
            vec_odd.push_back(i + 1);
        }
        a.push_back(temp);
    }
    if (n == 3) {
        int sum = a[0] + a[1] + a[2];
        if (sum % 2 != 0) {
            cout << "YES" << "\n";
            cout << 1 << " " << 2 << " " << 3 << "\n";
        } else {
            cout << "NO" << "\n";
        }
        return;
    }

    if (cnt_odd == 0) {
        cout << "NO" << "\n";
    }
    if (cnt_odd == 1) {
        if (cnt_even >= 2) {
            cout << "YES" << "\n";
            cout << vec_odd[0] << " " << vec_even[0] << " " << vec_even[1] << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }
    if (cnt_odd >= 2) {
        if(cnt_odd >= 2) {
            cout << "YES" << "\n";
            cout << vec_odd[0] << " " << vec_even[0] << " " << vec_even[1] << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }


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