package leetcode.tasks;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class task_2131 {
    class Solution {
        public int longestPalindrome(String[] words) {
            int answer = 0;
            HashMap<String, Integer> map = new HashMap<>();
            for (String word : words) {
                map.put(word, map.getOrDefault(word, 0) + 1);
            }
            int maxLenOdd = 0;
            String maxOdd = "";
            for (Map.Entry<String, Integer> entry : map.entrySet()) {
                String key = entry.getKey();
                int value = entry.getValue();
                String reverse = "" + key.charAt(1) + key.charAt(0);
                if (reverse.equals(key)) {
                    if (value % 2 == 1) {
                        if (maxLenOdd < 2 * value) {
                            maxLenOdd = 2 * value;
                            maxOdd = key;
                        }

                    }
                } else if (map.containsKey(reverse)) {
                    int reverseValue = map.get(reverse);
                    int minVal = Math.min(value, reverseValue);
                    answer += 2 * minVal;
                }

            }

            answer += maxLenOdd;
            for (Map.Entry<String, Integer> entry : map.entrySet()) {
                String key = entry.getKey();
                int value = entry.getValue();
                String reverse = "" + key.charAt(1) + key.charAt(0);
                if (reverse.equals(key)) {
                    if (!maxOdd.equals(key)) {
                        answer += 2 * (value - (value % 2));
                    }
                }
            }
            return answer;
        }

    }

    public static void main(String[] args) {
        String[] words;

        int answer, result;

        Solution solution = new task_2131().new Solution();

        words = new String[]{"dd", "aa", "bb", "dd", "aa", "dd", "bb", "dd", "aa", "cc", "bb", "cc", "dd", "cc"};
        answer = 22;
        result = solution.longestPalindrome(words);
        assert answer == result : "Answer is different";

        words = new String[]{"cc", "ll", "xx"};
        answer = 2;
        result = solution.longestPalindrome(words);
        assert answer == result : "Answer is different";

        words = new String[]{"lc", "cl", "gg"};
        answer = 6;
        result = solution.longestPalindrome(words);
        assert answer == result : "Answer is different";

        words = new String[]{"ab", "ty", "yt", "lc", "cl", "ab"};
        answer = 8;
        result = solution.longestPalindrome(words);
        assert answer == result : "Answer is different";


    }
}
