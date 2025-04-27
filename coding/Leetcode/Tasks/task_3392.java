public class task_3392 {
    class Solution {
        public int countSubarrays(int[] nums) {
            int answer = 0;
            int n = nums.length;
            int sum = 0;
            for (int i = 0; i < n - 2; i++) {
                sum = nums[i + 2] + nums[i];
                if (nums[i + 1] == 2 * sum) {
                    ++answer;
                }
            }

            return answer;
        }
    }

    public static void main(String[] args) {
        int[] nums;
        int x;
        int answer;

        Solution solution = new task_3392().new Solution();

        nums = new int[]{1, 2, 1, 4, 1};
        answer = 1;
        x = solution.countSubarrays(nums);
        assert answer == x : "Answer is different";

        nums = new int[]{1, 1, 1};
        answer = 0;
        x = solution.countSubarrays(nums);
        assert answer == x : "Answer is different";

    }
}
