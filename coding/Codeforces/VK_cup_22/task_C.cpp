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
        int max_day = 0;
        for (auto i = 1; i < n; ++i) {
            std::cin >> a[i];
            max_day = std::max(max_day, a[i]);
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
            int days[max_day + 1] = {0};
            int count_commits[max_day + 1] = {0};
            for (int count: a) {
                days[count] = count;
                count_commits[count] += 1;
            }
            int global_max = 0;
            int start_idx = 1;
            for (auto i = 2; i < max_day + 1; ++i) {
                int temp_sum = count_commits[i];
                for (auto j = start_idx; j < i; ++j) {
                    temp_sum += count_commits[j];
                }
                if (temp_sum == i - start_idx + 1) {
                    if (temp_sum > global_max) {
                        global_max = temp_sum;
                    }
                } else {
                    for (auto j = start_idx + 1; j < max_day + 1; ++j) {
                        if (count_commits[j] != 0) {
                            start_idx = j;
                            break;
                        }
                    }
                }
            }

            std::cout << global_max << "\n";


            int k = 0;
            k++;
//            std::cout << "MAX day " << max_day << "\n";

        }

    }
    return 0;
}