package leetcode.tasks;


public class task_342 {
    class Solution {
        int currPower = 4;

        public boolean isPowerOfFour(int n) {
            boolean answer = false;
            if (n <= 0) {
                return answer;
            }
            while (n != 1) {
                if (n % this.currPower != 0) {
                    return answer;
                }
                n /= this.currPower;
            }
            answer = true;

            return answer;
        }
    }

    public void main(String[] args) {
        int n;
        boolean answer;

        Solution solution = new Solution();

        n = 16;
        answer = true;
        assert answer == solution.isPowerOfFour(n) : "Answer is different";

        n = 5;
        answer = false;
        assert answer == solution.isPowerOfFour(n) : "Answer is different";

        n = 1;
        answer = true;
        assert answer == solution.isPowerOfFour(n) : "Answer is different";

        n = -1;
        answer = false;
        assert answer == solution.isPowerOfFour(n) : "Answer is different";

    }

}
