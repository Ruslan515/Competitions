//https://leetcode.com/problems/adjacent-increasing-subarrays-detection-ii/
package leetcode.tasks;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class task_3350 {
    class Solution {
        public int maxIncreasingSubarrays(List<Integer> nums) {
            int answer = 0;
            int n = nums.size();
            if (n == 2 || n == 3) {
                return 1;
            }
            List<List<Integer>> indexes = new ArrayList<>();
            int left = 0;
            int right = 0;

            int len;
            while (left < n) {
                ++right;
                while (right < n && nums.get(right) > nums.get(right - 1))
                    right++;
                if (right <= n && nums.get(right - 1) > nums.get(left)) {
                    len = right - left;
                    answer = Math.max(answer, len / 2);
                    indexes.add(Arrays.asList(left, right - 1));
                }
                left = right;
            }
            List<Integer> first, second;
            int s1, e1, s2, e2, l1, l2;
            for (int i = 0; i < indexes.size() - 1; i++) {
                first = indexes.get(i);
                second = indexes.get(i + 1);
                s1 = first.get(0);
                e1 = first.get(1);
                s2 = second.get(0);
                e2 = second.get(1);

                l1 = e1 - s1 + 1;
                l2 = e2 - s2 + 1;
                if ((e1 + 1) == s2) {
                    answer = Math.max(answer, Math.min(l1, l2));
                }
            }

            return answer;
        }

    }

    public void main(String[] args) {
        List<Integer> nums;
        int answer;

        Solution solution = new Solution();

        nums = new ArrayList<>(Arrays.asList(20, -2, -18));
        answer = 1;
        assert answer == solution.maxIncreasingSubarrays(nums) : "Answer is different";

        nums = new ArrayList<>(Arrays.asList(1, 2, 3, 4, 4, 4, 4, 5, 6, 7));
        answer = 2;
        assert answer == solution.maxIncreasingSubarrays(nums) : "Answer is different";

        nums = new ArrayList<>(Arrays.asList(5, 8, -2, -1));
        answer = 2;
        assert answer == solution.maxIncreasingSubarrays(nums) : "Answer is different";

        nums = new ArrayList<>(Arrays.asList(-15, 19));
        answer = 1;
        assert answer == solution.maxIncreasingSubarrays(nums) : "Answer is different";

        nums = new ArrayList<>(Arrays.asList(2, 5, 7, 8, 9, 2, 3, 4, 3, 1));
        answer = 3;
        assert answer == solution.maxIncreasingSubarrays(nums) : "Answer is different";


    }

}
