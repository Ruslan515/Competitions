package leetcode.tasks;


public class task_2348 {
    class Solution {
        public long zeroFilledSubarray(int[] nums) {
            long answer = 0;
            int n = nums.length;
            int left = 0, right = 0;
            long cnt, len;
            while (right < n) {
                while (left < n && nums[left] != 0) {
                    ++left;
                }
                if (left == n) {
                    break;
                }
                right = left;
                while (right < n && nums[right] == 0) {
                    ++right;
                }
                len = (long) right - left;
                cnt = len * (len + 1) / 2;
                answer += cnt;
                left = right;
            }

            return answer;
        }
    }

    public void main(String[] args) {
        int[] nums;
        long answer;

        Solution solution = new Solution();

        nums = new int[]{1, 3, 0, 0, 2, 0, 0, 4};
        answer = 6;
        assert answer == solution.zeroFilledSubarray(nums) : "Answer is different";

        nums = new int[]{0, 0, 0, 2, 0, 0};
        answer = 9;
        assert answer == solution.zeroFilledSubarray(nums) : "Answer is different";

        nums = new int[]{2, 10, 2019};
        answer = 0;
        assert answer == solution.zeroFilledSubarray(nums) : "Answer is different";
    }

}
