package Stepik.algo_csc.DP;

import java.util.Scanner;

public class Backpack_Task {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int weight = sc.nextInt();
        int n = sc.nextInt();
        int[] w_i = new int[n];
        for (int i = 0; i < n; i++)
            w_i[i] = sc.nextInt();

        int[][] dp = new int[n + 1][weight + 1];

        for (int i = 1; i < n + 1; i++) {
            for(int w = 1; w < weight + 1; w++) {
                dp[i][w] = dp[i - 1][w];
                if (w_i[i - 1] <= w)
                    dp[i][w] = (
                            Math.max(
                                    dp[i][w],
                                    dp[i - 1][w - w_i[i - 1]] + w_i[i - 1]
                            )
                    );
            }
        }
        System.out.println(dp[n][weight]);

        return;
    }
}
