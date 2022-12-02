// https://leetcode.com/problems/jump-game/
package DP;

import java.util.Scanner;

public class Jump_Game_55_X {
//    dp[i] - i > 1, можно ли добраться до i-й ячейки с 1ой. если все true - можно добраться
    public static boolean canJump(int[] nums) {
        int n = nums.length;
        boolean answer = false;
        if (n == 1) {
            answer = true;
        } else if (n == 2) {
            if (nums[0] > 0) {
                answer = true;
            }
        }
        else {
            boolean[] dp = new boolean[n + 1];
            dp[0] = true;
            dp[1] = true;
            for (int i = 1; i < n + 1; ++i) {
                int k = nums[i - 1];
                for (int j = 0; j < k && (i + j) < n; ++j) {
                    dp[i + j + 1] = true;
                }
            }
            answer = dp[0];
            for (int i = 1; i < n + 1; ++i) {
                answer = answer && dp[i];
            }
        }
        return answer;

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
