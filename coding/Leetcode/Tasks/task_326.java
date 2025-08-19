package leetcode.tasks;


public class task_326 {
    class Solution {
        public boolean isPowerOfThree(int n) {
            boolean answer = false;
            if (n <= 0) {
                return answer;
            }
            while (n != 1) {
                if (n % 3 != 0) {
                    return answer;
                }
                n /= 3;
            }
            answer = true;

            return answer;
        }
    }

    public void main(String[] args) {
        int n;
        boolean answer;

        Solution solution = new Solution();

        n = 1;
        answer = false;
        assert answer == solution.isPowerOfThree(n) : "Answer is different";

        n = 27;
        answer = true;
        assert answer == solution.isPowerOfThree(n) : "Answer is different";

        n = 0;
        answer = false;
        assert answer == solution.isPowerOfThree(n) : "Answer is different";

        n = -1;
        answer = false;
        assert answer == solution.isPowerOfThree(n) : "Answer is different";

    }

}
