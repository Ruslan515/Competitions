// https://coderun.yandex.ru/seasons/first_2023/tracks/backend/problem/sorting-reverse-order?currentPage=1&difficulty=EASY&pageSize=10&rowNumber=10
// Created by ruslan515 on 19.06.23.
//

#define CURL_STATICLIB

#include <bits/stdc++.h>
#include <curl/curl.h>
#include "json.hpp"

using namespace std;
using namespace nlohmann;

vector<int> parcero(string in) {
    auto j3 = json::parse(in);
    vector<int> out;
    for(json::iterator it = j3.begin(); it != j3.end();++it){
        cout << *it << " ";
        out.push_back(*it);
    }

    return out;
}

int main() {
    ios::sync_with_stdio(false);
    ios_base::sync_with_stdio(false);
    cin.tie(0);


    string in = "", temp;
    while (cin >> temp) {
        in += temp;
    }
    vector<int> answer = parcero(in);
    for (int num: answer) {
        cout << num << "\n";
    }

    return 0;
}