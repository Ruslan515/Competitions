package DP;

import java.util.Scanner;

public class Maximum_Length_of_Subarray_With_Positive_Product_1567 {
    public static int getMaxLen(int[] nums) {
        int n = nums.length;
        int[] pos = new int[n];
        int[] neg = new int[n];
        if (nums[0] > 0) pos[0] = 1;
        if (nums[0] < 0) neg[0] = 1;
        int ans = pos[0];
        for (int i = 1; i < n; i++) {
            if (nums[i] > 0) {
                pos[i] = 1 + pos[i - 1];
                neg[i] = neg[i - 1] > 0 ? 1 + neg[i - 1]:0;
            } else if (nums[i] < 0) {
                pos[i] = neg[i - 1] > 0 ? 1 + neg[i - 1]:0;
                neg[i] = 1 + pos[i - 1];
            }
            ans = Math.max(ans, pos[i]);
        }
        return ans;

    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] nums = new int[n];
        for (int i = 0; i < n; i++)
            nums[i] = sc.nextInt();
        System.out.println(getMaxLen(nums));
    }
}
