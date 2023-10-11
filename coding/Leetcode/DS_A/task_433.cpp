// https://leetcode.com/problems/minimum-genetic-mutation/description/
// Created by ruslan515 on 04.10.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    const int GEN_LEN = 8;

    int minMutation(string startGene, string endGene, vector<string> &bank) {
        int answer = -1;
        set<string> setBank(bank.begin(), bank.end());
        if (setBank.find(endGene) == setBank.end()) {
            return -1;
        }
        queue<pair<string, int>> q;
        q.push(make_pair(startGene, 0));
        set<string> visited;
        while (!q.empty()) {
            int size_q = q.size();
            for (int i = 0; i < size_q; ++i) {
                auto [current, dist] = q.front();
                q.pop();
                if (visited.find(current) != visited.end()) {
                    continue;
                } else {
                    visited.insert(current);
                }
                if (current == endGene) {
                    return dist;
                }
                for (int j = 0; j < GEN_LEN; ++j) {
                    char currCh = current[j];
                    set<char> s = {'A', 'C', 'G', 'T'};
                    s.erase(currCh);
                    set<char>::iterator it = s.begin();
                    string temp;
                    for (; it != s.end(); ++it) {
                        temp = current;
                        temp[j] = *it;
                        if (setBank.find(temp) != setBank.end()) {
                            q.push(make_pair(temp, dist + 1));
                        }
                    }
                }

            }
        }

        return answer;
    }
};

int main() {
    string startGene, endGene;
    vector<string> bank;
    int answer;
    Solution solve;

    startGene = "AAAAAAAT", endGene = "CCCCCCCC";
    bank = {"AAAAAAAC", "AAAAAAAA", "CCCCCCCC"};
    answer = -1;
    assert(answer == solve.minMutation(startGene, endGene, bank));

    startGene = "AAAAAAAA", endGene = "CCCCCCCC";
    bank = {
            "AAAAAAAA",
            "AAAAAAAC",
            "AAAAAACC",
            "AAAAACCC",
            "AAAACCCC",
            "AACACCCC",
            "ACCACCCC",
            "ACCCCCCC",
            "CCCCCCCA"
    };
    answer = -1;
    assert(answer == solve.minMutation(startGene, endGene, bank));

    startGene = "AACCGGTT", endGene = "AACCGGTA", bank = {"AACCGGTA"};
    answer = 1;
    assert(answer == solve.minMutation(startGene, endGene, bank));

    startGene = "AACCGGTT", endGene = "AAACGGTA", bank = {"AACCGGTA", "AACCGCTA", "AAACGGTA"};
    answer = 2;
    assert(answer == solve.minMutation(startGene, endGene, bank));

    return 0;
}