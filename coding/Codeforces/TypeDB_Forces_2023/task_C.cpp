//
// Created by ruslan515 on 29.01.23.
//

//#include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

void solving() {
    int n, s;
    cin >> n >> s;
    vector<int> arr;
    int temp;
    for (int i = 0; i < n; ++i) {
        cin >> temp;
        arr.push_back(temp);
    }
    vector<long long> xx(n), yy(n);
//    xx.push_back(0);
//    yy.push_back(0);
    for(int i = 1; i < n - 1; ++i) {
        int a = s;
        int b = arr[i] - s;
        if (b <= 0) {
            a += b;
            b = 0;
        }
//        xx.push_back(a);
//        yy.push_back(b);
        xx[i] = a;
        yy[i] = b;
    }
    vector<vector<long long>> dp(n, vector<long long>(2, 0));
    dp[1][0] = arr[0] * xx[1];
    dp[1][1] = arr[0] * yy[1];
    for (int i = 2; i < n - 1; ++i) {
        int val1 = dp[i - 1][0] + xx[i] * yy[i - 1];
        int val2 = dp[i - 1][1] + xx[i] * xx[i - 1];
        dp[i][0] = min(val1 , val2);

        val1 = dp[i - 1][0] + yy[i] * yy[i - 1];
        val2 = dp[i - 1][1] + yy[i] * xx[i - 1];
        dp[i][1] = min(val1, val2);
    }
    long long val1 = dp[n - 2][0] + yy[n - 2] * arr[n - 1];
    long long val2 = dp[n - 2][1] + xx[n - 2] * arr[n - 1];;
    long long answer = min(val1, val2);
    cout << answer << "\n";
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