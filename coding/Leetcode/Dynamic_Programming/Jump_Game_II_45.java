// https://leetcode.com/problems/jump-game/
package DP;

import java.util.Scanner;

public class Jump_Game_II_45 {
    public static int jump(int[] nums) {
        Integer inf = Integer.MAX_VALUE;
        int n = nums.length;
        int[] dp = new int[n];
        dp[0] = 0;
        for (int i = 1; i < n; i++) {
            int min = inf;
            for (int j = 0; j < i; j++) {
                if (nums[j] + j >= i && dp[j] < min)
                    min = dp[j];
            }

            dp[i] = min + 1;
        }
        return dp[n - 1];
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] nums = new int[n];
        for (int i = 0; i < n; i++)
            nums[i] = sc.nextInt();
        System.out.println(jump(nums));
    }
}
