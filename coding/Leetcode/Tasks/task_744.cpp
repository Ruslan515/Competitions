// https://leetcode.com/problems/find-smallest-letter-greater-than-target/
// Created by ruslan515 on 09.06.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    char nextGreatestLetter(vector<char> &letters, char target) {
        char first = letters[0];
        char answer = first;
        int n = letters.size();
        char last = letters[n - 1];
        if (target < first || target > last) {
            answer = first;
        } else {
            int left = 0;
            int right = n - 1;
            while (left <= right) {
                int middle = left + (right - left) / 2;
                char temp = letters[middle];
                if (temp > target) {
                    right = middle - 1;
                } else if (temp < target) {
                    left = middle + 1;
                } else {
                    if (middle + 1 != n) {
                        while (middle < n - 1 && letters[middle] == letters[middle + 1]) {
                            ++middle;
                        }
                        if (middle + 1 != n) {
                            answer = letters[middle + 1];
                        } else {
                            answer = first;
                        }

                    } else {
                        answer = first;
                    }
                    return answer;
                }
            }
            answer = letters[left];
        }

        return answer;
    }
};

int main() {
    char target;
    vector<char> letters;
    char answer;
    Solution solve;

    letters = {'e','e','g','g'}, target = 'g';
    answer = 'e';
    assert(answer == solve.nextGreatestLetter(letters, target));

    letters = {'c', 'f', 'j'}, target = 'j';
    answer = 'c';
    assert(answer == solve.nextGreatestLetter(letters, target));

    letters = {'c', 'f', 'j'}, target = 'd';
    answer = 'f';
    assert(answer == solve.nextGreatestLetter(letters, target));

    letters = {'c', 'f', 'j'}, target = 'a';
    answer = 'c';
    assert(answer == solve.nextGreatestLetter(letters, target));

    letters = {'c', 'f', 'j'}, target = 'c';
    answer = 'f';
    assert(answer == solve.nextGreatestLetter(letters, target));

    letters = {'x', 'x', 'y', 'y'}, target = 'z';
    answer = 'x';
    assert(answer == solve.nextGreatestLetter(letters, target));

    return 0;
}