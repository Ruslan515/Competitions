package leetcode.tasks;

import java.util.Arrays;

public class task_75 {
    class Solution {
        public void sortColors(int[] nums) {
            int cntZeros = 0, cntOnes = 0, cntTwos = 0;
            for (int num : nums) {
                if (num == 0) {
                    cntZeros++;
                } else if (num == 1) {
                    cntOnes++;
                } else if (num == 2) {
                    cntTwos++;
                }
            }

            int[] cnts = new int[]{cntZeros, cntOnes, cntTwos};
            int i = 0;
            for (int val = 0; val < cnts.length; ++val) {
                int cnt = cnts[val];
                for (int j = 0; j < cnt; ++j) {
                    nums[i + j] = val;
                }
                i += cnt;
            }
        }
    }

    public static void main(String[] args) {
        int[] nums;
        int[] answer;

        Solution solution = new task_75().new Solution();

        nums = new int[]{2, 0, 2, 1, 1, 0};
        answer = new int[]{0, 0, 1, 1, 2, 2};
        solution.sortColors(nums);
        assert Arrays.equals(answer, nums) : "Answer is different";

        nums = new int[]{2, 0, 1};
        answer = new int[]{0, 1, 2};
        solution.sortColors(nums);
        assert Arrays.equals(answer, nums) : "Answer is different";

    }
}
