// https://leetcode.com/problems/all-oone-data-structure/description/?envType=daily-question&envId=2024-09-29
// Created by omega515 on 29.09.24.
//

#include <bits/stdc++.h>

using namespace std;

class AllOne {
public:
    unordered_map<string, int> cntDict;
    int maxCnt, minCnt;
    string maxS, minS;

    AllOne() {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        this->maxCnt = 0;
        this->minCnt = 0;
        this->minS = "";
        this->maxS = "";
    }

    void inc(string key) {
        if (this->cntDict.size() == 0) {
            ++cntDict[key];
            int val = cntDict[key];
            this->maxCnt = val;
            this->maxS = key;
            this->minCnt = val;
            this->minS = key;
            return;
        }
        ++cntDict[key];
        int val = cntDict[key];
        if (val > this->maxCnt) {
            this->maxCnt = val;
            this->maxS = key;
        }
        if (val < this->minCnt) {
            this->minCnt = val;
            this->minS = key;
        }

    }

    void dec(string key) {
        --cntDict[key];
        int val = cntDict[key];
        if (val < minCnt) {
            minCnt = val;
            minS = key;
        }
    }

    string getMaxKey() {
        string answer = "";
        if (!this->cntDict.empty()) {
            answer = this->maxS;
        }
        return answer;
    }

    string getMinKey() {
        string answer = "";
        if (!this->cntDict.empty()) {
            answer = this->minS;
        }
        return answer;
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */

int main() {
    AllOne *allOne = new AllOne();
    allOne->inc("hello");
    allOne->inc("hello");
    assert("hello" == allOne->getMaxKey()); // return "hello"
    assert("hello" == allOne->getMinKey()); // return "hello"
    allOne->inc("leet");
    assert("hello" == allOne->getMaxKey()); // return "hello"
    assert("leet" == allOne->getMinKey()); // return "leet"
    return 0;
}