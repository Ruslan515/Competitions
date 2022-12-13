// https://leetcode.com/problems/longest-increasing-subsequence/description/
package DP;

import java.util.Scanner;

public class task_300 {
    public static int lengthOfLIS(int[] nums) {
        int n = nums.length;
        int[] dp = new int[n + 1];
        dp[0] = 0;
        dp[1] = 1;
        int global_max = 1;
        for (int i = 2; i < n + 1; ++i) {
            int num = nums[i - 1];
            int local_max = dp[0];
            for(int j = 0; j < i - 1; ++j) {
                if (nums[j] < num) {
                    local_max = Math.max(local_max, dp[j + 1]);
                }
            }

            dp[i] = local_max + 1;
            global_max = Math.max(global_max, dp[i]);
        }

        return global_max;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] nums = new int[n];
        for (int i = 0; i < n; i++)
            nums[i] = sc.nextInt();
        System.out.println(lengthOfLIS(nums));
    }
}
