//https://leetcode.com/problems/shortest-word-distance/?envType=problem-list-v2&envId=array
package leetcode.tasks;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class task_243 {
    class Solution {
        public int shortestDistance(String[] wordsDict, String word1, String word2) {
            int answer = Integer.MAX_VALUE;
            List<Integer> list1 = new ArrayList<>();
            List<Integer> list2 = new ArrayList<>();
            int n = wordsDict.length;
            for (int i = 0; i < n; i++) {
                String s = wordsDict[i];
                if (s.equals(word1)) {
                    list1.add(i);
                } else if (s.equals(word2)) {
                    list2.add(i);
                }
            }
            for (int i = 0; i < list1.size(); ++i) {
                for (int j = 0; j < list2.size(); ++j) {
                    int diff = Math.abs(list1.get(i) - list2.get(j));
                    if (diff < answer) {
                        answer = diff;
                    }
                }
            }

            return answer;
        }
    }

    public void main(String[] args) {
        String[] wordsDict;
        String word1, word2;
        int answer;

        Solution solution = new Solution();

        wordsDict = new String[]{"practice", "makes", "perfect", "coding", "makes"};
        word1 = "coding";
        word2 = "practice";
        answer = 3;
        assert answer == solution.shortestDistance(wordsDict, word1, word2) : "Answer is different";

        wordsDict = new String[]{"practice", "makes", "perfect", "coding", "makes"};
        word1 = "makes";
        word2 = "coding";
        answer = 1;
        assert answer == solution.shortestDistance(wordsDict, word1, word2) : "Answer is different";

    }

}
