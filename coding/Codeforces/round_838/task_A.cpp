//
// Created by ruslan515 on 15.12.22.
//

#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int DivideConquer(int n) {
    int ans = 0;
    vector<int> a;
    int temp;
    int sum = 0;
    int min_a = INT32_MAX;
    for (int i = 0; i < n; ++i) {
        cin >> temp;
        a.push_back(temp);
        sum += temp;
        min_a = min(min_a, temp);
    }
    if (sum % 2 != 0) {
        if (min_a % 2 == 0) {
            ans = min_a / 2;
        } else {
            int count = 0;
            while (min_a != 0) {
                min_a = floor((float ) min_a / 2);
                ++count;
            }
            ans = count;

        }
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t, n;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        cin >> n;
        int ans = DivideConquer(n);
        cout << ans << "\n";
    }

    return 0;
}

