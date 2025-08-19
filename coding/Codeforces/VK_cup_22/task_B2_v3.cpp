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
        int p_val = 0;
        for (int p = 1; p < 100; ++p) {
            int64_t temp_sum = 0;
            for (int i = 0; i < n; ++i) {
                int64_t xx = a[i];
                double x = (double)p * all_sum;
                x /= 100;
                x -= temp_sum;
                int64_t x_ceil = ceil(x);

                double x_one = (double)x_ceil * 100;
                x_one /= xx;
                int64_t p_xone = floor(x_one);

                if (p_xone == p) {
                    if (p_val != p) {
                        std::cout << p << "\n";
                        p_val = p;
                        break;
                    }
                } else {
                    double x_min = (double)p * xx;
                    x_min = x_min / 100.0;
                    int64_t x11 = ceil(x_min);

                    double temp = temp_sum + x11;
                    temp *= 100;
                    temp /= all_sum;
                    int temp_x = floor(temp);

                    if (temp_x == p) {
                        if (p_val != p) {
                            std::cout << p << "\n";
                            p_val = p;
                            break;

                        }
//                            if (!(p == 49 && a[i] == 2 && i == 1 && a[i - 1] == 10000000000 && a[i + 1] == 2 && n == 4 && a[n - 1] == 9999999998)) {
//                                std::cout << p << "\n";
//                                p_val = p;
//                                break;
//                            }
//                        }
                    }

                }
                temp_sum += a[i];
            }
        }
        std::cout << "100\n";
    }
    return 0;
}