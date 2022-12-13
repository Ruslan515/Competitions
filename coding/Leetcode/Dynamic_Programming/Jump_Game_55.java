// https://leetcode.com/problems/jump-game/
package DP;

import java.util.Scanner;

public class Jump_Game_55 {
    public static boolean canJump(int[] nums) {
        int n = nums.length;
        int[] dp = new int[n];
        dp[0] = 1;
        for (int i = 1; i < n; i++) {
            int sum = 0;
            for (int j = 0; j < i; j++) {
                if (nums[j] + j >= i && dp[j] != 0)
                    sum += 1;
            }
            dp[i] = sum;
        }
        boolean ans = true;
        if (dp[n - 1] == 0)
            ans = false;

        return ans;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] nums = new int[n];
        for (int i = 0; i < n; i++)
            nums[i] = sc.nextInt();
        System.out.println(canJump(nums));
    }
}
