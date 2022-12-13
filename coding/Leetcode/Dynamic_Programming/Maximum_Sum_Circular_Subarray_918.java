// https://leetcode.com/problems/jump-game/
package DP;

import java.util.Scanner;

public class Maximum_Sum_Circular_Subarray_918 {
    public static int maxSubArray(int[] nums) {
        int n = nums.length;
        int n2 = 2 * n - 2;
        int[] temp = new int[n2];
        for (int i = 0; i < n - 1; ++i) {
            temp[i] = nums[i + 1];
        }
        for (int i = n - 1; i < n2; ++i) {
            temp[i] = nums[i - n + 1];
        }


        int current = temp[0];
        int max_sub = temp[0];
        for (int i = 1; i < n2; i++) {
            if (current > 0)
                current += temp[i];
            else
                current = temp[i];

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
