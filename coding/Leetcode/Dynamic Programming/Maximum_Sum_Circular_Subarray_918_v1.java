// https://leetcode.com/problems/jump-game/
package DP;

import java.util.Scanner;

public class Maximum_Sum_Circular_Subarray_918_v1 {
    public static int maxSubArray(int[] nums) {
        int N = nums.length;

        int ans = nums[0], cur = nums[0];
        for (int i = 1; i < N; ++i) {
            cur = nums[i] + Math.max(cur, 0);
            ans = Math.max(ans, cur);
        }

        // ans is the answer for 1-interval subarrays.
        // Now, let's consider all 2-interval subarrays.
        // For each i, we want to know
        // the maximum of sum(nums[j:]) with j >= i+2

        // rightsums[i] = nums[i] + nums[i+1] + ... + nums[N-1]
        int[] rightsums = new int[N];
        rightsums[N-1] = nums[N-1];
        for (int i = N-2; i >= 0; --i)
            rightsums[i] = rightsums[i+1] + nums[i];

        // maxright[i] = max_{j >= i} rightsums[j]
        int[] maxright = new int[N];
        maxright[N-1] = nums[N-1];
        for (int i = N-2; i >= 0; --i)
            maxright[i] = Math.max(maxright[i+1], rightsums[i]);

        int leftsum = 0;
        for (int i = 0; i < N-2; ++i) {
            leftsum += nums[i];
            ans = Math.max(ans, leftsum + maxright[i+2]);
        }

        return ans;
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
