// https://coderun.yandex.ru/seasons/first_2023/tracks/backend/problem/calendar-formatting?currentPage=2&difficulty=EASY&pageSize=10&rowNumber=15&compiler=cpp
// Created by ruslan515 on 24.06.23.
//

#include <bits/stdc++.h>

using namespace std;

unordered_map<string, int> mp = {
        {"Monday",    0},
        {"Tuesday",   1},
        {"Wednesday", 2},
        {"Thursday",  3},
        {"Friday",    4},
        {"Saturday",  5},
        {"Sunday",    6},
};

vector<string> solve(int nDays, string weekday, int countWeek) {
    vector<string> answer(countWeek * 7, "");
    int day = mp[weekday];
    for (int i = 0; i < day; ++i) {
        answer[i] = "..";
    }
    for (int i = 0; i < 9; ++i) {
        answer[day + i] = "." + to_string(i + 1);
    }
    for (int i = 9; i < nDays; ++i) {
        answer[day + i] = to_string(i + 1);
    }

    return answer;
}


int main() {
    ios::sync_with_stdio(false);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int nDays;
    string weekday;
    cin >> nDays >> weekday;

    int countChars = nDays + mp[weekday];
    int countWeek = countChars / 7;
    if (countChars % 7 != 0) {
        ++countWeek;
    }
    vector<string> answer = solve(nDays, weekday, countWeek);
    string day;
    for (int i = 0; i < countWeek; ++i) {
        for (int j = 0; j < 7; ++j) {
            day = answer[i * 7 + j];
            if (day != "") {
                cout << day << " ";
            }
        }
        cout << "\n";
    }

    return 0;
}