package DP;

import java.util.Arrays;
import java.util.Scanner;

public class Min_Cost_746 {

    public static int minCostClimbingStairs(int[] cost) {
        Integer inf = 1000;
        int n = cost.length;
        int ans = 0;
        int[] dp = new int[n + 2];
        dp[0] = inf;
        dp[1] = 0;
        for (int i = 2; i < n + 1; i++) {
            int one_step = dp[i - 1] + cost[i - 1];
            int two_step = dp[i - 2] + cost[i - 2];
            int min;
            if (one_step < two_step)
                min = one_step;
            else
                min = two_step;
            dp[i] = min;
        }
        ans = dp[n];


        return ans;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] cost = new int[n];
        for (int i = 0; i < n; i++)
            cost[i] = sc.nextInt();
        System.out.println(minCostClimbingStairs(cost));
    }
}
