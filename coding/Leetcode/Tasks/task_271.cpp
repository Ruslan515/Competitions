// https://leetcode.com/problems/encode-and-decode-strings/description/
// Created by ruslan515 on 08.08.23.
//

#include <bits/stdc++.h>

using namespace std;

class Codec {
public:
    char separator = '\n';
//    string separator = "$#$";
    // Encodes a list of strings to a single string.
    string encode(vector<string> &strs) {
        string answer = "";
        for (auto s: strs) {
            answer += s + separator;
        }
        return answer;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> answer;
        int n = s.size();
        int i = 0;
        string temp = "";
        while (i < n) {
            while (i < n && s[i] != separator) {
                temp += s[i];
                ++i;
            }
            ++i;
            answer.push_back(temp);
            temp = "";
        }

        return answer;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));

int main() {
    Codec *encoder = new Codec();

    vector<string> dummy_input = {"Hello", "World"};
    vector<string> answer = {"Hello", "World"};
    assert(answer == encoder->decode(encoder->encode(dummy_input)));

    return 0;
}
