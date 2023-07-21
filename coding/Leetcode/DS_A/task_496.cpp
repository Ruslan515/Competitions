// https://leetcode.com/problems/next-greater-element-i/description/
// Created by Ruslan Khalikov on 21.07.2023.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        vector<int> answer2(n2);
        stack<int> st;
        unordered_map<int, int> mp;
        for (int i = 0; i < n2; ++i) {
            mp[nums2[i]] = i;
            while (!st.empty() && nums2[st.top()] < nums2[i]) {
                int j = st.top();
                answer2[j] = j;
                st.pop();
            }
            st.push(i);
        }
        vector<int> answer1;
        int temp;
        for (int i = 0; i < n1; ++i) {
            temp = mp[nums1[i]];
            temp = answer2[temp];
            answer1.push_back(temp);
        }


        return answer1;
    }
};

int main() {
    vector<int> nums1, nums2, answer;
    Solution solve;

    nums1 = {4, 1, 2}, nums2 = {1, 3, 4, 2};
    answer = {-1, 3, -1};
    assert(answer == solve.nextGreaterElement(nums1, nums2));

    nums1 = {2, 4}, nums2 = {1, 2, 3, 4};
    answer = {3, -1};
    assert(answer == solve.nextGreaterElement(nums1, nums2));

    return 0;
}
