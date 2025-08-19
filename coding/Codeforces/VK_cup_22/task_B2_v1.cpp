// https://codeforces.com/contest/1769/problem/B2
// Created by ruslan515 on 06.12.22.
//
#include <iostream>
#include <cmath>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    std::cin >> n;
    int64_t a[n];
    int64_t all_sum = 0;
    for(auto i = 0; i < n; ++i) {
        std::cin >> a[i];
        all_sum += a[i];
    }

    std::cout << 0 << "\n";
    if (n == 1) {
        int temp = 0;
        for(auto i = 0; i < n; ++i) {
            int sum_i = 0;
            for (auto j = 0; j < i; ++j) {
                sum_i += a[j];
            }

            for(int x = 1; x < all_sum - sum_i; ++x) {
                int t1 = floor(100 * x / a[i]);
                int t2 = floor(100 * (sum_i + x) / all_sum);
                if (t1 == t2) {
                    if (t1 != temp){
                        temp = t1;
                        std::cout << t1 << "\n";
                    }
                }
            }
        }
        std::cout << "100\n";
    } else {
        for (int p = 1; p < 100; ++p) {
            int64_t temp_sum = 0;
            for (int i = 0; i < n; ++i) {
                int64_t xx = a[i];
                float x1 = (float)p * xx;
                x1 = x1 / 100.0;

                float temp = temp_sum + x1;
                temp *= 100;
                temp /= all_sum;
                int temp_x = floor(temp);
                if (temp_x == p) {
                    float x2 = (float)p * all_sum;
                    x2 = x2 / 100;
                    x2 -= temp_sum;

                    float temp_1 = 100 * x2;
                    temp_1 /= a[i];
                    int temp_xx = floor(temp_1);
                    if (temp_xx == p) {
                        std::cout << p << "\n";
                        break;
                    }
//                    std::cout << "file # " << i << ". file size == " << a[i] << ". p == " << p << "\n";
                }

//            float x2 = (float)p * sum;
//            x2 -= temp_sum;
//            x2 = x2 / 100;
////            x2 = x2;
//            float delta = abs(x1 - x2);
////            if (x1 == x2 && x1 != 0) {
//            if (delta <= 3) {
//                std::cout << "file # " << i << ". file size == " << a[i] << ". p == " << p << "\n";
//            }
                temp_sum += a[i];
            }
        }


        std::cout << "100\n";

    }


    return 0;
}