package DP;

import java.util.Arrays;
import java.util.Collections;
import java.util.Scanner;

public class House_Robber_II_213_v2 {
    public static int rob(int[] nums) {
        int answer = 0;
        int n = nums.length;
        if (n <= 3) {
            Arrays.sort(nums);
            answer = nums[n - 1];
        }
        else {
            int g0 = nums[0];
            for (int i = 2; i < n - 1; i += 2) {
                g0 += nums[i];
            }
            int g1 = nums[1];
            for (int i = 3; i < n; i += 2) {
                g1 += nums[i];
            }
            if (g1 > g0) {
                answer = g1;
            }
            else {
                answer = g0;
            }

        }

        return answer;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] nums = new int[n];
        for (int i = 0; i < n; i++)
            nums[i] = sc.nextInt();
        System.out.println(rob(nums));
    }
}
