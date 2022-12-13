package DP;

import java.util.Arrays;
import java.util.Map;
import java.util.Scanner;

public class House_Robber_II_213_v1 {

    public static int sub_rob(int[] nums) {
        int answer = 0;
        int n = nums.length;
        int[] dp = new int[n + 1];
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

    public static int rob(int[] nums) {
        int n = nums.length;
        int answer = 0;
        if (n <= 3) {
            int gl_max = nums[0];
            for (int i = 1; i < n; ++i) {
                gl_max = Math.max(gl_max, nums[i]);
            }
            answer = gl_max;
        }
        else {
            int max_1 = sub_rob(Arrays.copyOfRange(nums, 0, n - 1));
            int max_2 = sub_rob(Arrays.copyOfRange(nums, 1, n));
            answer = Math.max(max_1, max_2);
        }
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
