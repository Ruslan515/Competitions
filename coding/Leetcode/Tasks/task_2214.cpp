//
// Created by ruslan515 on 20.01.23.
//

#include <iostream>
#include <vector>
#include <map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    long long minimumHealth(vector<int>& damage, int armor) {
        long long ans = 0;
        int max_damage = INT32_MIN;
        for (int d: damage) {
            ans += d;
            max_damage = max(max_damage, d);
        }
        ans = ans - min(armor, max_damage) + 1;
        return ans;
    }
};


void read_data(vector<int>& damage, int& armor) {
    cin >> armor;
    int t;
    while (cin >> t)
        damage.push_back(t);
    return;
}

int main() {
    vector<int> damage;
    int armor;
    read_data(damage, armor);
    Solution solve;
    cout << solve.minimumHealth(damage, armor);
    return 0;
}