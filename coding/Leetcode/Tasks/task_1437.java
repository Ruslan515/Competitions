//https://leetcode.com/problems/check-if-all-1s-are-at-least-length-k-places-away/description/?envType=daily-question&envId=2025-11-17
package leetcode.tasks;

public class task_1437 {
    class Solution {
        public boolean kLengthApart(int[] nums, int k) {
            boolean answer = true;
            int n = nums.length;
            int dist = 0;
            boolean firstOnes = false;
            for (int i = 0; i < n; i++) {
                if (firstOnes && i != 0 && nums[i] == 1) {
                    if (dist < k) {
                        answer = false;
                        break;
                    }
                    dist = 0;
                } else if (nums[i] == 0) {
                    dist++;
                } else if (nums[i] == 1) {
                    firstOnes = true;
                    dist = 0;
                }
            }


            return answer;
        }

    }

    public void main(String[] args) {
        int[] nums;
        int k;
        boolean answer;

        Solution solution = new Solution();

        nums = new int[]{0, 0, 0, 1, 0, 1};
        k = 2;
        answer = false;
        assert answer == solution.kLengthApart(nums, k) : "Answer is different";

        nums = new int[]{0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0};
        k = 3;
        answer = true;
        assert answer == solution.kLengthApart(nums, k) : "Answer is different";

        nums = new int[]{0, 1, 1, 0, 0, 0, 1, 0};
        k = 3;
        answer = false;
        assert answer == solution.kLengthApart(nums, k) : "Answer is different";

        nums = new int[]{1, 1, 1, 0};
        k = 3;
        answer = false;
        assert answer == solution.kLengthApart(nums, k) : "Answer is different";

        nums = new int[]{0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1};
        k = 3;
        answer = true;
        assert answer == solution.kLengthApart(nums, k) : "Answer is different";


        nums = new int[]{1, 0, 0, 0, 1, 0, 0, 1};
        k = 2;
        answer = true;
        assert answer == solution.kLengthApart(nums, k) : "Answer is different";

        nums = new int[]{1, 0, 0, 1, 0, 1};
        k = 2;
        answer = false;
        assert answer == solution.kLengthApart(nums, k) : "Answer is different";
    }
}
