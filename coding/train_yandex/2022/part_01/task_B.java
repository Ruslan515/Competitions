/*
https://contest.yandex.ru/contest/39359/problems/B/
 */
package Yandex_learning.part_01;

import java.util.Scanner;

public class task_B {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.nextLine();
        boolean label = true;
        while (label) {
            s = s.replace("/../", "/");
            s = s.replace("//", "/");
        }
        if (s.charAt(s.length() - 1) == '/' && s.length() > 1)
            s = s.substring(0, s.length() - 1);
        System.out.println(s);
    }
}
