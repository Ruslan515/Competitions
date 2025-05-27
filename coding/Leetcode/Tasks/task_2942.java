package leetcode.tasks;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashSet;
import java.util.List;

public class task_2942 {
    class Solution {
        public List<Integer> findWordsContaining(String[] words, char x) {
            List<Integer> answer = new ArrayList<>();
            for (int i = 0; i < words.length; ++i) {
                String word = words[i];
                for (int j = 0; j < word.length(); j++) {
                    if (word.charAt(j) == x) {
                        answer.add(i);
                        break;
                    }
                }
            }
            return answer;
        }

    }

    public static void main(String[] args) {
        String[] words;
        char x;
        List<Integer> answer, result;

        Solution solution = new task_2942().new Solution();

        words = new String[]{"leet", "code"};
        x = 'e';
        answer = List.of(0, 1);
        result = solution.findWordsContaining(words, x);
        assert answer.equals(result) : "Answer is different";

        words = new String[]{"abc", "bcd", "aaaa", "cbc"};
        x = 'a';
        answer = List.of(0, 2);
        result = solution.findWordsContaining(words, x);
        assert answer.equals(result) : "Answer is different";

        words = new String[]{"abc", "bcd", "aaaa", "cbc"};
        x = 'z';
        answer = List.of();
        result = solution.findWordsContaining(words, x);
        assert answer.equals(result) : "Answer is different";
    }
}
