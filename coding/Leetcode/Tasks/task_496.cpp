// https://leetcode.com/problems/next-greater-element-i/description/
// Created by omega515 on 21.12.24.
//

#include <bits/stdc++.h>

using namespace std;

typedef pair<double, pair<int, int>> pr;

class Solution {
public:
    stack<pair<int, int>> vec2stack(vector<int> &nums) {
        stack<pair<int, int>> answer;
        pair<int, int> p;
        int val, idx, current;
        for (int i = 0; i < nums.size(); ++i) {
            if (answer.empty()) {
                answer.push({nums[i], i});
            } else {
                p = answer.top();
                val = p.first;
                idx = p.second;
                current = nums[i];
                if (current > val) {
                    answer.pop();
                    answer.push({current, i});
                    answer.push({val, idx});
                } else {
                    answer.push({current, i});
                }
            }
        }

        return answer;
    }

    vector<pair<int, int>> vec2vec(vector<int> &nums) {
        vector<pair<int, int>> answer;
        for (int i = 0; i < nums.size(); ++i) {
            answer.push_back({nums[i], i});
        }

        return answer;
    }

    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int n = nums1.size();
        vector<int> answer(n, 0);
//        stack<pair<int, int>> st1 = vec2stack(nums1), st2 = vec2stack(nums2);
        vector<pair<int, int>> st1 = vec2vec(nums1), st2 = vec2vec(nums2);
        sort(st1.begin(), st1.end());
        sort(st2.begin(), st2.end());

        pair<int, int> pair1, pair2;
        int val1, idx1, val2, idx2, targetIdx;
        int j = 0;
        for (int i = 0; i < n; ++i) {
            pair1 = st1[i];
            val1 = pair1.first;
            idx1 = pair1.second;
            targetIdx = -1;
            for (; j < st2.size(); ++j) {
                pair2 = st2[j];
                val2 = pair2.first;
                idx2 = pair2.second;
                if (val2 > val1) {
                    targetIdx = idx2;
                    break;
                }
            }

            answer[idx1] = targetIdx;
        }


        return answer;
    }
};


int main() {
    vector<int> nums1, nums2;
    vector<int> answer;
    Solution solve;

    nums1 = {4, 1, 2}, nums2 = {1, 3, 4, 2};
    answer = {-1, 3, -1};
    assert(answer == solve.nextGreaterElement(nums1, nums2));

    nums1 = {2, 4}, nums2 = {1, 2, 3, 4};
    answer = {3, -1};
    assert(answer == solve.nextGreaterElement(nums1, nums2));
    return 0;
}
