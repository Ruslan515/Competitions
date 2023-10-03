// https://codeforces.com/contest/1875/problem/A
// Created by ruslan515 on 30.09.23.
//

#include<bits/stdc++.h>

using namespace std;

void printVector(vector<int> &x) {
    int maxLike = 0;
    int n = x.size();
    for (int i = 0; i < n; ++i) {
        if (x[i] > 0) {
            ++maxLike;
        } else {
            --maxLike;
        }
        cout << maxLike << " ";
    }
    cout << "\n";
}

void solving() {
    int a, b, n;
    cin >> a >> b >> n;
    vector<int> x(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i];
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

