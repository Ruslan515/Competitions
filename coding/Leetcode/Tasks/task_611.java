package leetcode.tasks;


import java.util.Arrays;

public class task_611 {
    class Solution {
        public int countValid(int[] nums, int endIdx) {
            int answer = 0;
            int left = 0, right = endIdx - 1;
            int xLeft, xRight, xEnd = nums[endIdx];
            int sums;
            while (left < right) {
                xLeft = nums[left];
                xRight = nums[right];
                sums = xLeft + xRight;
                if (sums > xEnd) {
                    answer += right - left;
                    --right;
                } else {
                    ++left;
                }
            }
            return answer;
        }

        public int triangleNumber(int[] nums) {
            int answer = 0;
            int n = nums.length;
            Arrays.sort(nums);
            for (int i = n - 1; i >= 1; i--) {
                answer += countValid(nums, i);
            }

            return answer;
        }

    }

    public void main(String[] args) {
        int[] nums;
        int answer;

        Solution solution = new Solution();

        nums = new int[]{2, 2, 3, 4};
        answer = 3;
        assert answer == solution.triangleNumber(nums) : "Answer is different";

        nums = new int[]{4, 2, 3, 4};
        answer = 4;
        assert answer == solution.triangleNumber(nums) : "Answer is different";
    }

}
