// https://leetcode.com/contest/biweekly-contest-115/problems/last-visited-integers/
// Created by ruslan515 on 14.10.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    const string prev = "prev";

    vector<int> lastVisitedIntegers(vector<string> &words) {
        vector<int> answer;
        int k = 0;
        vector<string> nums, nums_reverse;
        int n = words.size();
        string word;
        for (int i = 0; i < n; ++i) {
            word = words[i];
            if (word == prev) {
                int k = 0;
                string curr;
                for (int j = i - 1; j >= 0; --j) {
                    curr = words[j];
                    if (curr == prev) {
                        ++k;
                    } else {
                        break;
                    }
                }
                int temp = -1;
                ++k;
                if (k <= nums.size()) {
                    vector<string> nums_reverse = nums;
                    reverse(nums_reverse.begin(), nums_reverse.end());
                    int idx = k - 1;
                    temp = stoi(nums_reverse[idx]);
                }
                answer.push_back(temp);


            } else {
                nums.push_back(word);
            }
        }

        return answer;
    }
};

int main() {
    vector<string> words;
    vector<int> answer;
    Solution solve;

    words = {"prev", "prev", "2", "prev", "prev"};
    answer = {-1, -1, 2, -1};
    assert(answer == solve.lastVisitedIntegers(words));

    words = {"1", "prev", "2", "prev", "prev"};
    answer = {1, 2, 1};
    assert(answer == solve.lastVisitedIntegers(words));


    words = {"1", "2", "prev", "prev", "prev"};
    answer = {2, 1, -1};
    assert(answer == solve.lastVisitedIntegers(words));


    return 0;
}

