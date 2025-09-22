//https://leetcode.com/problems/maximum-number-of-words-you-can-type/description/?envType=daily-question&envId=2025-09-15
package leetcode.tasks;

import java.util.HashSet;

import java.util.Set;

public class task_1935 {
    class Solution {
        public int canBeTypedWords(String text, String brokenLetters) {
            int answer = 0;
            Set<Character> setBrokenLetters = new HashSet<>();
            for (char c : brokenLetters.toCharArray()) {
                setBrokenLetters.add(c);
            }
            String[] words = text.split(" ");
            for (String word : words) {
                int i = 0;
                for (i = 0; i < word.length(); i++) {
                    char ch = word.charAt(i);
                    if (setBrokenLetters.contains(ch)) {
                        break;
                    }
                }
                if (i == word.length()) {
                    ++answer;
                }
            }


            return answer;
        }

    }

    public void main(String[] args) {
        String text, brokenLetters;
        int answer;

        Solution solution = new Solution();

        text = "hello world";
        brokenLetters = "ad";
        answer = 1;
        assert answer == solution.canBeTypedWords(text, brokenLetters) : "Answer is different";

        text = "leet code";
        brokenLetters = "lt";
        answer = 1;
        assert answer == solution.canBeTypedWords(text, brokenLetters) : "Answer is different";

        text = "leet code";
        brokenLetters = "e";
        answer = 0;
        assert answer == solution.canBeTypedWords(text, brokenLetters) : "Answer is different";

    }

}
