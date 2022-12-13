//https://leetcode.com/problems/maximum-score-from-performing-multiplication-operations/
package DP;

import java.util.Scanner;

public class task_1770 {
    public static int maximumScore(int[] nums, int[] multipliers) {
        int n = nums.length;
        int m = multipliers.length;
        int[][] dp = new int[m + 1][m + 1];

        for (int i = m - 1; i >= 0; i--) {
            int mult = multipliers[i];
            for (int left = i; left >= 0; left--) {
                int right = n - 1 - (i - left);
                int t1 = nums[left];
                t1 *= mult;
                t1 += + dp[i + 1][left + 1];
                int t2 = nums[right];
                t2 *= mult;
                t2 += dp[i + 1][left];
                dp[i][left] = Math.max(t1, t2);
            }
        }

        return dp[0][0];
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] nums = new int[n];
        for (int i = 0; i < n; i++)
            nums[i] = sc.nextInt();
        int m = sc.nextInt();
        int[] multipliers = new int[m];
        for (int i = 0; i < m; i++)
            multipliers[i] = sc.nextInt();
        System.out.println(maximumScore(nums, multipliers));
    }

}
