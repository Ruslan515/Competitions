// ccccbbgbidbkhgcdnchgjvfickbgtdlbdtvkvjcbvvid
// Created by ruslan515 on 11.06.23.
//

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    map<int, int> unique;
    int temp;
    for (int i = 0; i < n; ++i) {
        cin >> temp;
        ++unique[temp];
    }

    int answer = 0;
    for (pair<int, int> element: unique) {
        int value = element.second;
        if (value == 1) {
            ++answer;
        }
    }

    cout << answer << "\n";

    return 0;
}