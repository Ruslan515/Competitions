package DP;

import java.util.Arrays;

public class Tribonacci_Number_1137 {
    public static int memTri(int n, int[] mem){
        if (mem[n] != -1) {
            return mem[n];
        } else if (n < 2) {
            mem[n] = n;
        }
        else {
            mem[n] = (
                    memTri(n - 3, mem) +
                            memTri(n - 2, mem) +
                            memTri(n - 1, mem)
            );
        }
        return mem[n];
    }
    public static int tribonacci(int n) {
        int[] mem = new int[n + 1];
        Arrays.fill(mem, -1);
        mem[0] = 0;
        mem[1] = 1;
        mem[2] = 1;
        int ans = memTri(n, mem);
        return ans;
    }
    public static void main(String[] args) {
        int n = 25;
        System.out.println(tribonacci(n));
    }
}
