//
// Created by omega515 on 27.06.24.
//

//#include <bits/stdc++.h>
//
//using namespace std;
//
//string solving() {
//    int x, y;
//    cin >> x >> y;
//    string answer = "YES";
//    int dist = abs(x) + abs(y);
//
//    if (y < dist) {
//        answer = "NO";
//    }
//
//    return answer;
//}
//
//
//int main() {
//    ios::sync_with_stdio(false);
//    ios_base::sync_with_stdio(false);
//    cin.tie(0);
//
//    int n;
//    cin >> n;
//    for (int i = 0; i < n; ++i) {
//        cout << solving() << "\n";
//    }
//
//    return 0;
//}


#include <iostream>
#include <cmath>

int main() {
    int n;
    std::cin >> n;

    for (int i = 0; i < n; ++i) {
        int x, y;
        std::cin >> x >> y;

        // Вычисляем количество шагов, необходимых для достижения координат монеты
        int dx = std::abs(x);
        int dy = std::abs(y);

        // Монокарп может собрать монету, если max(dx, dy) <= y
        if (std::max(dx, dy) <= y) {
            std::cout << "YES\n";
        } else {
            std::cout << "NO\n";
        }
    }

    return 0;
}