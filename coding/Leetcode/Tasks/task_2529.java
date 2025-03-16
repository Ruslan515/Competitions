package Leetcode.Tasks;

class Solution {
    public int maximumCount(int[] nums) {
        int answer = 0;
        int cntPos = 0, cntNeg = 0;
        int n = nums.length;
        for (int i = 0; i < n; i++) {
            if (nums[i] != 0) {
                if (nums[i] < 0) {
                    ++cntNeg;
                } else {
                    ++cntPos;
                }
            }
        }

        answer = Math.max(cntNeg, cntPos);

        return answer;
    }
}

public class task_2529 {
    public static void main(String[] args) {
        int[] nums;
        int answer;
        Solution solution = new Solution();

        nums = new int[]{-2, -1, -1, 1, 2, 3};
        answer = 3;
        assert (answer == solution.maximumCount(nums));

        nums = new int[]{-3, -2, -1, 0, 0, 1, 2};
        answer = 3;
        assert (answer == solution.maximumCount(nums));

        nums = new int[]{5, 20, 66, 1314};
        answer = 4;
        assert (answer == solution.maximumCount(nums));

    }
}
