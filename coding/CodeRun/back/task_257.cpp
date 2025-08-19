// https://coderun.yandex.ru/seasons/first_2023/tracks/backend/problem/find-rle-string-length?currentPage=1&difficulty=MEDIUM&pageSize=10&rowNumber=7
// Created by ruslan515 on 24.06.23.
//

#include <bits/stdc++.h>

using namespace std;

struct Segment {
    char c;
    int len;
};

vector<Segment> parse(const string &s) {
    vector<Segment> res;
    for (int i = 0; i < s.size(); i++) {
        int j = i;
        int len = 1;
        if (isdigit(s[i])) {
            while (j < s.size() && isdigit(s[j])) {
                j++;
            }
            len = stoi(s.substr(i, j - i));
        }
        char c = s[j];
        res.push_back({c, len});
        i = j;
    }
    return res;
}

int getCompressedLength(const vector<Segment> &t, int l, int r) {
    int res = 0, cnt = 0;
    for (const auto &seg: t) {
        if (cnt >= r) {
            break;
        }
        int curLen = min(seg.len, r - cnt);
        if (cnt + curLen > l) {
            res += (cnt + curLen <= r) ? curLen : r - cnt - l;
        }
        cnt += curLen;
    }
    return res;
}

int main() {
    string s;
    cin >> s;
    auto t = parse(s);
    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << getCompressedLength(t, l, r) << "\n";
    }
    return 0;
}

//int main() {
//    string s;
//    cin >> s;
//
//    // Построение массива cnt.
//    vector<int> cnt(s.size() + 1);
//    for (int i = 1; i <= s.size(); i++) {
//        cnt[i] = cnt[i-1] + i;
//        if (i < s.size() && s[i] != s[i-1]) {
//            cnt[i]++; // учитываем разделительную букву
//        }
//    }
//
//    // Обработка запросов.
//    int q;
//    cin >> q;
//    while (q--) {
//        int l, r;
//        cin >> l >> r;
//        cout << cnt[r] - cnt[l-1] << endl;
//    }
//
//    return 0;
//}

//string code(string t) {
//    string s = "";
//    int n = t.size();
//    int i = 0;
//    while (i < n) {
//        int count = 1;
//        while (i < n && t[i] == t[i + 1]) {
//            ++i;
//            ++count;
//        }
//        if (count != 1) {
//            s += to_string(count);
//        }
//        char ch = t[i];
//        s += ch;
//        ++i;
//    }
//
//    return s;
//}
//
//string decode(string s) {
//    string t = "";
//    int n = s.size();
//    for (int i = 0; i < n;) {
//        char current = s[i];
//        if (isdigit(current)) {
//            string number = "";
//            while (isdigit(s[i])) {
//                number += s[i];
//                ++i;
//            }
//            char ch = s[i];
//            int count = atoi(number.c_str());
//            for (int j = 0; j < count; ++j) {
//                t += ch;
//            }
//        } else {
//            t += current;
//
//        }
//        ++i;
//    }
//
//    return t;
//}
//
//int solve(string t, int l, int r) {
//    int answer = 0;
//    string subStr = t.substr(l, r - l + 1);
//    string s = code(subStr);
//    answer = s.size();
//
//    return answer;
//}
//
//int main() {
//    ios::sync_with_stdio(false);
//    ios_base::sync_with_stdio(false);
//    cin.tie(0);
//
//    string s;
//    cin >> s;
//    string t = decode(s);
//    int q, l, r;
//    cin >> q;
//    for (int i = 0; i < q; ++i) {
//        cin >> l >> r;
//        cout << solve(t, --l, --r) << "\n";
//    }
//
//    return 0;
//}