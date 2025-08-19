//https://leetcode.com/problems/find-the-original-typed-string-i/description/?envType=daily-question&envId=2025-07-01
package leetcode.tasks;

import java.util.HashMap;
import java.util.Map;

public class task_3330 {
    class Solution {
        public int possibleStringCount(String word) {
            int answer = 1;
            int n = word.length();
            int left = 0;
            int right = 0;
            while (left < n) {
                while (right < n && word.charAt(right) == word.charAt(left)) {
                    ++right;
                }
                int cnt = right - left - 1;
                answer += cnt;
                left = right;
            }

            return answer;
        }
    }

    public void main(String[] args) {
        String word;
        int answer;

        Solution solution = new Solution();

        word = "ere";
        answer = 1;
        assert answer == solution.possibleStringCount(word) : "Answer is different";

        word = "abbcccc";
        answer = 5;
        assert answer == solution.possibleStringCount(word) : "Answer is different";

        word = "abcd";
        answer = 1;
        assert answer == solution.possibleStringCount(word) : "Answer is different";

        word = "aaaa";
        answer = 4;
        assert answer == solution.possibleStringCount(word) : "Answer is different";

    }

}
