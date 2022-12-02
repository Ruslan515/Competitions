package DP;

import java.util.Scanner;

public class Maximum_Product_Subarray_152_v1 {
    public static int maxProduct(int[] nums) {
        int n = nums.length;
        int current = nums[0];
        int max_so_far = nums[0];
        int min_so_far = nums[0];
        int global_max = max_so_far;
        for (int i = 1; i < n; ++i) {
            current = nums[i];
            int temp_max = current * max_so_far;
            int temp_min = current * min_so_far;
            max_so_far = Math.max(current, Math.max(temp_max, temp_min));
            if (max_so_far > global_max) {
                global_max = max_so_far;
            }
            min_so_far = Math.min(current, Math.min(temp_min, temp_max));
        }

        return global_max;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] nums = new int[n];
        for (int i = 0; i < n; i++)
            nums[i] = sc.nextInt();
        System.out.println(maxProduct(nums));
    }
}
