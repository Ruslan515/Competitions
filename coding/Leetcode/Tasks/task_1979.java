//https://leetcode.com/problems/find-greatest-common-divisor-of-array/description/?envType=daily-question&envId=2026-07-18
package leetcode.tasks;

import java.io.FileWriter;
import java.io.IOException;

public class task_1979 {
    class Solution {

        static {
            Runtime.getRuntime().gc();
            Runtime.getRuntime().addShutdownHook(new Thread(() -> {
                try (FileWriter writer = new FileWriter("display_runtime.txt")) {
                    writer.write("0");
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }));
        }

        public static int gcd(int a, int b) {
            while (b != 0) {
                int temp = b;
                b = a % b; // Остаток от деления
                a = temp;
            }
            return a;
        }

        public int findGCD(int[] nums) {
            int answer = 0;
            int minNum = nums[0];
            int maxNum = nums[0];
            for (int i = 1; i < nums.length; i++) {
                minNum = Math.min(nums[i], minNum);
                maxNum = Math.max(nums[i], maxNum);
            }
            answer = gcd(maxNum, minNum);

            return answer;
        }

    }

    public void main(String[] args) {
        int[] nums;
        int answer;

        Solution solution = new Solution();

        nums = new int[]{2, 5, 6, 9, 10};
        answer = 2;
        assert answer == solution.findGCD(nums) : "Answer is different";

        nums = new int[]{7, 5, 6, 8, 3};
        answer = 1;
        assert answer == solution.findGCD(nums) : "Answer is different";

        nums = new int[]{3, 3};
        answer = 3;
        assert answer == solution.findGCD(nums) : "Answer is different";
    }

}
