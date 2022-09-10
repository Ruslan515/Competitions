/*
https://stepik.org/lesson/13257/step/6?unit=3442
 */
package Stepik.algo_csc.DP;

import java.io.*;
import java.util.StringTokenizer;

class MyReader{
    private BufferedReader reader = null;
    private StringTokenizer tokenizer = null;
    MyReader(Reader r) throws IOException{
        reader = new BufferedReader(r);
    }
    public int nextInt() throws IOException {
        return Integer.parseInt(nextToken());
    }
    public String nextToken() throws IOException {
        while (tokenizer == null || !tokenizer.hasMoreTokens()) {
            tokenizer = new StringTokenizer(reader.readLine());
        }
        return tokenizer.nextToken();
    }
}

public class L_not_IS_square_N {
    public static void main(String[] args) throws IOException {
        MyReader sc = new MyReader(new InputStreamReader(System.in));
//        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++)
            a[i] = sc.nextInt();

        int[] dp = new int[n];
        dp[0] = 1;
        int ans = dp[0];
        int idx = 0;
        for (int i = 1; i < n; i++) {
            dp[i] = 1;
            for (int j = 0; j < i; j++) {
                if (a[j] >= a[i] && dp[j] + 1 > dp[i])
                    dp[i] = dp[j] + 1;
            }
            if (dp[i] > ans) {
                ans = dp[i];
                idx = i;
            }

        }

        System.out.println(ans);

        int[] el = new int[ans];
        int j = ans - 1;
        while (ans != 0) {
            int i = idx;
            while (dp[i] != ans)
                i--;
            idx = i;
            el[j] = i + 1;
            j--;
            ans--;
        }
        for (int i = 0; i < el.length; i++)
            System.out.print(el[i] + " ");


    }
}
