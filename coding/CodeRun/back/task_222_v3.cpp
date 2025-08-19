// https://coderun.yandex.ru/seasons/first_2023/tracks/backend/problem/two-cliques?currentPage=1&difficulty=MEDIUM&pageSize=10&rowNumber=2
// Created by ruslan515 on 15.06.23.
//

#include <bits/stdc++.h>

using namespace std;

bool isBipartiteUtil(vector<vector<int>> edgesRev, int src, vector<int> &colorArr) {
    int n = colorArr.size();
    colorArr[src] = 1;

    // Create a queue (FIFO) of vertex numbers and enqueue
    // source vertex for BFS traversal
    queue<int> q;
    q.push(src);

    // Run while there are vertices in queue (Similar to BFS)
    while (!q.empty()) {
        // Dequeue a vertex from queue
        int u = q.front();
        q.pop();

        for (int v: edgesRev[u]) {
            // Find all non-colored adjacent verticess
            // An edge from u to v exists and destination
            // v is not colored
            if (colorArr[v] == -1) {
                // Assign alternate color to this adjacent
                // v of u
                colorArr[v] = 1 - colorArr[u];
                q.push(v);
            }

                // An edge from u to v exists and destination
                // v is colored with same color as u
            else if (colorArr[v] == colorArr[u])
                return false;
        }
    }

    // If we reach here, then all adjacent vertices can
    // be colored with alternate color
    return true;
}

bool isBipartite(vector<vector<int>> edgesRev, vector<int> &colorArr) {
    // Create a color array to store colors assigned
    // to all vertices. Vertex number is used as index in
    // this array. The value '-1' of  colorArr[i]
    // is used to indicate that no color is assigned to
    // vertex 'i'.  The value 1 is used to indicate first
    // color is assigned and value 0 indicates
    // second color is assigned.
    int n = colorArr.size();

    // One by one check all not yet colored vertices.
    for (int i = 0; i < n; i++)
        if (colorArr[i] == -1)
            if (isBipartiteUtil(edgesRev, i, colorArr) == false)
                return false;

    return true;
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

    vector<int> colorArr(n, -1);
    bool ans = isBipartite(edgesRev, colorArr);
    if (ans) {
        int k = 0;
        for (int c: colorArr) {
            if (c == 1) {
                ++k;
            }
        }
        cout << k << "\n";
        for (int i = 0; i < n; ++i) {
            int c = colorArr[i];
            if (c == 1) {
                cout << i + 1 << " ";
            }
        }
        cout << "\n";
        for (int i = 0; i < n; ++i) {
            int c = colorArr[i];
            if (c == 0) {
                cout << i + 1 << " ";
            }
        }

    } else {
        cout << -1;
    }


    return 0;
}