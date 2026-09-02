//https://leetcode.com/problems/smallest-number-with-all-set-bits/description/?envType=daily-question&envId=2025-10-29
package leetcode.tasks;

public class task_3370 {
    class Solution {

        public int smallestNumber(int n) {
            int answer = 1;
            while (answer < n) {
                answer = answer * 2 + 1;
            }

            return answer;

        }
    }

    public void main(String[] args) {
        int n;
        int answer;

        Solution solution = new Solution();

        n = 1;
        answer = 1;
        assert answer == solution.smallestNumber(n) : "Answer is different";

        n = 7;
        answer = 7;
        assert answer == solution.smallestNumber(n) : "Answer is different";


        n = 5;
        answer = 7;
        assert answer == solution.smallestNumber(n) : "Answer is different";

        n = 10;
        answer = 15;
        assert answer == solution.smallestNumber(n) : "Answer is different";

        n = 3;
        answer = 3;
        assert answer == solution.smallestNumber(n) : "Answer is different";

    }
}
