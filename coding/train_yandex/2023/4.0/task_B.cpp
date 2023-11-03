// https://contest.yandex.ru/contest/53027/problems/B/
// Created by ruslan515 on 03.11.23.
//

#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b) {
    if (a == 0) {
        return b;
    }
    return gcd(b % a, a);
}

pair<int, int> solve(int a, int b, int c, int d) {
    pair<int, int> answer;
    int d1 = a * d + c * b;
    int d2 = b * d;
    int dd = gcd(d1, d2);
    d1 /= dd;
    d2 /= dd;
    answer = make_pair(d1, d2);

    return answer;
}

int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    pair<int, int> answer = solve(a, b, c, d);
    cout << answer.first << " " << answer.second << "\n";


    return 0;
}