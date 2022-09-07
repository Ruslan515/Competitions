/*
https://contest.yandex.ru/contest/39359/problems/A/
 */
package Yandex_learning.part_01;

import java.util.Scanner;

public class task_A {
    public static int true_func(int n) {
        int sum = 0;
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            sum += i;
            if (sum > n) {
                ans = i - 1;
                break;
            }
        }

        return ans;
    }

    public static  int not_true_func(int n) {
        int ans = 0;
        if (n % 2 == 0) {
            ans = n / 2 - 1;
        }
        else {
            ans = (n - 1) / 2;
        }
        return ans;
    }

    public static  int func(int n) {
        int ans = (int) Math.ceil((Math.sqrt(4 * n + 1) - 1) / 2);
        return ans;
    }


    public static final int func1(int n) {
        int nowinrow = 1;
        int rows = 0;
        while (n >= nowinrow) {
            n -= nowinrow;
            rows++;
            nowinrow += 1;
        }
        return rows;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        if (n == 1 || n == 2) {
            System.out.println(1);
            return;
        }

        System.out.println(func1(n));

//        int j = 8;
//        int tr;
//        int not_tr;
//        int t;
//        while (true) {
//            tr = true_func(j);
//            not_tr = not_true_func(j);
//            t = func1(j);
//            if (tr != t) {
//                System.out.println(tr + "\t" + t + "\t" + not_tr);
//                System.out.println(j);
//                break;
//            }
//            j++;
//        }

    }
}
