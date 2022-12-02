package DP;

import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Delete_and_Earn_740_v2 {
    static int maxPoints(
            int num,
            Map<Integer, Integer> points,
            Map<Integer, Integer> cache
    ) {
        int answer = 0;
        if (num == 0) {
            answer = 0;
        } else if (num == 1) {
            answer = points.getOrDefault(1, 0);
        } else if (cache.containsKey(num)) {
            answer = cache.get(num);
        }
        else {
            cache.put(
                    num,
                    Math.max(
                            maxPoints(num - 1, points, cache),
                            maxPoints(num - 2,  points, cache) + points.getOrDefault(num, 0)
                    )
            );
            answer = cache.get(num);

        }
        return answer;
    }
    public static int deleteAndEarn(int[] nums) {
        int answer = 0;
        Map<Integer, Integer> points = new HashMap<>();
        Map<Integer, Integer> cache = new HashMap<>();
        int maxNumber = 0;

        for (int num: nums) {
            points.put(num, points.getOrDefault(num, 0) + num);
            maxNumber = Math.max(maxNumber, num);
        }

        answer = maxPoints(maxNumber, points, cache);

        return answer;
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
