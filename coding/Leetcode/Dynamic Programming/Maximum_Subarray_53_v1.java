// https://leetcode.com/problems/jump-game/
package DP;

import java.util.Scanner;

public class Maximum_Subarray_53_v1 {
    public static int maxSubArray(int[] nums) {
        Integer inf = Integer.MAX_VALUE * (-1);
        int n = nums.length;
        int[] dp = new int[n];
        int[][] arr_sum = new int[n][n];
        for (int start = 0; start < n; start++) {
            for (int end = start; end < n; end++) {
                int sum = 0;
                for (int k = start; k <= end; k++)
                    sum += nums[k];
                arr_sum[start][end] = sum;
            }
            System.out.println(1);
        }

        dp[0] = nums[0];
        int global_max = dp[0];
        for (int i = 1; i < n; i++) {
            int max_sum = inf;
            for (int j = 0; j <= i; j++) {
                if (arr_sum[j][i] > max_sum)
                    max_sum = arr_sum[j][i];
            }

            dp[i] = max_sum;
            if (dp[i] > global_max)
                global_max = dp[i];
        }
        return global_max;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] nums = new int[n];
        for (int i = 0; i < n; i++)
            nums[i] = sc.nextInt();
        System.out.println(maxSubArray(nums));
    }
}
