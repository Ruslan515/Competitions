// https://coderun.yandex.ru/seasons/first_2023/tracks/backend/problem/merge-jsons-2?compiler=cpp-back
// Created by ruslan515 on 21.06.23.
//


#include <bits/stdc++.h>
#include "json.hpp"

using namespace std;
using namespace nlohmann;

json solve(vector<string> fids, int n, int m) {
    vector<json> arr;
    for (auto fid: fids) {
        json j = json::parse(fid);
        json jj = j["offers"];
        for (json::iterator it = jj.begin(); it != jj.end(); ++it) {
            arr.push_back(*it);
        }
    }

    json js;
    js["offers"] = json::array();
    int x = arr.size();
    int size = min(m, x);
    for (int i = 0; i < size; ++i) {
        js["offers"].push_back(arr[i]);
    }


    return js;
}

int main() {
    ios::sync_with_stdio(false);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<string> fids;
    string temp;
    getline(cin, temp, '\n');
    for (int i = 0; i < n; ++i) {
        getline(cin, temp, '\n');
        fids.push_back(temp);
    }

    json answer = solve(fids, n, m);
    cout << answer << "\n";

    return 0;
}
