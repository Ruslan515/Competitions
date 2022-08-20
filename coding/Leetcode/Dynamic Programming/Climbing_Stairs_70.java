package DP;

import java.util.Arrays;
import java.util.Scanner;

public class Climbing_Stairs_70 {
    public static int memFib(int n, int[] mem){
        if (mem[n] != -1) {
            return mem[n];
        } else if (n < 2) {
            mem[n] = n;
        }
        else {
            mem[n] = memFib(n - 2, mem) + memFib(n - 1, mem);
        }
        return mem[n];
    }
    public static int climbStairs(int n) {
        n++;
        int[] mem = new int[n + 1];
        Arrays.fill(mem, -1);
        int ans = memFib(n, mem);
        return ans;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        System.out.println(climbStairs(n));
    }
}
