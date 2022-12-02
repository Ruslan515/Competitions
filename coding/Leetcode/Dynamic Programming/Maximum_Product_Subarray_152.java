package DP;

import java.util.Scanner;

public class Maximum_Product_Subarray_152 {
    public static int maxProduct(int[] nums) {
        int n = nums.length;
        int current = nums[0];
        int max_prod = nums[0];
        for (int i = 1; i < n; ++i) {
            if ((current > 0 && nums[i] > 0) || (current < 0 && nums[i] < 0)) {
                current *= nums[i];
            }
            else {
                current = nums[i];
            }
            if (current > max_prod) {
                max_prod = current;
            }

        }

        return max_prod;
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
