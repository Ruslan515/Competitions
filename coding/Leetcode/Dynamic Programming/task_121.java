//https://leetcode.com/problems/best-time-to-buy-and-sell-stock/?envType=study-plan&id=dynamic-programming-i
package DP;

import java.util.Scanner;

public class task_121 {
    public static int maxProfit(int[] prices) {
        int n = prices.length;
        int global_min = prices[0];
        int profit = 0;
        for (int i = 1; i < n; ++i) {
            int temp_profit = prices[i] - global_min;
            if (temp_profit > profit) {
                profit = temp_profit;
            }
            else if (prices[i] < global_min){
                global_min = prices[i];
            }
        }
        return profit;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] nums = new int[n];
        for (int i = 0; i < n; i++)
            nums[i] = sc.nextInt();
        System.out.println(maxProfit(nums));
    }

}
