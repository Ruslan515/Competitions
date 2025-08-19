// https://coderun.yandex.ru/seasons/first_2023/tracks/backend/problem/rocks-and-jewels?currentPage=1&difficulty=EASY&pageSize=10&rowNumber=9
// Created by ruslan515 on 16.06.23.
//

#include <bits/stdc++.h>

using namespace std;

int solve(string j, string s) {
    int answer = 0;
    set<char> stJ;
    for(char ch: j) {
        stJ.insert(ch);
    }

    for(char ch: s) {
        if (stJ.find(ch) != stJ.end()) {
            ++answer;
        }
    }

    return answer;
}

int main() {
    ios::sync_with_stdio(false);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string j, s;
    cin >> j >> s;
    int answer = solve(j, s);

    cout << answer;

    return 0;
}