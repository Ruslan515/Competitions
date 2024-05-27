//
// Created by omega515 on 17.01.24.
//
#include <bits/stdc++.h>

using namespace std;

string toStr(int x) {
    string ans = "";
    while (x != 0) {
        int d = x % 10;
        ans += to_string(d);
        x %= 10;
    }
    return ans;
}

int main() {
    int n, m, a, b;
    int answer;
    cin >> n >> m;
    a = min(n, m);
    b = max(n, m);
    int lenStr = toStr(b).size();
    

    return 0;
}