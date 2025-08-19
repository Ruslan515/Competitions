package leetcode.tasks;

public class task_3151 {
    class Solution {
        public boolean isArraySpecial(int[] nums) {
            boolean answer = true;
            int n = nums.length;
            if (n == 1) {
                return answer;
            }
            int prev, curr;
            boolean check1, check2;
            for (int i = 1; i < n; i++) {
                prev = nums[i - 1];
                curr = nums[i];
                check1 = prev % 2 == 0 && curr % 2 == 0;
                check2 = prev % 2 != 0 && curr % 2 != 0;
                if (check1 || check2) {
                    answer = false;
                    break;
                }
            }

            return answer;
        }
    }

    public void main(String[] args) {
        int[] nums;
        boolean answer;

        Solution solution = new Solution();

        nums = new int[]{1};
        answer = true;
        assert answer == solution.isArraySpecial(nums) : "Answer is different";

        nums = new int[]{2, 1, 4};
        answer = true;
        assert answer == solution.isArraySpecial(nums) : "Answer is different";

        nums = new int[]{4, 3, 1, 6};
        answer = false;
        assert answer == solution.isArraySpecial(nums) : "Answer is different";

    }

}
