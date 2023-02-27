// https://codeforces.com/contest/1799/problem/A
// Created by ruslan515 on 27.02.23.
//

#include<bits/stdc++.h>

using namespace std;

void solving() {
    int n, m;
    cin >> n >> m;
    vector<int> p(m);

    for (int i = 0; i < m; ++i)
        cin >> p[i];
    
    map<int, int> my_map;
    
    for (int i = 1; i <= n; ++i) {
        my_map[i] = -1;
    }
    int memory = 1;
    int num = n;
    for (int i = 0; i < m; ++i) {
        if (num == 0) {
            break;
        }
        if (my_map.count(p[i]) == 0) {
            my_map[p[i]] = 1;
            my_map[num] = memory;
            --num;
        }
        ++memory;
    }
    map<int, int> :: iterator it = my_map.begin();
    for (; it != my_map.end(); it++) {
        if (it->first <= n) {
            cout << it->second << " ";
        }
    }

    cout << "\n";

    return;
}

int main() {
    ios::sync_with_stdio(false);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        solving();
    }

    return 0;
}

