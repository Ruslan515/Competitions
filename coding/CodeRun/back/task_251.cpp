// https://coderun.yandex.ru/seasons/first_2023/tracks/backend/problem/symbols-set-min-susbstr/description?currentPage=2&pageSize=10&rowNumber=20&compiler=pypy
// Created by ruslan515 on 12.06.23.
//

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int answer = 0;
    string s;
    set<char> c;
    cin >> s;
    char ch;
    while (cin >> ch) {
        c.insert(ch);
    }
    int n = s.size();
    int k = c.size();
    if (n == k && k == 1) {
        char temp;
        for (auto ch: c) {
            temp = ch;
        }
        if (s[0] == temp) {
            answer = 1;
        }
        cout << answer << "\n";
        return 0;
    }

    answer = INT_MAX;
    for (int start = 0; start < n; ++start) {
        for (int end = start; end < n; ++end) {
            set<char> temp;
            for (int i = start; i <= end; ++i) {
                temp.insert(s[i]);
            }
            if (temp == c) {
                int temp_len = end - start + 1;
                answer = min(answer, temp_len);
            }
        }
    }
    if (answer == INT_MAX) {
        answer = 0;
    }
    cout << answer << "\n";
    return 0;
}