/*
https://stepik.org/lesson/13258/step/8?unit=3443
 */
package Stepik.algo_csc.DP;

import java.util.Scanner;

public class EditDist {
    public static void main(String[] args) {
        Scanner sc  = new Scanner(System.in);
        String s1 = sc.nextLine();
        String s2 = sc.nextLine();
        int n = s1.length() + 1;
        int m = s2.length() + 1;
        int[][] dp = new int[n][m];
        for (int i = 0; i < n; i++)
            dp[i][0] = i;
        for (int j = 0; j < m; j++)
            dp[0][j] = j;

        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                int c = 0;
                if (s1.charAt(i - 1) != s2.charAt(j - 1))
                    c = 1;
                dp[i][j] = (
                        Math.min(
                                dp[i][j - 1] + 1,
                                Math.min(
                                        dp[i - 1][j] + 1,
                                        dp[i - 1][j - 1] + c
                                )
                        )
                );
            }
        }

        System.out.println(dp[n - 1][m - 1]);

        return;

    }
}
