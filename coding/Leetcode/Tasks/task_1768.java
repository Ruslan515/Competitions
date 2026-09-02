//https://leetcode.com/problems/merge-strings-alternately/description/
package leetcode.tasks;

public class task_1768 {
    class Solution {
        public String mergeAlternately(String word1, String word2) {
            String answer = "";
            int n1 = word1.length();
            int n2 = word2.length();
            int i1 = 0, i2 = 0;
            while (i1 < n1 && i2 < n2) {
                answer += word1.charAt(i1++);
                answer += word2.charAt(i2++);
            }
            while (i1 < n1) {
                answer += word1.charAt(i1++);
            }
            while (i2 < n2) {
                answer += word2.charAt(i2++);
            }

            return answer;
        }

    }

    public void main(String[] args) {
        String word1, word2;
        String answer;

        Solution solution = new Solution();

        word1 = "abc";
        word2 = "pqr";
        answer = "apbqcr";
        assert answer.equals(solution.mergeAlternately(word1, word2)) : "Answer is different";

        word1 = "ab";
        word2 = "pqrs";
        answer = "apbqrs";
        assert answer.equals(solution.mergeAlternately(word1, word2)) : "Answer is different";

        word1 = "abcd";
        word2 = "pq";
        answer = "apbqcd";
        assert answer.equals(solution.mergeAlternately(word1, word2)) : "Answer is different";
    }

}
