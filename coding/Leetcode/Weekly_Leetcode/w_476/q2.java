//https://leetcode.com/contest/weekly-contest-476/problems/minimum-string-length-after-balanced-removals/
package leetcode.weekly.w_476;


import java.util.HashMap;
import java.util.Map;

public class q2 {
    class Solution {
        public int minLengthAfterRemovals(String s) {
            int answer = 0;
            Map<Character, Integer> map = new HashMap<>();
            char ch;
            for (int i = 0; i < s.length(); ++i) {
                ch = s.charAt(i);
                map.put(ch, map.getOrDefault(ch, 0) + 1);
            }
            int cntA = map.getOrDefault('a', 0);
            int cntB = map.getOrDefault('b', 0);
            answer = Math.abs(cntA - cntB);


            return answer;
        }


    }

    public void main(String[] args) {
        String s;
        int answer;

        Solution solution = new Solution();

        s = "aabbab";
        answer = 0;
        assert answer == solution.minLengthAfterRemovals(s) : "Answer is different";

        s = "aaaa";
        answer = 4;
        assert answer == solution.minLengthAfterRemovals(s) : "Answer is different";

        s = "aaabb";
        answer = 1;
        assert answer == solution.minLengthAfterRemovals(s) : "Answer is different";

    }

}
