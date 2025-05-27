package leetcode.tasks;

public class task_3355 {
    class Solution {
        public boolean isZeroArray(int[] nums, int[][] queries) {
            boolean answer = true;
            int n = nums.length;
            int[] prefixSum = new int[n];
            prefixSum[0] = nums[0];
            for (int i = 1; i < n; i++) {
                prefixSum[i] = prefixSum[i - 1] + nums[i];
            }
            int allSums = prefixSum[n - 1];

            int diff, cnt, minSum;
            for (int i = 0; i < queries.length; i++) {
                int[] query = queries[i];
                int l = query[0];
                int r = query[1];
                cnt = r - l + 1;
                diff = prefixSum[r] - prefixSum[l] + nums[l];
                minSum = Math.min(cnt, diff);
                allSums -= minSum;
            }
            if (allSums != 0) {
                answer = false;
            }

            return answer;
        }
    }

    public static void main(String[] args) {
        int[] nums;
        int[][] queries;

        boolean x;
        boolean answer;

        Solution solution = new task_3355().new Solution();

        nums = new int[]{2};
        queries = new int[][]{{0, 0}, {0, 0}, {0, 0}};
        answer = false;
        x = solution.isZeroArray(nums, queries);
        assert answer == x : "Answer is different";

        nums = new int[]{2};
        queries = new int[][]{{0, 0}, {0, 0}};
        answer = true;
        x = solution.isZeroArray(nums, queries);
        assert answer == x : "Answer is different";

        nums = new int[]{1, 0, 1};
        queries = new int[][]{{0, 2}};
        answer = true;
        x = solution.isZeroArray(nums, queries);
        assert answer == x : "Answer is different";

        nums = new int[]{4, 3, 2, 1};
        queries = new int[][]{{1, 3}, {0, 2}};
        answer = false;
        x = solution.isZeroArray(nums, queries);
        assert answer == x : "Answer is different";

    }
}
