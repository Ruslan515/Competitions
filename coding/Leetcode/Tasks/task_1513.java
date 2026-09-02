//https://leetcode.com/problems/number-of-substrings-with-only-1s/description/?envType=daily-question&envId=2025-11-16
package leetcode.tasks;

public class task_1513 {
    class Solution {
        public int numSub(String s) {
            long answer = (long) 0;

            long cntOnes;
            int n = s.length();
            int left = 0, right = 0;

            while (left < n) {
                while (right < n && s.charAt(right) == '1') {
                    ++right;
                }
                cntOnes = (long) right - left;
                answer += cntOnes * (cntOnes + 1) / 2;
                while (right < n && s.charAt(right) == '0') {
                    ++right;
                }
                left = right;
                ++right;
            }

            answer %= Math.pow(10, 9) + 7;

            return (int) answer;
        }

    }

    public void main(String[] args) {
        String s;
        int answer;

        Solution solution = new Solution();

        s = "0110111";
        answer = 9;
        assert answer == solution.numSub(s) : "Answer is different";

        s = "0110111";
        answer = 9;
        assert answer == solution.numSub(s) : "Answer is different";

        s = "0110111";
        answer = 9;
        assert answer == solution.numSub(s) : "Answer is different";

    }

}
