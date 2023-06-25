// https://coderun.yandex.ru/seasons/first_2023/tracks/backend/problem/two-cliques?currentPage=1&difficulty=MEDIUM&pageSize=10&rowNumber=2
// Created by ruslan515 on 15.06.23.
//

#include <bits/stdc++.h>

using namespace std;

const int DEFAULT_COLOR = 0;

void dfs(int v, vector<vector<int>> &edges, vector<int> &color, int &cnt, int &k) {
    color[v] = cnt;
    if (cnt == 1) {
        ++k;
    }
    int u;
    for (int i = 0; i < edges[v].size(); ++i) {
        u = edges[v][i];
        if (color[u] == DEFAULT_COLOR) {
            dfs(u, edges, color, cnt, k);
        }
    }
}

void findComponents(vector<vector<int>> &edges, vector<int> &color, int &cnt, int &k) {
    for (int v = 0; v < edges.size(); ++v) {
        if (color[v] == DEFAULT_COLOR) {
            ++cnt;
            dfs(v, edges, color, cnt, k);
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

    vector<int> color(n, DEFAULT_COLOR);
    int cnt = 0;
    int k = 0;
    findComponents(edges, color, cnt, k);
    if (cnt == 2) {
        int z = 0;
        for (int i = 0; i < n; ++i) {
            if (color[i] == 1) {
                ++z;
            }
        }
        cout << z << "\n";

//        cout << k << "\n";

        for (int i = 0; i < n; ++i) {
            if (color[i] == 1) {
                cout << i + 1 << " ";
            }
        }
        cout << "\n";
        for (int i = 0; i < n; ++i) {
            if (color[i] == 2) {
                cout << i + 1 << " ";
            }
        }
    } else {
        cout << -1 << "\n";
    }

    return 0;
}