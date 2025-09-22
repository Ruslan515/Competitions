package leetcode.tasks;


import java.util.Map;
import java.util.HashMap;

public class task_3005 {
    class Solution {
        public int maxFrequencyElements(int[] nums) {
            int answer = 0;
            int maxFrequency = 0;
            Map<Integer, Integer> frequency = new HashMap<>();
            for (int num : nums) {
                frequency.put(num, frequency.getOrDefault(num, 0) + 1);
                maxFrequency = Math.max(maxFrequency, frequency.get(num));
            }

            for (Map.Entry<Integer, Integer> entry : frequency.entrySet()) {
                if (entry.getValue() == maxFrequency) {
                    answer += maxFrequency;
                }
            }


            return answer;
        }

    }

    public void main(String[] args) {
        int[] nums;
        int answer;

        Solution solution = new Solution();

        nums = new int[]{1, 2, 2, 3, 1, 4};
        answer = 4;
        assert answer == solution.maxFrequencyElements(nums) : "Answer is different";

        nums = new int[]{1, 2, 3, 4, 5};
        answer = 5;
        assert answer == solution.maxFrequencyElements(nums) : "Answer is different";

    }

}
