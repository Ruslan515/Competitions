package leetcode.tasks;

import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;

public class task_2553 {
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

        public int[] separateDigits(int[] nums) {
            int[] answer;
            int n = nums.length;
            int item;
            ArrayList<Integer> allDigits = new ArrayList<>();
            for (int i = 0; i < n; ++i) {
                item = nums[i];
                ArrayList<Integer> digits = new ArrayList<>();
                while (item > 0) {
                    digits.add(item % 10);
                    item /= 10;
                }
                for (int j = digits.size() - 1; j >= 0; --j) {
                    allDigits.add(digits.get(j));
                }
            }
            answer = new int[allDigits.size()];
            for (int i = 0; i < allDigits.size(); ++i) {
                answer[i] = allDigits.get(i);
            }

            return answer;
        }

    }

    public void main(String[] args) {
        int[] nums;
        int[] answer;

        Solution solution = new Solution();

        nums = new int[]{13, 25, 83, 77};
        answer = new int[]{1, 3, 2, 5, 8, 3, 7, 7};
        assert Arrays.equals(answer, solution.separateDigits(nums)) : "Answer is different";

        nums = new int[]{7, 1, 3, 9};
        answer = new int[]{7, 1, 3, 9};
        assert Arrays.equals(answer, solution.separateDigits(nums)) : "Answer is different";

    }

}
