// https://leetcode.com/contest/weekly-contest-421/problems/find-the-maximum-factor-score-of-array/description/
// Created by omega515 on 27.10.24.
//

#include <bits/stdc++.h>

using namespace std;

//class Solution {
//public:
//    int lengthAfterTransformations(string s, int t) {
//        ios_base::sync_with_stdio(false);
//        cin.tie(NULL);
//        cout.tie(NULL);
//
//        int answer = s.size();
//        unordered_map<char, int> mp;
//        for (char ch: s) {
//            cout << ch << " " << (int) ch << "\n";
//            ++mp[ch];
//        }
//        for (int i = 0; i < t; ++i) {
//            unordered_map<char, int>::iterator it = mp.begin();
//            char key;
//            int value = it->second;
//            unordered_map<char, int> tmpMap;
//            for (; it != mp.end(); ++it) {
//                key = it->first;
//                if (key == 'z') {
//                    ++mp['a'];
//                    ++mp['b'];
//                    ++answer;
//                }
//                int x = (int) key;
//                char next = (char) (x + 1) % 97 + 97;
//                for (int j = 0; j < value; ++j) {
//                    --mp[key];
//                    ++tmpMap[next];
//                }
//                if (mp[key] == 0) {
//                    mp.erase(key);
//                }
//            }
//            mp = tmpMap;
//
//        }
//
//        return answer;
//    }
//};
class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        const int MOD = 1000000007;
        vector<long long> count(26, 0);  // счетчик для каждой буквы

        // Подсчитываем начальное количество каждой буквы
        for(char c : s) {
            count[c - 'a']++;
        }

        // Для каждой трансформации
        for(long long i = 0; i < t; i++) {
            vector<long long> next(26, 0);

            // Обрабатываем каждую букву
            for(int j = 0; j < 26; j++) {
                if(j == 25) {  // если 'z'
                    // 'z' превращается в "ab"
                    next[0] = (next[0] + count[j]) % MOD;  // добавляем 'a'
                    next[1] = (next[1] + count[j]) % MOD;  // добавляем 'b'
                } else {
                    // любая другая буква превращается в следующую
                    next[j + 1] = (next[j + 1] + count[j]) % MOD;
                }
            }
            count = next;
        }

        // Подсчитываем общую длину
        long long totalLength = 0;
        for(long long num : count) {
            totalLength = (totalLength + num) % MOD;
        }

        return totalLength;
    }
};

int main() {
    string s;
    int t;
    int answer;
    Solution solve;

    s = "v", t = 7;
    answer = 2;
    assert(answer == solve.lengthAfterTransformations(s, t));

    s = "abcyy", t = 2;
    answer = 7;
    assert(answer == solve.lengthAfterTransformations(s, t));

    s = "azbk", t = 1;
    answer = 5;
    assert(answer == solve.lengthAfterTransformations(s, t));


    return 0;
}
