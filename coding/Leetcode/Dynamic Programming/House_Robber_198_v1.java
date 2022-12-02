package DP;

import java.util.Scanner;

public class House_Robber_198_v1 {
    public static int rob(int[] nums) {
        int answer = 0;
        int n = nums.length;
        int[] dp = new int[n + 1];
//        dp[0] = 0;
        dp[0] = 0;
        int global_max = dp[0];
        for(int i = 1; i < n + 1; ++i) {
            int max_dp = dp[0];
            for (int j = 1; j < i - 1; ++j) {
                if (max_dp < dp[j]) {
                    max_dp = dp[j];
                }
            }
            dp[i] = max_dp + nums[i - 1];
            if (dp[i] > global_max) {
                global_max = dp[i];
            }
        }

        answer = global_max;
        return answer;
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
