//
// Created by ruslan515 on 29.01.23.
//

#include <bits/stdc++.h>

using namespace std;

void data_load(vector<int> & prime, vector<int> & flag, int & cnt) {
    flag[1] = 1;
    for(int i = 2; i < 1000000 + 1; ++i) {
        if (!flag[i]) {
            prime[++cnt] = i;
            for(int j = i * 2; j < 1000000 + 1; j += i) {
                flag[j] = 1;
            }
        }
    }
    return;
}

void solving(vector<int> & prime, vector<int> & flag) {
    int n;
    cin >> n;
    for (int i = 1; (i < cnt + 1) && (prime[i] < n + 1); ++i) {
        int cnt = 0;

    }
}

int main() {
    ios::sync_with_stdio(false);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int cnt;
    vector<int> prime(1000010);
    vector<int> flag(1000010);
    data_load(prime, flag, cnt);
    int t;
    cin >> t;
    for(int i = 0; i < t; ++i) {
        solving(prime, flag, cnt);
    }

    return 0;
}