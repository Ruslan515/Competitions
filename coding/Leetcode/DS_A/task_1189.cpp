// https://leetcode.com/problems/maximum-number-of-balloons/description/
// Created by ruslan515 on 13.06.23.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxNumberOfBalloons(string text) {
        map<char, int> balloon = {
                {'b', 0},
                {'a', 0},
                {'l', 0},
                {'o', 0},
                {'n', 0},
                };
        int minCount = 0;
        for(char ch: text) {
            if (balloon.count(ch)) {
                ++balloon[ch];
                minCount = min(minCount, balloon[ch]);
            }
        }
        
        
        int b = balloon['b'];
        int a = balloon['a'];
        int n = balloon['n'];
        int min_x = min(b, min(a,n));
        int l = balloon['l'];
        int o = balloon['o'];
        int minLO = min(l, o);
        if (minLO & 1) {
            --minLO;
        }
        int d = minLO / 2;
        int answer = 0;
        if (d <= min_x) {
            answer = d;
        } else if (min_x * 2 <= minLO) {
            answer = min_x;
        }

        return answer;
    }
};

int main() {
    string text;
    int answer;
    Solution solve;

    text = "krhizmmgmcrecekgyljqkldocicziihtgpqwbticmvuyznragqoyrukzopfmjhjjxemsxmrsxuqmnkrzhgvtgdgtykhcglurvppvcwhrhrjoislonvvglhdciilduvuiebmffaagxerjeewmtcwmhmtwlxtvlbocczlrppmpjbpnifqtlninyzjtmazxdbzwxthpvrfulvrspycqcghuopjirzoeuqhetnbrcdakilzmklxwudxxhwilasbjjhhfgghogqoofsufysmcqeilaivtmfziumjloewbkjvaahsaaggteppqyuoylgpbdwqubaalfwcqrjeycjbbpifjbpigjdnnswocusuprydgrtxuaojeriigwumlovafxnpibjopjfqzrwemoinmptxddgcszmfprdrichjeqcvikynzigleaajcysusqasqadjemgnyvmzmbcfrttrzonwafrnedglhpudovigwvpimttiketopkvqw";
    answer = 10;
    assert(answer == solve.maxNumberOfBalloons(text));

    text = "balllllllllllloooooooooon";
    answer = 1;
    assert(answer == solve.maxNumberOfBalloons(text));

    text = "balon";
    answer = 0;
    assert(answer == solve.maxNumberOfBalloons(text));

    text = "nlaebolko";
    answer = 1;
    assert(answer == solve.maxNumberOfBalloons(text));

    text = "nlaebolko";
    answer = 1;
    assert(answer == solve.maxNumberOfBalloons(text));

    return 0;
}
