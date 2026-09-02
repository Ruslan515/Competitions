//https://leetcode.com/problems/convert-integer-to-the-sum-of-two-no-zero-integers/description/
package leetcode.tasks;
import java.util.Arrays;

public class task_1317 {
    class Solution {
        public boolean hasZero(int n) {
            while (n > 0) {
                if (n % 10 == 0) {
                    return true;
                }
                n /= 10;
            }
            return false;
        }

        public int[] getNoZeroIntegers(int n) {
            int[] answer = new int[2];
            int b;
            boolean checkA, checkB;
            for (int a = 1; a < n; a++) {
                checkA = hasZero(a);
                if (!checkA) {
                    b = n - a;
                    checkB = hasZero(b);
                    if (!checkB) {
                        answer[0] = a;
                        answer[1] = b;
                        break;
                    }

                }
            }

            return answer;
        }

    }

    public void main(String[] args) {
        int n;
        int[] answer;

        Solution solution = new Solution();

        n = 2;
        answer = new int[]{1, 1};
        assert Arrays.equals(answer, solution.getNoZeroIntegers(n)) : "Answer is different";

        n = 11;
        answer = new int[]{2, 9};
        assert Arrays.equals(answer, solution.getNoZeroIntegers(n)) : "Answer is different";
    }

}
