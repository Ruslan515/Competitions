//https://leetcode.com/problems/adjacent-increasing-subarrays-detection-i/description/?envType=daily-question&envId=2025-10-14
package leetcode.tasks;

import java.util.*;

public class task_3349 {
    class Solution {
        public boolean hasIncreasingSubarrays(List<Integer> nums, int k) {
            boolean answer = false;
            int n = nums.size();
            if (k == 1) {
                return true;
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
                    if (len >= 2 * k) {
                        answer = true;
                        return answer;
                    }
                    indexes.add(Arrays.asList(left, right - 1));
                }
                left = right;
            }
            List<Integer> first, second;
            int s1, e1, s2, e2, l1, l2;
            boolean check1, check2;
            for (int i = 0; i < indexes.size() - 1; i++) {
                first = indexes.get(i);
                second = indexes.get(i + 1);
                s1 = first.get(0);
                e1 = first.get(1);
                s2 = second.get(0);
                e2 = second.get(1);

                l1 = e1 - s1 + 1;
                l2 = e2 - s2 + 1;
                check1 = l1 >= k;
                check2 = l2 >= k;
                if ((e1 + 1) == s2 && check1 && check2) {
                    answer = true;
                    break;
                }
            }

            return answer;
        }

    }

    public void main(String[] args) {
        List<Integer> nums;
        int k;
        boolean answer;

        Solution solution = new Solution();

        nums = new ArrayList<>(Arrays.asList(1, 2, 3, 4, 4, 4, 4, 5, 6, 7));
        k = 5;
        answer = false;
        assert answer == solution.hasIncreasingSubarrays(nums, k) : "Answer is different";

        nums = new ArrayList<>(Arrays.asList(5, 8, -2, -1));
        k = 2;
        answer = true;
        assert answer == solution.hasIncreasingSubarrays(nums, k) : "Answer is different";

        nums = new ArrayList<>(Arrays.asList(-15, 19));
        k = 1;
        answer = true;
        assert answer == solution.hasIncreasingSubarrays(nums, k) : "Answer is different";

        nums = new ArrayList<>(Arrays.asList(-15, 19));
        k = 1;
        answer = true;
        assert answer == solution.hasIncreasingSubarrays(nums, k) : "Answer is different";

        nums = new ArrayList<>(Arrays.asList(2, 5, 7, 8, 9, 2, 3, 4, 3, 1));
        k = 3;
        answer = true;
        assert answer == solution.hasIncreasingSubarrays(nums, k) : "Answer is different";


    }

}
