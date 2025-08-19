// https://coderun.yandex.ru/seasons/first_2023/tracks/backend/problem/checkers?currentPage=1&difficulty=EASY&pageSize=10&rowNumber=7
// Created by ruslan515 on 23.06.23.
//

#include <bits/stdc++.h>

using namespace std;

int solve(unordered_map<int, vector<int>> &catProd) {
    int answer = INT32_MAX;
    for (auto el:catProd) {
        vector<int> idx = el.second;
        sort(idx.begin(), idx.end());
        int diff;
        for (int i = 1; i < idx.size(); ++i) {
            diff = idx[i] - idx[i - 1];
            answer = min(diff, answer);
        }
    }

    return answer;
}


int main() {
    ios::sync_with_stdio(false);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int answer;
    int n;
    cin >> n;
    vector<int> product, category;
    unordered_map<int, int> prodCat;
    int prod, cat;
    for (int i = 0; i < n; ++i) {
        cin >> prod >> cat;
        prodCat[prod] = cat;
//        product.push_back(prod);
//        category.push_back(cat);
    }
    vector<int> permut;
    unordered_map<int, vector<int>> catProd;
    int i = 0;
    while (cin >> prod) {
        permut.push_back(prod);
        int cat = prodCat[prod];
        catProd[cat].push_back(i);
        ++i;
    }
    if (permut.size() == catProd.size()) {
        answer = permut.size();
    } else {
        answer = solve(catProd);
    }

    cout << answer << "\n";

    return 0;
}