// https://coderun.yandex.ru/seasons/first_2023/tracks/backend/problem/two-cliques?currentPage=1&difficulty=MEDIUM&pageSize=10&rowNumber=2
// Created by ruslan515 on 15.06.23.
//

#include <bits/stdc++.h>

using namespace std;


void dfs(int v, int c, vector<vector<int>> &graph, vector<int> &color, vector<bool> &visited) {
    visited[v] = true;
    color[v] = c;
    for (int u: graph[v]) {
        if (!visited[u]) {
            dfs(u, 1 - c, graph, color, visited);
        } else if (color[u] == c) {
            cout << -1 << endl;
            exit(0);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n, vector<int>());
    vector<int> color(n, -1); // Цвета вершин (0 или 1)
    vector<bool> visited(n); // Посещенные вершины

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a - 1].push_back(b - 1);
        graph[b - 1].push_back(a - 1);
    }

    vector<vector<int>> edgesRev;
    set<int> nodes;
    for (int i = 0; i < n; ++i) {
        nodes.insert(i);
    }
    for (int i = 0; i < n; ++i) {
        vector<int> curr = graph[i];
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


    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i, 0, edgesRev, color, visited);
        }
    }

    vector<int> part1, part2;
    for (int i = 0; i < n; i++) {
        if (color[i] == 0) {
            part1.push_back(i + 1);
        } else {
            part2.push_back(i + 1);
        }
    }

    cout << part1.size() << endl;
    for (int x: part1) {
        cout << x << " ";
    }
    cout << endl;

//    cout << part2.size() << endl;
    for (int x: part2) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}