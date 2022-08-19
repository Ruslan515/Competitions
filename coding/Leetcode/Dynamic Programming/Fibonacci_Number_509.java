// https://leetcode.com/tag/dynamic-programming/
package DP;

import java.util.Arrays;

public class Fibonacci_Number_509 {
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
    public static int fib(int n) {
        int[] mem = new int[n + 1];
        Arrays.fill(mem, -1);
        int ans = memFib(n, mem);
        return ans;
    }
    public static void main(String[] args) {
        int n = 30;
        System.out.println(fib(n));
    }
}
