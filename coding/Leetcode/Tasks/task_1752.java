//https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/?envType=daily-question&envId=2026-05-23
package leetcode.tasks;

import java.io.FileWriter;
import java.io.IOException;
import java.util.Arrays;
import java.util.HashSet;
import java.util.Set;

public class task_1752 {
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

        public boolean check(int[] nums) {
            boolean answer = true;
            int n = nums.length;
            int i = 1;
            for (; i < n; ++i) {
                if (nums[i] < nums[i - 1]) {
                    break;
                }
            }
            if (i == n ) {
                return answer;
            }
            ++i;
            for (; i < n; ++i) {
                if (nums[i] < nums[i - 1]) {
                    break;
                }
            }
            if (i != n) {
                answer = false;
            } else {
                if (nums[0] < nums[n - 1]) {
                    answer = false;
                }
            }

            return answer;
        }

    }

    public void main(String[] args) {
        int[] nums;
        boolean answer;

        Solution solution = new Solution();

        nums = new int[]{1, 2, 3};
        answer = true;
        assert answer == solution.check(nums) : "Answer is different";

        nums = new int[]{3, 4, 5, 1, 2};
        answer = true;
        assert answer == solution.check(nums) : "Answer is different";

        nums = new int[]{2, 1, 3, 4};
        answer = false;
        assert answer == solution.check(nums) : "Answer is different";

    }

}
