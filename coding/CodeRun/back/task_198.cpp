// https://coderun.yandex.ru/seasons/first_2023/tracks/backend/problem/trading-ya-intern?currentPage=1&difficulty=EASY&pageSize=10&rowNumber=6
// Created by ruslan515 on 20.06.23.
//

#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <assert.h>
#include <algorithm>
#include <iomanip>
#include <time.h>
#include <math.h>
#include <bitset>

#pragma comment(linker, "/STACK:256000000")

using namespace std;

typedef long long int ll;
typedef long double ld;

const int INF = 1000 * 1000 * 1000 + 21;
const ll LLINF = (1ll << 60) + 5;
const int MOD = 1000 * 1000 * 1000 + 7;

const int MAX_N = 100 * 1000 + 227;
const int MAX_K = 105;

int n, k;
int arr[MAX_N];
ll dp_l[MAX_N][MAX_K];
ll dp_r[MAX_N][MAX_K];

void solve() {
    scanf("%d%d", &n, &k);

    ll ans = -LLINF;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
        ans = max(ans, (ll) arr[i]);
    }

    if (ans <= 0) {
        printf("%lld\n", ans);
        return;
    }

    for (int i = 0; i <= k; ++i) {
        dp_l[n + 1][i] = 0;
        dp_r[n + 1][i] = 0;
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= k; ++j) {
            dp_l[i][j] = max(0ll, dp_l[i - 1][j] + arr[i - 1]);
            if (j) {
                dp_l[i][j] = max(dp_l[i][j], dp_l[i - 1][j - 1]);
            }

            ans = max(ans, dp_l[i][j]);
        }
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= k; ++j) {
            dp_l[i][j] = dp_l[i - 1][j] + arr[i - 1];
            if (j) {
                dp_l[i][j] = max(dp_l[i][j], dp_l[i - 1][j - 1]);
            }
        }
    }

    for (int i = n; i >= 1; --i) {
        for (int j = 0; j <= k; ++j) {
            dp_r[i][j] = dp_r[i + 1][j] + arr[i - 1];
            if (j) {
                dp_r[i][j] = max(dp_r[i][j], dp_r[i + 1][j - 1]);
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= k; ++j) {
            if (i != 1) {
                dp_l[i][j] = max(dp_l[i][j], dp_l[i - 1][j]);
            }
            if (j) {
                dp_l[i][j] = max(dp_l[i][j], dp_l[i][j - 1]);
            }
        }
    }

    for (int i = n; i >= 1; --i) {
        for (int j = 0; j <= k; ++j) {
            if (i != n) {
                dp_r[i][j] = max(dp_r[i][j], dp_r[i + 1][j]);
            }
            if (j) {
                dp_r[i][j] = max(dp_r[i][j], dp_r[i][j - 1]);
            }
        }
    }

    for (int i = 1; i < n; ++i) {
        for (int j = 0; j <= k; ++j) {
            ans = max(ans, dp_l[i][j] + dp_r[i + 1][k - j]);
        }
    }

    printf("%lld\n", ans);
}

int main() {
#ifdef CH_EGOR
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#else
    //freopen("", "r", stdin);
    //freopen("", "w", stdout);
#endif

    int t;
    scanf("%d", &t);
    while (t--) {
        solve();
    }

    return 0;
}