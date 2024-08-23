// https://leetcode.com/problems/design-an-ordered-stream/description/
// Created by omega515 on 21.08.24.
//

#include <bits/stdc++.h>

using namespace std;

class OrderedStream {
private:
    vector<string> stream;
    int ptr = 0;
    int size;
public:
    OrderedStream(int n) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);


        this->stream.resize(n);
        this->size = n;
    }

    vector<string> insert(int idKey, string value) {
        this->stream[idKey - 1] = value;
        vector<string> answer;
        string current;
        for (; ptr < this->size; ++ptr) {
            current = this->stream[ptr];
            if (current == "") {
                break;
            }
            answer.push_back(current);
        }


        return answer;
    }
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(idKey,value);
 */

int main() {
    vector<string> ans;
    OrderedStream *os = new OrderedStream(5);

    ans = {};
    assert(ans == os->insert(3, "c"));

    ans = {"a"};
    assert(ans == os->insert(1, "a"));

    ans = {"b", "c"};
    assert(ans == os->insert(2, "b"));

    ans = {};
    assert(ans == os->insert(5, "e"));

    ans = {"d", "e"};
    assert(ans == os->insert(4, "d"));

    return 0;
}
