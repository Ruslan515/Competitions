// https://leetcode.com/problems/jump-game/
package DP;

import java.util.Scanner;

public class Jump_Game_II_45_X {
    public static int jump(int[] nums) {
        int answer = 0;
        int n = nums.length;
        int[] dp = new int[n];
        dp[0] = -1;
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                int s = nums[j] + j;
                if (s >= i) {
                    dp[i] = j;
                    break;
                }
            }
        }

        int count = 0;
        int i = dp[n - 1];
        while (i != -1) {
            count++;
            i = dp[i];
        }
        answer = count;

        return answer;
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
