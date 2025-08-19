package leetcode.tasks;

import java.util.ArrayDeque;
import java.util.Deque;

public class task_1957 {
    class Solution {
        public String makeFancyString(String s) {
            String answer = "";

            Deque<Character> stack = new ArrayDeque<>();
            char empt = ' ';
            char prev1 = empt, prev2 = empt;
            char curr;
            StringBuilder sb = new StringBuilder();

            for (int i = 0; i < s.length(); i++) {
                curr = s.charAt(i);
                if (prev1 != empt && prev2 != empt) {
                    if (curr != prev1 ||
                            curr != prev2) {
                        sb.append(curr);
                        prev2 = prev1;
                        prev1 = curr;
                    }
                } else if (prev1 != empt) {
                    sb.append(curr);
                    prev2 = prev1;
                    prev1 = curr;
                } else {
                    sb.append(curr);
                    stack.push(curr);
                    prev1 = curr;
                }
            }
            answer = sb.toString();

            return answer;
        }

    }

    public void main(String[] args) {
        String s;
        String answer;

        Solution solution = new Solution();

        s = "leeetcode";
        answer = "leetcode";
        assert answer.equals(solution.makeFancyString(s)) : "Answer is different";

        s = "aaabaaaa";
        answer = "aabaa";
        assert answer.equals(solution.makeFancyString(s)) : "Answer is different";

        s = "aab";
        answer = "aab";
        assert answer.equals(solution.makeFancyString(s)) : "Answer is different";
    }

}
