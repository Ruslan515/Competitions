// https://codeforces.com/contest/1938/attachments/download/24400/combined.pdf
// Created by ruslan515 on 22.03.2024
//

#include<bits/stdc++.h>

using namespace std;

int solving() {
    int n;
    cin >> n;
    int answer = -1;
    vector<int> a(n);
    int pos_one = -1;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (i != 0) {
            if (a[i] == 0) {
                return answer;
            } else if (a[i] != 1) {
                int prev = a[i - 1];
                int diff = a[i] - prev;
                if (diff > 1) {
                    return answer;
                }
            } else if (a[i] == 1) {
                pos_one = i;
            }

        }
    }
    if (pos_one != -1) {

        return answer;
    }


    return answer;
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

