// https://codeforces.com/contest/1802/problem/A
// Created by ruslan515 on 04.03.23.
//

#include<bits/stdc++.h>

using namespace std;

void printVector(vector<int> & x) {
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
    int n;
    cin >> n;
    vector<int> b(n);
    map<int, vector<int>> mp;
    for(int i = 0; i < n; ++i) {
        int idx;
        cin >> idx;
        b[i] = idx;
        mp[abs(idx)].push_back(idx);
    }
    sort(b.begin(), b.end(), greater<int>());
    printVector(b);

    vector<int> a(n);
    int start = 0;
    int end = n - 1;
    map<int, vector<int>> :: iterator it = mp.begin();
    for(;it != mp.end(); ++it) {
        vector<int> temp = it->second;
        int l = temp.size();
        if (l > 1) {
            a[start] = abs(temp[0]);
            a[start + 1] = (-1) * abs( temp[1]);
            start += 2;
        } else {
            a[end] = temp[0];
            --end;
        }
    }

    printVector(a);

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

