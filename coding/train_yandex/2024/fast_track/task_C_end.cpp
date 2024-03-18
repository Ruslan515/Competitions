#include <bits/stdc++.h>

const int N = pow(10, 9);
const int MAX_SIZE = (int) (log(N) / log(2.0)) + 1;

using namespace std;

void create_max_table(vector<vector<int>> &table_min, vector<int> &a, int n) {
    for (int i = 1; i < n + 1; ++i) {
        table_min[i][0] = i;
    }

    for (int k = 1; (1 << k) < n + 1; ++k) {
        for (int l = 1; l + (1 << k) - 1 < n + 1; ++l) {
            if (a[table_min[l][k - 1]] > a[table_min[l + (1 << (k - 1))][k - 1]]) {
                table_min[l][k] = table_min[l][k - 1];
            } else {
                table_min[l][k] = table_min[l + (1 << (k - 1))][k - 1];
            }
        }
    }
}


void create_min_table(vector<vector<int>> &table_min, vector<int> &a, int n) {
    for (int i = 1; i < n + 1; ++i) {
        table_min[i][0] = i;
    }

    for (int k = 1; (1 << k) < n + 1; ++k) {
        for (int l = 1; l + (1 << k) - 1 < n + 1; ++l) {
            if (a[table_min[l][k - 1]] < a[table_min[l + (1 << (k - 1))][k - 1]]) {
                table_min[l][k] = table_min[l][k - 1];
            } else {
                table_min[l][k] = table_min[l + (1 << (k - 1))][k - 1];
            }
        }
    }
}
}

int rmq(vector<vector<int>> &table_min, vector<int> &a, int l, int r) {
    int k = (int) (log(1.0 * r - l + 1) / log(2.0));
    int result;

    if (a[table_min[r - (1 << k) + 1][k]] < a[table_min[l][k]]) {
        result = table_min[r - (1 << k) + 1][k];
    } else {
        result = table_min[l][k];
    }

    return result;
}

int rmq_max(vector<vector<int>> &table_min, vector<int> &a, int l, int r) {
    int k = (int) (log(1.0 * r - l + 1) / log(2.0));
    int result;

    if (a[table_min[r - (1 << k) + 1][k]] > a[table_min[l][k]]) {
        result = table_min[r - (1 << k) + 1][k];
    } else {
        result = table_min[l][k];
    }

    return result;
}

int main() {
    ios::sync_with_stdio(false);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> temps(2 * n + 1 + 1);
    for (int i = 1; i < 2 * n + 2; ++i) {
        cin >> temps[i];
    }

    vector<vector<int>> table_min(n + 1, vector<int>(MAX_SIZE));
//    int table_min[n + 1][MAX_SIZE];
    create_min_table(table_min, temps, n);

    vector<vector<int>> table_max(n + 1, vector<int>(MAX_SIZE));
//    int table_max[n + 1][MAX_SIZE];
    create_max_table(table_max, temps, n);

    int b, tMin, tMax, dMin, dMax, left, right;
    cin >> b;
    for (int k = 0; k < b; ++k) {
        cin >> tMin >> tMax >> dMin >> dMax;
        left = n + dMin;
        right = n + dMax;
        int min_temp = temps[rmq(table_min, temps, left, right + 1)];
        int max_temp = temps[rmq_max(table_max, temps, left, right + 1)];;
        bool low = tMin > max_temp;
        bool high = min_temp > tMax;
        if (low || high) {
            cout << "no\n";
        } else {
            cout << "yes\n";
        }

    }


//    int rmq_current = 0;
//    int current_u;
//    int current_v;
//
//    for (int i = 1; i < m; ++i) {
//        if (u > v) {
//            rmq_current = a[rmq(table_min, a, v, u)];
//        } else {
//            rmq_current = a[rmq(table_min, a, u, v)];
//        }
//        u = ((MAX_SIZE * u + 751 + rmq_current + 2 * i) % n) + 1;
//        v = ((13 * v + 593 + rmq_current + 5 * i) % n) + 1;
//    }
//
//    if (u > v) {
//        rmq_current = a[rmq(table_min, a, v, u)];
//    } else {
//        rmq_current = a[rmq(table_min, a, u, v)];
//    }
//
//
//    cout << u << " " << v << " " << rmq_current << "\n";

    return 0;
}