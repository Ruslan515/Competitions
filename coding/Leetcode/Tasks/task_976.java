package leetcode.tasks;

import java.util.Arrays;

public class task_976 {
    class Solution {
        public int largestPerimeter(int[] nums) {
            int answer = 0;
            int n = nums.length;
            Arrays.sort(nums);
            int a, b, c;
            double area;
            for (int i = n - 1; i >= 2; i--) {
                a = nums[i];
                b = nums[i - 1];
                c  = nums[i - 2];
                if (a < b + c) {
                    answer = a + b + c;
                    break;
                }
            }


            return answer;
        }

    }

    public void main(String[] args) {
        int[] nums;
        int answer;

        Solution solution = new Solution();

        nums = new int[]{2, 1, 2};
        answer = 5;
        assert answer == solution.largestPerimeter(nums) : "Answer is different";

        nums = new int[]{1, 2, 1, 10};
        answer = 0;
        assert answer == solution.largestPerimeter(nums) : "Answer is different";

    }

}
