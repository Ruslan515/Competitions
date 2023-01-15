// https://leetcode.com/problems/convert-the-temperature/
// Created by ruslan515 on 15.01.23.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<double> convertTemperature(double celsius) {
        vector<double> ans;
        double kelvin = celsius + 273.15;
        double fahr = celsius * 1.80 + 32.00;
        ans.push_back(kelvin);
        ans.push_back(fahr);
        return ans;
    }
};

void read_data(double& celsius) {
    cin >> celsius;

    return;
}

int main() {
    double celsius;
    read_data(celsius);
    Solution solve;
    for(double i: solve.convertTemperature(celsius)) {
        cout << i << " ";
    }
    return 0;
}