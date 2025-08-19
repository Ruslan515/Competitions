// https://codeforces.com/contest/1769/problem/A
// Created by ruslan515 on 06.12.22.
//

#include <iostream>

int main() {
    int n;
    std::cin >> n;
    int a[n];
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    int ans[n];
    ans[0] = a[0] - 1;
    std::cout << ans[0] << "\n";
    for(int i = 1; i < n; ++i) {
        int delta = a[i] - (i + 1);
        if (delta <= ans[i - 1]) {
            delta = ans[i - 1] + 1;
        }
        ans[i] = delta;
        std::cout << ans[i] << "\n";
    }


    return 0;
}