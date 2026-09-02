//https://leetcode.com/problems/count-partitions-with-even-sum-difference/description/?envType=daily-question&envId=2025-12-05
package leetcode.tasks;

public class task_3432 {
    class Solution {
        public int countPartitions(int[] nums) {
            int answer = 0;
            int sums = 0;
            for (int num : nums) {
                sums += num;
            }
            int n = nums.length;
            int iSum = 0;
            int diff;
            for (int i = 0; i < n - 1; ++i) {
                iSum += nums[i];
                sums -= nums[i];
                diff = iSum - sums;
                if ((diff & 1) == 0) {
                    ++answer;
                }
            }

            return answer;
        }
    }

    public void main(String[] args) {
        int[] nums;
        int answer;

        Solution solution = new Solution();

        nums = new int[]{10, 10, 3, 7, 6};
        answer = 4;
        assert answer == solution.countPartitions(nums) : "Answer is different";

        nums = new int[]{1, 2, 2};
        answer = 0;
        assert answer == solution.countPartitions(nums) : "Answer is different";

        nums = new int[]{2, 4, 6, 8};
        answer = 3;
        assert answer == solution.countPartitions(nums) : "Answer is different";
    }

}
