package leetcode.bw.bw_167;

public class task_q2 {
    class Solution {
        public int longestSubarray(int[] nums) {
            int answer = 0;
            int n = nums.length;
            int left = 0;
            int right = 0;

            int currMaxLen = 0;
            while (left < n) {
                right = left + 2;
                while (right < n && nums[right] == (nums[right - 1] + nums[right - 2])) {
                    right++;
                }
                currMaxLen = right - left;
                answer = Math.max(answer, currMaxLen);
                left++;
            }

            return answer;
        }

    }

    public void main(String[] args) {
        int[] nums;
        int answer;

        Solution solution = new Solution();

        nums = new int[]{1, 1, 1, 2};
        answer = 3;
        assert answer == solution.longestSubarray(nums) : "Answer is different";

        nums = new int[]{1, 1, 1, 1, 2, 3, 5, 1};
        answer = 5;
        assert answer == solution.longestSubarray(nums) : "Answer is different";

        nums = new int[]{5, 2, 7, 9, 16};

        answer = 5;
        assert answer == solution.longestSubarray(nums) : "Answer is different";

        nums = new int[]{1000000000, 1000000000, 1000000000};

        answer = 2;
        assert answer == solution.longestSubarray(nums) : "Answer is different";
    }

}
