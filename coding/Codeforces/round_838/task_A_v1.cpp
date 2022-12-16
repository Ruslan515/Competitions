//
// Created by ruslan515 on 15.12.22.
//

#include <iostream>
#include <vector>
#include <math.h>

const int INF = INT32_MAX;

using namespace std;

int DivideConquer(int n) {
    int ans = 0;
    vector<int> a;
    int temp;
    int sum = 0;
    int min_even = INF;
    int min_odd = INF;
    int min_even_odd = INF;
    for (int i = 0; i < n; ++i) {
        cin >> temp;
        a.push_back(temp);
        sum += temp;
        if (temp % 2 == 0) {
            min_even = min(min_even, temp);
            if ((temp / 2) % 2 != 0) {
                min_even_odd = min(min_even_odd, temp);
            }
        } else {
            min_odd = min(min_odd, temp);
        }
    }
    if (sum % 2 != 0) {
        int count_even = 0;
        int count_odd = 0;
        int count_even_odd = 0;
        if (min_even_odd != INF) {
            count_even_odd = 1;
        } else {
            count_even_odd = INF;
        }
        if (min_even != INF) {
            while (min_even != 1) {
                min_even /= 2;
                ++count_even;
            }
        } else {
            count_even = INF;
        }
        if (min_odd != INF) {
            while (min_odd % 2 != 0) {
                min_odd = floor((float) min_odd / 2);
                ++count_odd;
            }
        } else {
            count_odd = INF;
        }
        ans = min(count_even, min(count_odd, count_even_odd));

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

