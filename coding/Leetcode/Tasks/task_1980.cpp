// https://leetcode.com/problems/find-unique-binary-string/description/?envType=daily-question&envId=2025-02-20
// Created by omega515 on 20.02.2025.
//

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    string findDifferentBinaryString(vector<string> &nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        string answer = "";
        unordered_set<string> setNums(nums.begin(), nums.end());
        int n = nums.size();
        queue<string> queue1;
        queue1.push("");
        string current;
        while (!queue1.empty()) {
            int sizeQueue = queue1.size();
            for (int i = 0; i < sizeQueue; ++i) {
                current = queue1.front();
                queue1.pop();
                if (current.size() == n) {
                    if (setNums.find(current) == setNums.end()) {
                        return current;
                    }
                }
                queue1.push(current + "0");
                queue1.push(current + "1");
            }
        }


        return answer;
    }
};

int main() {
    vector<string> nums;
    string answer;
    Solution solve;

    nums = {"01", "10"};
    answer = "00";
    assert(answer == solve.findDifferentBinaryString(nums));

    nums = {"00", "01"};
    answer = "10";
    assert(answer == solve.findDifferentBinaryString(nums));

    nums = {"111", "011", "001"};
    answer = "000";
    assert(answer == solve.findDifferentBinaryString(nums));

    return 0;
}
