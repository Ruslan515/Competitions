// https://leetcode.com/problems/sum-of-elements-with-frequency-divisible-by-k/description/
package leetcode.weekly.w_471;


import java.util.HashMap;
import java.util.Map;

public class task_q1 {
    class Solution {
        public int sumDivisibleByK(int[] nums, int k) {
            int answer = 0;
            Map<Integer, Integer> map = new HashMap<>();
            for (int num : nums) {
                map.put(num, map.getOrDefault(num, 0) + 1);
            }
            for (int num : map.keySet()) {
                if (map.get(num) % k == 0) {
                    answer += num * map.get(num);
                }
            }


            return answer;
        }


    }

    public void main(String[] args) {
        int[] nums;
        int k;
        int answer;

        Solution solution = new Solution();

        nums = new int[]{1, 2, 2, 3, 3, 3, 3, 4};
        k = 2;
        answer = 16;
        assert answer == solution.sumDivisibleByK(nums, k) : "Answer is different";

        nums = new int[]{1, 2, 3, 4, 5};
        k = 2;
        answer = 0;
        assert answer == solution.sumDivisibleByK(nums, k) : "Answer is different";


        nums = new int[]{4, 4, 4, 1, 2, 3};
        k = 3;
        answer = 12;
        assert answer == solution.sumDivisibleByK(nums, k) : "Answer is different";

    }

}
