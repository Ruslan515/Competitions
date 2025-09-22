package leetcode.tasks;

public class task_1493 {
    class Solution {
        public int longestSubarray(int[] nums) {
            int n = nums.length;
            int answer = 0;
            int left = 0, right = 0;
            int cntZero = 0;
            while (right < n) {
                while (right < n) {
                    if (nums[right] == 0) {
                        cntZero++;
                    }
                    if (cntZero > 1) {
                        break;
                    }
                    ++right;
                }
                answer = Math.max(answer, right - left - 1);
                while (left < n && left < right) {
                    if (nums[left] == 0) {
                        cntZero--;
                    }
                    if (cntZero <= 1) {
                        ++left;
                        break;
                    }
                    ++left;
                }
                ++right;

            }


            return answer;
        }

    }

    public void main(String[] args) {
        int[] nums;
        int answer;

        Solution solution = new Solution();

        nums = new int[]{0, 1, 1, 1, 0, 1, 1, 0, 1};
        answer = 5;
        assert answer == solution.longestSubarray(nums) : "Answer is different";

        nums = new int[]{1, 1, 0, 1};
        answer = 3;
        assert answer == solution.longestSubarray(nums) : "Answer is different";

        nums = new int[]{1, 1, 1};
        answer = 2;
        assert answer == solution.longestSubarray(nums) : "Answer is different";
    }

}
