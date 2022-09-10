/*
https://stepik.org/lesson/13257/step/6?unit=3442
 */
package Stepik.algo_csc.DP;

import java.util.Arrays;
import java.util.Scanner;

public class L_not_IS_log_N {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++)
            a[i] = sc.nextInt();
        if (n == 1) {
            System.out.println(1);
            System.out.println(a[0]);
            return;
        }
        int[] dp = new int[n + 1];
        int[] position = new int[n + 1];
        int[] prev = new int[n];

        int INF = Integer.MAX_VALUE;
        Arrays.fill(dp, (-1) * INF);

        dp[0] = INF;
        position[0] = -1;
        int len = 0;
        for (int i = 0; i < n; i++) {
            int left = 0;
            int right = n;
            while (right - left > 1) {
                int middle = (left + right) / 2;
                if (dp[middle] < a[i])
                    right = middle;
                else
                    left = middle;
            }
            dp[right] = a[i];
            position[right] = i;
            prev[i] = position[right - 1];
            len = Math.max(len, right);
        }
        int i = n;
        while (dp[i] == (-1) * INF)
            i--;
        int ans = i;
        System.out.println(ans);

        int[] answer = new int[ans];
        i = 0;
        int p = position[len];
        while (p != -1) {
            answer[i] = p + 1;
            p = prev[p];
            i++;
        }

//        for (int j = 0; j < ans; j++)
//            System.out.print(answer[j] + " ");

        for (int j = ans - 1; j >= 0; j--)
            System.out.print(answer[j] + " ");
    }
}
