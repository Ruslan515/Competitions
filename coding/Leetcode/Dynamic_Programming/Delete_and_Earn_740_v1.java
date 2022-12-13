package DP;

import java.util.HashMap;
import java.util.Scanner;

public class Delete_and_Earn_740_v1 {
    public static int deleteAndEarn(int[] nums) {
        int[] count = new int[10001];
        for(int num: nums) {
            count[num]++;
        }
        int prev = -1;
        int in = 0;
        int ex = 0;
        for (int k = 0; k < count.length; k++) {
            int m = Math.max(in, ex);
            if (k - 1 != prev) {
                in = k * count[k] + m;
            }
            else {
                in = k * count[k] + ex;

            }
            ex = m;
            prev = k;
        }


        return Math.max(in, ex);
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] nums = new int[n];
        for (int i = 0; i < n; i++)
            nums[i] = sc.nextInt();
        System.out.println(deleteAndEarn(nums));
    }
}
