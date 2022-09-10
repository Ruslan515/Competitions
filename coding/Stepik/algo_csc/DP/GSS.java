/*
https://stepik.org/lesson/13257/step/5?unit=3442
 */
package Stepik.algo_csc.DP;

import java.util.Scanner;

public class GSS {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++)
            a[i] = sc.nextInt();

        int[] dp = new int[n];
        dp[0] = 1;
        int ans = dp[0];
        for (int i = 1; i < n; i++) {
            dp[i] = 1;
            for (int j = 0; j < i; j++) {
                if (a[i] % a[j] == 0 && dp[j] + 1 > dp[i])
                    dp[i] = dp[j] + 1;
            }
            if (dp[i] > ans)
                ans = dp[i];
        }
        System.out.println(ans);

    }
}
