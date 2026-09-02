//https://leetcode.com/problems/find-subsequence-of-length-k-with-the-largest-sum/description/?envType=problem-list-v2&envId=heap-priority-queue
package leetcode.tasks;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.PriorityQueue;

public class task_2099 {
    class Solution {
        public int[] maxSubsequence(int[] nums, int k) {
            int n = nums.length;
            if (n == k) return nums;
            int[] answer = new int[k];
            PriorityQueue<int[]> pq = new PriorityQueue<>(
                    (a, b) -> {
                        if (a[0] != b[0]) {
                            return b[0] - a[0];
                        } else {
                            return a[1] - b[1];
                        }

                    }
            );
            PriorityQueue<int[]> pqIdx = new PriorityQueue<>(
                    (a, b) -> a[1] - b[1]  // сортировка по убыванию по первому элементу
            );

            for (int i = 0; i < n; ++i) {
                pq.offer(new int[]{nums[i], i});
            }
            int idx, val;
            for (int i = 0; i < k; i++) {
                int[] item = pq.poll();
                pqIdx.offer(item);
            }
            for (int i = 0; i < k; i++) {
                int[] item = pqIdx.poll();
                val = item[0];
                answer[i] = val;
            }


            return answer;
        }

    }

    public void main(String[] args) {
        int[] nums;
        int k;
        int[] answer;

        Solution solution = new Solution();

        nums = new int[]{-1, -2, 3, 4};
        k = 3;
        answer = new int[]{-1, 3, 4};
        assert Arrays.equals(answer, solution.maxSubsequence(nums, k)) : "Answer is different";

        nums = new int[]{63, -74, 61, -17, -55, -59, -10, 2, -60, -65};
        k = 9;
        answer = new int[]{63, 61, -17, -55, -59, -10, 2, -60, -65};
        assert Arrays.equals(answer, solution.maxSubsequence(nums, k)) : "Answer is different";

        nums = new int[]{3, 4, 3, 3};
        k = 2;
        answer = new int[]{3, 4};
        assert Arrays.equals(answer, solution.maxSubsequence(nums, k)) : "Answer is different";

        nums = new int[]{50, -75};
        k = 2;
        answer = new int[]{50, -75};
        assert Arrays.equals(answer, solution.maxSubsequence(nums, k)) : "Answer is different";

        nums = new int[]{2, 1, 3, 3};
        k = 2;
        answer = new int[]{3, 3};
        assert Arrays.equals(answer, solution.maxSubsequence(nums, k)) : "Answer is different";

    }

}
