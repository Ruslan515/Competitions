//https://leetcode.com/problems/minimum-operations-to-convert-all-elements-to-zero/description/?envType=daily-question&envId=2025-11-10
package leetcode.tasks;

import java.util.PriorityQueue;

public class task_3542 {
    class Solution {
        public int minOperations(int[] nums) {
            int answer = 0;

            PriorityQueue<Integer> pq = new PriorityQueue<>();
            for (int num : nums) {
                if (num != 0) {
                    pq.offer(num);
                }
            }

            int current;
            while (!pq.isEmpty()) {
                current = pq.peek();
                while (!pq.isEmpty() && pq.peek() == current) {
                    pq.poll();
                }
                answer++;
            }

            return answer;
        }
    }

    public void main(String[] args) {
        int[] nums;
        int answer;

        Solution solution = new Solution();

        nums = new int[]{1, 2, 1, 2, 1, 2};
        answer = 4;
        assert answer == solution.minOperations(nums) : "Answer is different";

        nums = new int[]{0, 2};
        answer = 1;
        assert answer == solution.minOperations(nums) : "Answer is different";

        nums = new int[]{3, 1, 2, 1};
        answer = 3;
        assert answer == solution.minOperations(nums) : "Answer is different";
    }

}
