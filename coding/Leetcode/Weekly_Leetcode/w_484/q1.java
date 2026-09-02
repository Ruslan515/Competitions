//https://leetcode.com/contest/weekly-contest-484/problems/count-residue-prefixes/description/
package leetcode.weekly.w_484;

import java.util.HashMap;
import java.util.Map;

public class q1 {
    class Solution {
        public int residuePrefixes(String s) {
            int answer = 0;
            Map<Character, Integer> map = new HashMap<>();
            int cnt;
            int n = s.length();
            for (int i = 0; i < n; ++i) {
                char ch = s.charAt(i);
                map.put(ch, map.getOrDefault(ch, 0) + 1);
                cnt = map.size();
                if ((i + 1) % 3 == cnt) {
                    ++answer;
                }

            }

            return answer;
        }


    }

    public void main(String[] args) {
        String s;
        int answer;

        Solution solution = new Solution();

        s = "abc";
        answer = 2;
        assert answer == solution.residuePrefixes(s) : "Answer is different";

        s = "dd";
        answer = 1;
        assert answer == solution.residuePrefixes(s) : "Answer is different";

        s = "bob";
        answer = 2;
        assert answer == solution.residuePrefixes(s) : "Answer is different";

    }


}
