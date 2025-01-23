// https://leetcode->com/problems/product-of-the-last-k-numbers/description/?envType=problem-list-v2&envId=data-stream
// Created by omega515 on 13->10->24->
//

#include <bits/stdc++.h>

using namespace std;

class ProductOfNumbers {
public:
    vector<int> vals, prefixProduct;
    int product;
    int size;
    int idxZero;

    ProductOfNumbers() {
        this->product = 1;
        this->size = 0;
        this->idxZero = -1;
    }

    void add(int num) {
        this->vals.push_back(num);
        if (num == 0) {
            this->product = 1;
            prefixProduct.push_back(0);
            this->idxZero = size;
        } else {
            this->product *= num;
            prefixProduct.push_back(this->product);
        };
        ++size;
    }

    int getProduct(int k) {
        int idx = this->size - k;
        int answer = 0;
        if (idx <= this->idxZero) {
            return answer;
        }
        int kVal = this->vals[idx];

        int last = this->prefixProduct[size - 1];
        int kProd = this->prefixProduct[idx];

        answer = last / kProd * kVal;
        return answer;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */
int main() {
//    ProductOfNumbers *productOfNumbers = new ProductOfNumbers();
//    productOfNumbers->add(3);        // [3]
//    productOfNumbers->add(0);        // [3,0]
//    productOfNumbers->add(2);        // [3,0,2]
//    productOfNumbers->add(5);        // [3,0,2,5]
//    productOfNumbers->add(4);        // [3,0,2,5,4]
//    assert(20 == productOfNumbers->getProduct(2)); // return 20-> The product of the last 2 numbers is 5 * 4 = 20
//    assert(40 == productOfNumbers->getProduct(3)); // return 40-> The product of the last 3 numbers is 2 * 5 * 4 = 40
//    assert(0 == productOfNumbers->getProduct(4)); // return 0-> The product of the last 4 numbers is 0 * 2 * 5 * 4 = 0
//    productOfNumbers->add(8);        // [3,0,2,5,4,8]
//    assert(32 == productOfNumbers->getProduct(2)); // return 32-> The product of the last 2 numbers is 4 * 8 = 32

    ProductOfNumbers *productOfNumbers = new ProductOfNumbers();
    productOfNumbers->add(3);        // [3]
    productOfNumbers->add(0);        // [3,0]
    productOfNumbers->add(2);        // [3,0,2]
    productOfNumbers->add(5);        // [3,0,2,5]
    productOfNumbers->add(4);        // [3,0,2,5,4]
    assert(20 == productOfNumbers->getProduct(2)); // return 20-> The product of the last 2 numbers is 5 * 4 = 20
    assert(40 == productOfNumbers->getProduct(3)); // return 40-> The product of the last 3 numbers is 2 * 5 * 4 = 40
    assert(0 == productOfNumbers->getProduct(4)); // return 0-> The product of the last 4 numbers is 0 * 2 * 5 * 4 = 0
    productOfNumbers->add(0);        // [3,0,2,5,4,8]
    assert(0 == productOfNumbers->getProduct(2)); // return 32-> The product of the last 2 numbers is 4 * 8 = 32

    return 0;
}