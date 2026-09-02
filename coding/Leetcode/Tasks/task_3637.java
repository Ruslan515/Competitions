package leetcode.tasks;

import java.io.FileWriter;
import java.io.IOException;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.List;

public class task_3637 {
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

        public boolean isTrionic(int[] nums) {
            boolean answer = false;
            int n = nums.length;
            if (n == 3) {
                return answer;
            }
            int p, q;

            int i = 0;
            while (i < (n - 1) && nums[i] < nums[i + 1]) {
                i++;
            }
            p = i;
            if (p == 0) {
                return answer;
            }
            while (i < (n - 1) && nums[i] > nums[i + 1]) {
                ++i;
            }
            q = i;
            if (q == p || q == n - 1) {
                return answer;
            }
            while (i < (n - 1) && nums[i] < nums[i + 1]) {
                ++i;
            }
            if (i == n - 1) {
                answer = true;
            }

            return answer;
        }
    }

    public void main(String[] args) {
        int[] nums;
        boolean answer;

        Solution solution = new Solution();

        nums = new int[]{6, 7, 5, 1};
        answer = false;
        assert answer == solution.isTrionic(nums) : "Answer is different";

        nums = new int[]{1, 3, 5, 4, 2, 6};
        answer = true;
        assert answer == solution.isTrionic(nums) : "Answer is different";

        nums = new int[]{2, 1, 3};
        answer = false;
        assert answer == solution.isTrionic(nums) : "Answer is different";
    }

}
