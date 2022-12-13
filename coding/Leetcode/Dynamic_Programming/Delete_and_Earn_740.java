package DP;

import java.util.HashMap;
import java.util.Scanner;

public class Delete_and_Earn_740 {
    public static int deleteAndEarn(int[] nums) {
        HashMap<Integer, Integer> my_map = new HashMap<Integer, Integer>();
        for(int num: nums) {
            my_map.put(num, my_map.getOrDefault(num, 0) + 1);
        }
        int prev = -1;
        int in = 0;
        int ex = 0;
        for (int key: my_map.keySet()) {
            int m = Math.max(in, ex);
            if (key - 1 != prev) {
                in = key * my_map.get(key) + m;
            }
            else {
                in = key * my_map.get(key) + ex;

            }
            ex = m;
            prev = key;
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
