// https://coderun.yandex.ru/seasons/first_2023/tracks/backend/problem/two-cliques?currentPage=1&difficulty=MEDIUM&pageSize=10&rowNumber=2
// Created by ruslan515 on 15.06.23.
//

#include <bits/stdc++.h>

using namespace std;

int invert(int c) {
    return c == 1 ? 2 : 1;
}

void dfs(vector<vector<int>> edgesRev, vector<int> &color, int v, int c, int &answer) {
    color[v] = c;
    for (int u: edgesRev[v]) {
        if (color[u] == 0) {
            dfs(edgesRev, color, u, invert(c), answer);
        } else if (color[u] == c) {
            answer = -1;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> edges(n, vector<int>());
    int a, b;
    for (int i = 0; i < m; ++i) {
        cin >> a >> b;
        --a;
        --b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    vector<vector<int>> edgesRev;
    set<int> nodes;
    for (int i = 0; i < n; ++i) {
        nodes.insert(i);
    }
    for (int i = 0; i < n; ++i) {
        vector<int> curr = edges[i];
        set<int> currSet;
        for (int v: curr) {
            currSet.insert(v);
        }
        set<int> res;
        set_difference(nodes.begin(), nodes.end(),
                       currSet.begin(), currSet.end(),
                       inserter(res, res.begin()));
        res.erase(i);
        vector<int> r(res.begin(), res.end());
        edgesRev.push_back(r);
    }

    vector<int> color(n, 0);
    int answer = 0;
    for (int i = 0; i < n; ++i) {
        if (color[i] == 0) {
            dfs(edgesRev, color, i, 1, answer);
        }
    }
    if (answer == 0) {
        int k = 0;
        for (int c: color) {
            if (c == 1) {
                ++k;
            }
        }
        cout << k << "\n";
        for (int i = 0; i < n; ++i) {
            int c = color[i];
            if (c == 1) {
                cout << i + 1 << " ";
            }
        }
        cout << "\n";
        for (int i = 0; i < n; ++i) {
            int c = color[i];
            if (c == 2) {
                cout << i + 1 << " ";
            }
        }

    } else {
        cout << answer << "\n";
    }

    return 0;
}