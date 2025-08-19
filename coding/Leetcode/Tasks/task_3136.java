package leetcode.tasks;

import java.util.*;

public class task_3136 {
    class Solution {
        public boolean isValid(String word) {
            boolean answer = false;
            int n = word.length();
            if (n < 3) {
                return answer;
            }
            Set<Character> set = new HashSet<>(List.of('a', 'e', 'i', 'o', 'u'));
            int cntVowels = 0;
            int cntConsonants = 0;
            for (char ch : word.toCharArray()) {
                char c = Character.toLowerCase(ch);
                if (String.valueOf(c).matches("[0-9a-zA-Z]")) {
                    if (String.valueOf(c).matches("[a-zA-Z]")) {
                        if (set.contains(c)) {
                            cntVowels++;
                        } else {
                            cntConsonants++;
                        }
                    }
                } else {
                    return answer;
                }
            }
            if (cntVowels >= 1 && cntConsonants >= 1) {
                answer = true;
            }

            return answer;
        }
    }

    public void main(String[] args) {
        String word;
        boolean answer;

        Solution solution = new Solution();

        word = "Ya$";
        answer = false;
        assert answer == solution.isValid(word) : "Answer is different";

        word = "AhI";
        answer = true;
        assert answer == solution.isValid(word) : "Answer is different";

        word = "234Adas";
        answer = true;
        assert answer == solution.isValid(word) : "Answer is different";

        word = "234Adas";
        answer = true;
        assert answer == solution.isValid(word) : "Answer is different";


        word = "b3";
        answer = false;
        assert answer == solution.isValid(word) : "Answer is different";

        word = "a3$e";
        answer = false;
        assert answer == solution.isValid(word) : "Answer is different";

    }

}
