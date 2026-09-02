//https://leetcode.com/problems/minimum-operations-to-make-array-sum-divisible-by-k/description/?envType=daily-question&envId=2025-11-29
package leetcode.tasks;


public class task_3512 {
    class Solution {
        public int minOperations(int[] nums, int k) {
            int answer = 0;
            int sums = 0;
            for (int num : nums) {
                sums += num;
            }
            answer = sums % k;

            return answer;
        }

    }

    public void main(String[] args) {
        int[] nums;
        int k;
        int answer;

        Solution solution = new Solution();

        nums = new int[]{3, 9, 7};
        k = 5;
        answer = 4;
        assert answer == solution.minOperations(nums, k) : "Answer is different";

        nums = new int[]{4, 1, 3};
        k = 4;
        answer = 0;
        assert answer == solution.minOperations(nums, k) : "Answer is different";

        nums = new int[]{3, 2};
        k = 6;
        answer = 5;
        assert answer == solution.minOperations(nums, k) : "Answer is different";

    }

}
