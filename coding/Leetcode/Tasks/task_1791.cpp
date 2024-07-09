// https://leetcode.com/problems/find-center-of-star-graph/description/?envType=daily-question&envId=2024-06-27
// Created by omega515 on 27.06.24.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findCenter(vector<vector<int>> &edges) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int answer = -1;
        unordered_set<int> st;
        for (auto edge: edges) {
            int u = edge[0];
            int v = edge[1];
            if (st.find(u) != st.end()) {
                answer = u;
                break;
            }
            if (st.find(v) != st.end()) {
                answer = v;
                break;
            }
            st.insert(u);
            st.insert(v);
        }


        return answer;
    }
};

// блок для ускорения кода
int init = [] {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ofstream out("user.out");
    cout.rdbuf(out.rdbuf());
    for (string line; getline(cin, line); cout << '\n') {
        istringstream ss(line);
        char ch;
        int a, b, c, d;
        ss >> ch >> ch >> a >> ch >> b >> ch >> ch >> ch >> c >> ch >> d;
        if (a == c || a == d) cout << a;
        else cout << b;
    }
    exit(0);
    return 0;
}();


int main() {
    vector<vector<int>> edges;
    int answer;
    Solution solve;

    edges = {{1, 2},
             {2, 3},
             {4, 2}};
    answer = 2;
    assert(answer == solve.findCenter(edges));

    edges = {{1, 2},
             {5, 1},
             {1, 3},
             {1, 4}};
    answer = 1;
    assert(answer == solve.findCenter(edges));

    return 0;
}
