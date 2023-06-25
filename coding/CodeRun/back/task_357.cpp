// https://coderun.yandex.ru/seasons/first_2023/tracks/backend/problem/substring-graph?currentPage=2&difficulty=EASY&pageSize=10&rowNumber=11
// Created by ruslan515 on 13.06.23.
//

#include <bits/stdc++.h>

using namespace std;

const int SIZE_SUB = 3;

void solve(vector<string> &s) {
    unordered_map<string, unordered_map<string, int>> vertex;
    set<string> nodes;

    int len;
    int countEdges = 0;
    int countVertex = 0;
    for (auto words: s) {
        string u, v;
        len = words.size();
        for (int start = 0; start < words.size() - 3; ++start) {
            u = words.substr(start, SIZE_SUB);
            v = words.substr(start + 1, SIZE_SUB);
            nodes.insert(u);
            nodes.insert(v);
            if (!vertex[u].count(v)) {
                ++countEdges;
            }
            ++vertex[u][v];
        }
    }

    cout << nodes.size() << "\n" << countEdges << "\n";

    for (pair<string, unordered_map<string, int>> edge: vertex) {
        string u, v;
        u = edge.first;
        int w;
        unordered_map<string, int> mp = edge.second;
        for (pair<string, int> x: mp) {
            v = x.first;
            w = x.second;
            cout << u << " " << v << " " << w << "\n";
        }

    }


}

int main() {
    ios::sync_with_stdio(false);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    vector<string> s;
    string temp;
    while (cin >> temp) {
        s.push_back(temp);
    }

    solve(s);

    return 0;
}