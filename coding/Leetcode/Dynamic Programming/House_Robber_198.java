package DP;

import java.util.Scanner;

public class House_Robber_198 {

    public static int rob(int[] nums) {
        if (nums.length == 1)
            return nums[0];
        else if (nums.length == 2) {
            return Math.max(nums[0], nums[1]);
        }
        int n1 = nums.length + 1;
        int[] dp = new int[n1];
        dp[1] = nums[0];
        int global_max = dp[1];
        for (int i = 2; i < n1; i++) {
            int max = dp[0];
            for (int j = 1; j < i - 1; j++) {
                if (dp[j] > max) {
                    max = dp[j];
                }
            }
            dp[i] = max + nums[i - 1];
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
        System.out.println(rob(nums));
    }
}
