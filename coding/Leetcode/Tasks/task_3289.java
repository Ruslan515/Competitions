//https://leetcode.com/problems/the-two-sneaky-numbers-of-digitville/description/?envType=daily-question&envId=2025-10-31
package leetcode.tasks;

import java.util.HashMap;
import java.util.Map;

public class task_3289 {
    class Solution {
        public int[] getSneakyNumbers(int[] nums) {
            int[] answer = new int[2];
            int i = 0;
            Map<Integer, Integer> freq = new HashMap<>();
            for (int num : nums) {
                freq.put(num, freq.getOrDefault(num, 0) + 1);
                if (freq.get(num) == 2) {
                    answer[i++] = num;
                }
            }


            return answer;
        }
    }

    public void main(String[] args) {
        int[] nums;
        int[] answer;

        Solution solution = new Solution();

        nums = new int[]{0, 1, 1, 0};
        answer =  new int[]{0, 1};
        assert answer == solution.getSneakyNumbers(nums) : "Answer is different";

        nums = new int[]{0, 3, 2, 1, 3, 2};
        answer =  new int[]{2, 3};
        assert answer == solution.getSneakyNumbers(nums) : "Answer is different";

        nums = new int[]{7, 1, 5, 4, 3, 4, 6, 0, 9, 5, 8, 2};
        answer =  new int[]{4, 5};
        assert answer == solution.getSneakyNumbers(nums) : "Answer is different";
    }

}
