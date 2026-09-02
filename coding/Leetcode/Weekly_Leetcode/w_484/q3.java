//https://leetcode.com/contest/weekly-contest-484/problems/count-caesar-cipher-pairs/description/
package leetcode.weekly.w_484;

import java.util.*;

public class q3 {
    class Solution {
        public long countPairs(String[] words) {
            long answer = 0;
            long zero = 0;
            Map<String, Long> map = new HashMap<>();
            for (String word : words) {
                int m = word.length();
                StringBuilder sb = new StringBuilder();
                int step = word.charAt(0) - 'a';
                int k;
                char current;
                for (int i = 0; i < m; ++i) {
                    current = word.charAt(i);
                    k = (current - 'a' + 26 - step) % 26;
                    sb.append((char) (k + 'a'));
                }
                String s = sb.toString();
                map.put(s, map.getOrDefault(s, zero) + 1);
            }
            for (long value : map.values()) {
                answer += value * (value - 1) / 2;
            }


            return answer;
        }
    }

    public void main(String[] args) {
        String[] words;
        int answer;

        Solution solution = new Solution();

        words = new String[]{"fusion", "layout"};
        answer = 1;
        assert answer == solution.countPairs(words) : "Answer is different";

        words = new String[]{"ab", "aa", "za", "aa"};
        answer = 2;
        assert answer == solution.countPairs(words) : "Answer is different";

    }

}
