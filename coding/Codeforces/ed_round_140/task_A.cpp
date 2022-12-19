// https://codeforces.com/contest/1767/problem/A
// Created by ruslan515 on 16.12.22.
//

#include <iostream>
#include <vector>

using namespace std;

string CutTriangle(const vector<pair<int, int>>& triangle) {
    string ans = "YES";
    int count = 0;
    for (int i = 0; i < 3; ++i) {
        int dx = (triangle[i].first - triangle[(i + 1) % 3].first);
        int dy = (triangle[i].second - triangle[(i + 1) % 3].second);
        if (dx == 0) {
            ++count;
        }
        if (dy == 0) {
            ++count;
        }
    }
    if (count == 2) {
        ans = "NO";
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    string s;
    for (int i = 0; i < t; ++i) {
        getline(cin, s);
        vector<pair<int, int>> triangle;
        for (int i = 0; i < 3; ++i) {
            int x, y;
            cin >> x >> y;
            triangle.push_back(make_pair(x, y));
        }
        string ans = CutTriangle(triangle);
        cout << ans << "\n";
    }

    return 0;
}