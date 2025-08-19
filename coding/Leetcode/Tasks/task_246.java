//https://leetcode.com/problems/strobogrammatic-number/description/?envType=problem-list-v2&envId=hash-table
package leetcode.tasks;

import java.util.*;

public class task_246 {
    class Solution {
        public boolean isStrobogrammatic(String num) {
            Map<Character, Character> map = Map.of(
                    '9', '6',
                    '6', '9'
            );

            boolean answer = false;
            int n = num.length();
            String s = "";
            StringBuilder stringBuilder = new StringBuilder();
            for (int i = n - 1; i >= 0; i--) {
                char ch = num.charAt(i);
                int x = ch - '0';
                if (x != 8 && x != 6 && x != 9 && x != 0 && x != 1) {
                    return answer;
                }
                ch = map.getOrDefault(ch, ch);
                stringBuilder.append(ch);
            }
//            int origin = Integer.parseInt(num);
//            int rev = Integer.parseInt(s);
            if (stringBuilder.toString().equals(num)) {
                answer = true;
            }
            return answer;
        }
    }

    public void main(String[] args) {
        String num;
        boolean answer;

        Solution solution = new Solution();

        num = "10698186901";
        answer = true;
        assert answer == solution.isStrobogrammatic(num) : "Answer is different";

        num = "6";
        answer = false;
        assert answer == solution.isStrobogrammatic(num) : "Answer is different";

        num = "1";
        answer = true;
        assert answer == solution.isStrobogrammatic(num) : "Answer is different";

        num = "69";
        answer = true;
        assert answer == solution.isStrobogrammatic(num) : "Answer is different";

        num = "88";
        answer = true;
        assert answer == solution.isStrobogrammatic(num) : "Answer is different";

        num = "962";
        answer = false;
        assert answer == solution.isStrobogrammatic(num) : "Answer is different";
    }

}
