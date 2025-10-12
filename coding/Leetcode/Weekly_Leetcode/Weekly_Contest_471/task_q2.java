// https://leetcode.com/problems/longest-balanced-substring-i/
package leetcode.weekly.w_471;

import java.util.*;

public class task_q2 {
    class Solution {
        public int longestBalanced(String s) {
            int answer = 1;
            int n = s.length();
            Map<Character, Integer> map = new HashMap<>();
            for (int i = 0; i < n; i++){
                if (n - i <= answer) {
                    break;
                }
                int[] freq = new int[26];
                for (int j = i; j < n; j++) {
                    int idx = s.charAt(j) - 'a';
                    freq[idx]++;
                    int minFreq = Integer.MAX_VALUE;
                    int maxFreq = 0;
                    for (int k = 0; k < 26; k++) {
                        if (freq[k] > 0) {
                            minFreq = Math.min(minFreq, freq[k]);
                            maxFreq = Math.max(maxFreq, freq[k]);
                        }
                    }
                    if (minFreq == maxFreq) {
                        int currLen = j - i + 1;
                        answer = Math.max(answer, currLen);
                    }
                }
            }


            return answer;
        }

    }

    public void main(String[] args) {
        String s;
        int answer;

        Solution solution = new Solution();

        s = "a";
        answer = 1;
        assert answer == solution.longestBalanced(s) : "Answer is different";

        s = "abbac";
        answer = 4;
        assert answer == solution.longestBalanced(s) : "Answer is different";

        s = "zzabccy";
        answer = 4;
        assert answer == solution.longestBalanced(s) : "Answer is different";

        s = "aba";
        answer = 2;
        assert answer == solution.longestBalanced(s) : "Answer is different";

    }

}
