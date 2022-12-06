// https://codeforces.com/contest/1769/problem/B2
// Created by ruslan515 on 06.12.22.
//
#include <iostream>
#include <cmath>

int main() {
    int n;
    std::cin >> n;
    int a[n];
    int sum = 0;
    for(auto i = 0; i < n; ++i) {
        std::cin >> a[i];
        sum += a[i];
    }

    std::cout << 0 << "\n";
    int temp = 0;
    for(auto i = 0; i < n; ++i) {
        int sum_i = 0;
        for (auto j = 0; j < i; ++j) {
            sum_i += a[j];
        }

        for(int x = 1; x < sum - sum_i; ++x) {
            int t1 = floor(100 * x / a[i]);
            int t2 = floor(100 * (sum_i + x) / sum);
            if (t1 == t2) {
                if (t1 != temp){
                    temp = t1;
                    std::cout << t1 << "\n";
                }
            }
        }
    }
    std::cout << "100\n";


    return 0;
}