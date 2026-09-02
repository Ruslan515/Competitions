//https://leetcode.com/problems/find-missing-elements/description/?envType=daily-question&envId=2026-08-04
package leetcode.tasks;

import java.io.FileWriter;
import java.io.IOException;
import java.util.*;

public class task_3731 {
    class Solution {
        public List<Integer> findMissingElements(int[] nums) {
            List<Integer> answer = new ArrayList<>();
            int minNum = Integer.MAX_VALUE;
            int maxNum = Integer.MIN_VALUE;
            Set<Integer> currSet = new HashSet<>();
            for (int num : nums) {
                minNum = Math.min(minNum, num);
                maxNum = Math.max(maxNum, num);
                currSet.add(num);
            }
            for (int i = minNum; i <= maxNum; i++) {
                if (!currSet.contains(i)) {
                    answer.add(i);
                }
            }

            return answer;
        }

    }

    public void main(String[] args) {
        int[] nums;
        List<Integer> answer;

        Solution solution = new Solution();

        nums = new int[]{1, 4, 2, 5};
        answer = List.of(3);
        assert answer.equals(solution.findMissingElements(nums)) : "Answer is different";

        nums = new int[]{7, 8, 6, 9};
        answer = List.of();
        assert answer.equals(solution.findMissingElements(nums)) : "Answer is different";

        nums = new int[]{5, 1};
        answer = List.of(2, 3, 4);
        assert answer.equals(solution.findMissingElements(nums)) : "Answer is different";

    }

}
