// https://codeforces.com/contest/1931/problem/A
// Created by ruslan515 on 13.02.2024
//

#include<bits/stdc++.h>

using namespace std;

void solving() {
    int n;
    cin >> n;
    int sum, x = -1, y, z;
    for (int i = 1; i <= 26; ++i) {
        for (int j = 1; j <= 26; ++j) {
            for (int k = 1; k <= 26; ++k) {
                sum = i + j + k;
                if (sum == n) {
                    x = i;
                    y = j;
                    z = k;
                    break;
                }
            }
            if (x != -1) {
                break;
            }
        }
        if (x != -1) {
            break;
        }
    }
    vector<int> ans = {x, y, z};
    sort(ans.begin(), ans.end());
    string answer = "";
    for (int el: ans) {
        answer += char (el + 96);
    }
    cout << answer << "\n";

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

