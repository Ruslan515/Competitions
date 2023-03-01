// https://codeforces.com/contest/1796/problem/A
// Created by ruslan515 on 28.02.23.
//

#include <bits/stdc++.h>

using namespace std;

const string TEMPLATE = "FBFBFBFFBFBFFBFFBFBFFBFFBFBFFBFFBFBFFBFFBFBFFBFFBFBFFBFFBFBFFBFFBFBFFBFFBFBFFBFFBFBFFBFFB";

string correct = "";
int size_correct = 0;

void create_correct(){
    for(int i = 1; i < 151; ++i) {
        if (i % 3 == 0) {
            correct += "F";
        }
        if (i % 5 == 0) {
            correct += "B";
        }
    }
    size_correct = correct.size();
}

//string solving() {
//    string ans = "YES";
//    int k;
//    cin >> k;
//    string s;
//    cin >> s;
//    size_t pos = TEMPLATE.find(s);
//    if (pos == string::npos) {
//        ans = "NO";
//    }
//
//    return ans;
//}

string solving() {
    string ans = "YES";
    int k;
    cin >> k;
    string s;
    cin >> s;

    size_t pos = correct.find(s);
    if (pos == string::npos) {
        ans = "NO";
    }

    return ans;
}


int main() {
    ios::sync_with_stdio(false);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    create_correct();
    for (int i = 0; i < t; ++i) {
        cout << solving() << "\n";
    }

    return 0;
}