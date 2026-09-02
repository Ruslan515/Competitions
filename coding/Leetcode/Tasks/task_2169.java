//https://leetcode.com/problems/count-operations-to-obtain-zero/description/?envType=daily-question&envId=2025-11-09
package leetcode.tasks;

public class task_2169 {
    class Solution {
        public int countOperations(int num1, int num2) {
            /*
            num1 > num2
             */

            int answer = 0;
            if (num1 < num2) {
                return countOperations(num2, num1);
            }
            int k, d;
            while (num1 != 0 && num2 != 0) {
                k = num1 / num2;
                d = num1 % num2;
                answer += k;
                num1 = num2;
                num2 = d;
            }

            return answer;
        }

    }

    public void main(String[] args) {
        int num1, num2;
        int answer;

        Solution solution = new Solution();

        num1 = 5;
        num2 = 29;
        answer = 10;
        assert answer == solution.countOperations(num1, num2) : "Answer is different";

        num1 = 2;
        num2 = 3;
        answer = 3;
        assert answer == solution.countOperations(num1, num2) : "Answer is different";

        num1 = 10;
        num2 = 10;
        answer = 1;
        assert answer == solution.countOperations(num1, num2) : "Answer is different";

    }

}
