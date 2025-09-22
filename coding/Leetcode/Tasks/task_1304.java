package leetcode.tasks;

import java.util.Arrays;

public class task_1304 {
    class Solution {
        public int[] sumZero(int n) {
            int[] answer = new int[n];
            if (n == 1) {
                answer = new int[]{0};
            } else if (n == 2) {
                answer = new int[]{-1, 1};
            } else {
                int leftStart = (n - 1) / 2 - n % 2;
                int rightStart = (n - 1) / 2 + 1;
                for (int i = leftStart, j = rightStart, idx = 1; i >= 0; --i, ++j, ++idx) {
                    answer[i] = -idx;
                    answer[j] = idx;
                }
            }

            return answer;
        }

    }

    public void main(String[] args) {
        int n;
        int[] answer;

        Solution solution = new Solution();

        n = 4;
        answer = new int[]{-2, -1, 1, 2};
        assert Arrays.equals(answer, solution.sumZero(n)) : "Answer is different";

        n = 5;
        answer = new int[]{-2, -1, 0, 1, 2};
        assert Arrays.equals(answer, solution.sumZero(n)) : "Answer is different";

        n = 3;
        answer = new int[]{-1, 0, 1};
        assert Arrays.equals(answer, solution.sumZero(n)) : "Answer is different";

        n = 1;
        answer = new int[]{0};
        assert Arrays.equals(answer, solution.sumZero(n)) : "Answer is different";


    }

}
