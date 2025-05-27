package leetcode.tasks;

public class task_1920 {
    class Solution {
        public int[] buildArray(int[] nums) {
            int n = nums.length;
            int[] answer = new int[n];
            for (int i = 0; i < n; i++) {
                int idx = nums[i];
                answer[i] = nums[idx];
            }

            return answer;
        }
    }

    public static void main(String[] args) {
        int[] nums;
        int[] x;
        int[] answer;

        Solution solution = new task_1920().new Solution();

        nums = new int[]{0, 2, 1, 5, 3, 4};
        answer = new int[]{0, 1, 2, 4, 5, 3};
        x = solution.buildArray(nums);
        assert answer == x : "Answer is different";

        nums = new int[]{0, 2, 1, 5, 3, 4};
        answer = new int[]{0, 1, 2, 4, 5, 3};
        x = solution.buildArray(nums);
        assert answer == x : "Answer is different";

    }
}
