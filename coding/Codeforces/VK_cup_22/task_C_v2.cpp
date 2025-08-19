//
// Created by ruslan515 on 06.12.22.
//

#include "iostream"

int get_max_len(int a[], int n) {
    int i = 1;
    int len = 0;
    int temp_len = 0;
    while (i <= n) {
        int t1 = a[i];
        if (t1 != 0) {
            ++temp_len;
        } else{
            len = std::max(len, temp_len);
            temp_len = 0;
        }
        ++i;
    }
    len = std::max(len, temp_len);
    return len;
}

//https://www.geeksforgeeks.org/generate-all-the-binary-strings-of-n-bits/
void generate_bin_strings(int n, int arr[], int i) {

}


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
            int global_max = 0;
            int days[maxDay + 1] = {0};
            int count_commits[maxDay + 1] = {0};
            bool bin_days[maxDay + 1] = {false};
            for (int count: a) {
                days[count] = count;
                count_commits[count] += 1;
            }

            int max_len = get_max_len(count_commits, maxDay);
            std::cout << max_len << "\n";

            for (int k = 1; k < maxDay; ++k) {

            }

//            std::cout << global_max << "\n";
        }

    }
    return 0;
}