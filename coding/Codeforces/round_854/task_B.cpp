// https://codeforces.com/contest/1799/problem/B
// Created by ruslan515 on 27.02.23.
//

#include<bits/stdc++.h>

using namespace std;


bool check_vector(vector<int> a) {
    bool ans = true;
    for (int i = 0; i < a.size() - 1; ++i) {
        if (a[i] != a[i + 1]) {
            ans = false;
            break;
        }
    }
    return ans;
}

void find_min_idx(vector<int> &a, int &my_min, int & idx) {
    int n = a.size();
    for (int i = 0; i < n; ++i) {
        if (a[i] < my_min) {
            my_min = a[i];
            idx = i;
        }
    }
    return;
}

void solving() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    if (check_vector(a)) {
        cout << 0 << "\n";
    } else {

        vector<vector<int>> ans;
        vector<int> prev = a;

        while (check_vector(a) == false) {
            int my_min = INT_MAX;
            int idx = -1;
            find_min_idx(a, my_min, idx);

            for (int i = 0; i < n; ++i) {
                if (a[i] != my_min and a[i] > my_min) {
                    int x = (a[i] / my_min);
                    if (a[i] % my_min != 0) {
                        ++x;
                    }
                    vector<int> temp;
                    temp.push_back(i);
                    temp.push_back(idx);
                    ans.push_back(temp);
                    a[i] = x;
                }
            }
            if (a == prev) {
                cout << -1 << "\n";
                return;
            }
            prev = a;
        }

        cout << ans.size() << "\n";
        for (int i = 0; i < ans.size(); ++i) {
            cout << ans[i][0] + 1 << " " << ans[i][1] + 1 << "\n";
        }

    }

    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        solving();
    }

    return 0;
}


