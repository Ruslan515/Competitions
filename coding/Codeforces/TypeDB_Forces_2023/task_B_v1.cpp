//
// Created by ruslan515 on 29.01.23.
//

#include <bits/stdc++.h>

using namespace std;

void solving() {
    int n;
    cin >> n;
    int answer = 0;
    int current_N = n;
    int max_cnt = 1;
    map<int, int> my_map;
    for (auto i = 2; i * i < n + 1; ++i) {
        if (current_N % i == 0) {
            int count = 0;
            while (current_N % i == 0) {
                ++count;
                current_N /= i;
            }
            my_map[i] = count;
            if (count > max_cnt) {
                max_cnt = count;
            }
        }
    }
    if (current_N != 1) {
        my_map[current_N] = 1;
    }
    for (int i = 0; i < max_cnt + 1; ++i) {
        int curr = 1;
        map<int, int> :: iterator it = my_map.begin();
        for (; it != my_map.end(); ++it) {
            int val = it->second;
            if (val > 0) {
                int key = it->first;
                my_map[key]--;
                curr *= key;
            }
        }
        answer += curr;
    }
    --answer;
    cout << answer << "\n";

    return;
}

int main() {
    ios::sync_with_stdio(false);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    for(int i = 0; i < t; ++i) {
        solving();
    }

    return 0;
}