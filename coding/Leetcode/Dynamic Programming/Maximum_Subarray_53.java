// https://leetcode.com/problems/jump-game/
package DP;

import java.util.Scanner;

public class Maximum_Subarray_53 {
    public static int maxSubArray(int[] nums) {
        Integer inf = Integer.MAX_VALUE * (-1);
        int n = nums.length;
        int[] dp = new int[n];
        dp[0] = nums[0];
        int global_max = dp[0];
        for (int i = 1; i < n; i++) {
            int max_sum = inf;
            for (int j = 0; j <= i; j++) {
                int temp_sum = 0;
                for (int k = j; k <= i; k++)
                    temp_sum += nums[k];
                if (temp_sum > max_sum)
                    max_sum = temp_sum;
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
