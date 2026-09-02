//https://leetcode.com/contest/weekly-contest-476/problems/maximize-expression-of-three-elements/description/
package leetcode.weekly.w_476;


public class q1 {
    class Solution {
        public int maximizeExpressionOfThree(int[] nums) {
            int answer = 0;
            int maxCurrent = -101, maxPrev = -101, min = 101;
            int current;
            int n = nums.length;
            for (int i = 0; i < n; i++) {
                current = nums[i];
                if (current > maxCurrent) {
                    maxPrev = maxCurrent;
                    maxCurrent = current;
                } else if (current > maxPrev) {
                    maxPrev = current;
                }
                if (current < min) {
                    min = current;
                }
            }
            answer = maxCurrent + maxPrev - min;
            return answer;
        }


    }

    public void main(String[] args) {
        int[] nums;
        int answer;

        Solution solution = new Solution();

        nums = new int[]{-4, -8, -10};
        answer = -2;
        assert answer == solution.maximizeExpressionOfThree(nums) : "Answer is different";

        nums = new int[]{-2, 0, 5, -2, 4};
        answer = 11;
        assert answer == solution.maximizeExpressionOfThree(nums) : "Answer is different";

        nums = new int[]{1, 4, 2, 5};
        answer = 8;
        assert answer == solution.maximizeExpressionOfThree(nums) : "Answer is different";

    }

}
