//https://leetcode.com/problems/best-sightseeing-pair/?envType=study-plan&id=dynamic-programming-i
package DP;

import java.util.Scanner;

public class task_1014 {
    public static int maxScoreSightseeingPair(int[] values) {
        int score = 0;
        return score;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] nums = new int[n];
        for (int i = 0; i < n; i++)
            nums[i] = sc.nextInt();
        System.out.println(maxScoreSightseeingPair(nums));
    }

}
