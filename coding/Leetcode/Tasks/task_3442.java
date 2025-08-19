package leetcode.tasks;

import java.util.HashMap;
import java.util.Map;

public class task_3442 {
    class Solution {
        public int maxDifference(String s) {
            int answer = 0;
            Map<Character, Integer> map = new HashMap<>();
            for (char c : s.toCharArray()) {
                map.put(c, map.getOrDefault(c, 0) + 1);
            }
            Integer maxOdd = 0;
            Integer minEven = 101;
            for (Integer value : map.values()) {
                if (value % 2 == 0) {
                    minEven = Math.min(minEven, value);
                } else {
                    maxOdd = Math.max(maxOdd, value);
                }
            }
            answer = maxOdd - minEven;

            return answer;
        }
    }

    public void main(String[] args) {
        String s;
        int answer;

        Solution solution = new Solution();

        s = "aaaaabbc";
        answer = 3;
        assert answer == solution.maxDifference(s) : "Answer is different";

        s = "aaaaabbc";
        answer = 3;
        assert answer == solution.maxDifference(s) : "Answer is different";

    }

}
