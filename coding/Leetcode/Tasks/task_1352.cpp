// https://leetcode.com/problems/product-of-the-last-k-numbers/description/?envType=daily-question&envId=2025-02-14
// Created by omega515 on 14.02.25.
//

#include <bits/stdc++.h>

using namespace std;


class ProductOfNumbers {
public:
    vector<int> prefix;
    vector<int> nums;

    ProductOfNumbers() {
        prefix.push_back(1);
    }

    void add(int num) {
        this->nums.push_back(num);
        int idx = this->prefix.size() - 1;
        int val = this->prefix[idx];
        if (val == 0) {
            this->prefix.push_back(num);
        } else {
            this->prefix.push_back(num * prefix[idx]);
        }

        if (num == 0) {
            for (int i = 1; i < idx + 1; ++i) {
                prefix[i] = 0;
            }
        }
    }

    int getProduct(int k) {
        int answer;
        int idx = this->prefix.size() - k;
        int val = this->prefix[idx];
        int last = this->prefix[prefix.size() - 1];
        if (val != 0) {
            answer = last / val * this->nums[idx - 1];
        } else {
            answer = 0;
        }


//        int idx = prefix.size() - k - 1;
//        int prev = prefix[idx];
//        int curr = prefix[idx + 1];
//
//        int last = prefix[prefix.size() - 1];
//        if (prev != 0) {
//            answer = last / prev;
//        } else if (prev == 0 && curr != 0) {
//            answer = last;
//        } else {
//            answer = 0;
//        }

        return answer;
    }
};

int main() {
    ProductOfNumbers *productOfNumbers = new ProductOfNumbers();
    productOfNumbers->add(3);        // [3]
    productOfNumbers->add(0);        // [3,0]
    productOfNumbers->add(2);        // [3,0,2]
    productOfNumbers->add(5);        // [3,0,2,5]
    productOfNumbers->add(4);        // [3,0,2,5,4]
    assert(20 == productOfNumbers->getProduct(2)); // return 20. The product of the last 2 numbers is 5 * 4 = 20
    assert(40 == productOfNumbers->getProduct(3)); // return 40. The product of the last 3 numbers is 2 * 5 * 4 = 40
    assert(0 == productOfNumbers->getProduct(4)); // return 0. The product of the last 4 numbers is 0 * 2 * 5 * 4 = 0
    productOfNumbers->add(8);        // [3,0,2,5,4,8]
    assert(32 == productOfNumbers->getProduct(2)); // return 32. The product of the last 2 numbers is 4 * 8 = 32

    return 0;
}

