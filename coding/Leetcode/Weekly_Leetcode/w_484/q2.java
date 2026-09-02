//https://leetcode.com/contest/weekly-contest-484/problems/number-of-centered-subarrays/description/
package leetcode.weekly.w_484;

import java.util.HashSet;
import java.util.Map;
import java.util.HashMap;
import java.util.Set;

public class q2 {
    class Solution {
        public int centeredSubarrays(int[] nums) {
            int n = nums.length;
            int answer = 0;
            int current;
            for (int start = 0; start < n; start++) {
                Set<Integer> set = new HashSet<>();
                long sums = 0;
                for (int end = start; end < n; end++) {
                    current = nums[end];
                    set.add(current);
                    sums += current;
                    if (set.contains((int) sums)) {
                        answer++;
                    }
                }
            }

            return answer;
        }
    }

    public void main(String[] args) {
        int[] nums;
        int answer;

        Solution solution = new Solution();

        nums = new int[]{-1, 1, 0};
        answer = 5;
        assert answer == solution.centeredSubarrays(nums) : "Answer is different";

        nums = new int[]{2, -3};
        answer = 2;
        assert answer == solution.centeredSubarrays(nums) : "Answer is different";


    }

}
