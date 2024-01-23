// https://leetcode.com/problems/top-k-frequent-words/description/
// Created by omega515 on 21.01.24.
//

#include <bits/stdc++.h>

using namespace std;

typedef pair<string, int> pd;

struct myComp {
    constexpr bool operator()(
            pd const &a,
            pd const &b
    )
    const noexcept {
        if (a.second < b.second) {
            return a.second < b.second;
        } else if (a.second == b.second) {
            return a.first < b.first;
        } else {
            return a.second < b.second;
        }

    }
};

class Solution {
public:
    vector<string> topKFrequent(vector<string> &words, int k) {
        vector<string> answer(k);
        map<string, int> mp;
        for (string word: words) {
            --mp[word];
        }

        priority_queue<pd, vector<pd>, myComp> heap;

        for (pair<string, int> p: mp) {
            heap.push(p);
            if (heap.size() > k) {
                heap.pop();
            }
        }
        for (int i = k - 1; i >= 0; --i) {
            answer[i] = heap.top().first;
//            cout << heap.top().first << " " << heap.top().second << "\n";
            heap.pop();
        }


        return answer;
    }
};


int main() {
    vector<string> words;
    int k;
    vector<string> answer;

    Solution solve;

    words = {"i", "love", "leetcode", "i", "love", "coding"}, k = 2;
    answer = {"i", "love"};
    assert(answer == solve.topKFrequent(words, k));

    words = {"the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"}, k = 4;
    answer = {"the", "is", "sunny", "day"};
    assert(answer == solve.topKFrequent(words, k));

    return 0;
}