//
// Created by ruslan515 on 06.12.22.
//

#include "iostream"

int main() {
    int t;
    int n;
    std::cin >> t;
    for (auto z = 0; z < t; ++z) {
        std::cin >> n;
        int a[n];
        int sum = 0;
        std::cin >> a[0];
        int maxDay = 0;
        for (auto i = 1; i < n; ++i) {
            std::cin >> a[i];
            maxDay = std::max(maxDay, a[i]);
            int delta = 0;
            delta = a[i] - a[i - 1];
            sum += delta;
        }
        if (sum == 0) {
            if (n == 1) {
                std::cout << 1 << "\n";
            } else {
                std::cout << 2 << "\n";
            }
        } else if (sum == (n - 1)) {
            std::cout << n << "\n";
        } else{
            int days[maxDay + 1] = {0};
            int count_commits[maxDay + 1] = {0};
            int dp[maxDay + 1] = {0};
            for (int count: a) {
                days[count] = count;
                count_commits[count] += 1;
            }
            dp[0] = 0;
            dp[1] = 1;
            int global_max = dp[1];
            for (int i = 2; i < maxDay + 1; ++i) {
                if ((count_commits[i] > 0) || (count_commits[i - 1] > 1)) {
                    dp[i] = dp[i - 1] + 1;
                } else {
                    int count = 1;
                    int j = i - 1;
                    int t = count_commits[j] - 1;
                    while (t > -1) {
                        count++;
                        j--;
                        t = count_commits[j] - 1;
                    }
                    dp[i] = count - 1;
                }
                if (dp[i] > global_max) {
                    global_max = dp[i];
                }
            }



            std::cout << global_max << "\n";


            int k = 0;
            k++;
//            std::cout << "MAX day " << maxDay << "\n";

        }

    }
    return 0;
}