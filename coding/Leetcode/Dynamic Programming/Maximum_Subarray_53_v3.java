// https://leetcode.com/problems/jump-game/
package DP;

import java.util.Scanner;

public class Maximum_Subarray_53_v3 {
    public static int maxSubArray(int[] nums) {
        int n = nums.length;
        int current = nums[0];
        int max_sub = nums[0];
        for (int i = 1; i < n; i++) {
            if (current > 0)
                current += nums[i];
            else
                current = nums[i];

            if (current > max_sub)
                max_sub = current;

        }
        return max_sub;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] nums = new int[n];
        for (int i = 0; i < n; i++)
            nums[i] = sc.nextInt();
        System.out.println(maxSubArray(nums));
    }
}
