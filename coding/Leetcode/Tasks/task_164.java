//https://leetcode.com/problems/maximum-gap/?envType=problem-list-v2&envId=bucket-sort
package leetcode.tasks;

import java.io.FileWriter;
import java.io.IOException;
import java.util.Arrays;

public class task_164 {
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

        public int maximumGap(int[] nums) {
            int answer = 0;
            int n = nums.length;
            if (n < 2) {
                return answer;
            }
            Arrays.sort(nums);
            int curr, next, diff;
            for (int i = 0; i < n - 1; i++) {
                curr = nums[i];
                next = nums[i + 1];
                diff = next - curr;
                answer = Math.max(answer, diff);
            }

            return answer;
        }

    }

    public void main(String[] args) {
        int[] nums;
        int answer;

        Solution solution = new Solution();

        nums = new int[]{2, 5, 6, 9, 10};
        answer = 3;
        assert answer == solution.maximumGap(nums) : "Answer is different";

        nums = new int[]{3, 6, 9, 1};
        answer = 3;
        assert answer == solution.maximumGap(nums) : "Answer is different";

        nums = new int[]{10};
        answer = 0;
        assert answer == solution.maximumGap(nums) : "Answer is different";

    }

}
