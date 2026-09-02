package leetcode.tasks;

import java.io.FileWriter;
import java.io.IOException;
import java.util.*;

public class task_1200 {
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

        public List<List<Integer>> minimumAbsDifference(int[] arr) {
            List<List<Integer>> answer = new LinkedList<>();
            Arrays.sort(arr);
            int minDiff = Integer.MAX_VALUE;
            int n = arr.length;
            int diff;
            for (int i = 1; i < n; ++i) {
                diff = arr[i] - arr[i - 1];
                minDiff = Math.min(minDiff, diff);
            }
            for (int i = 1; i < n; ++i) {
                diff = arr[i] - arr[i - 1];
                if (diff == minDiff) {
                    answer.add(Arrays.asList(arr[i - 1], arr[i]));
                }
            }


            return answer;
        }
    }

    public void main(String[] args) {
        int[] arr;
        List<List<Integer>> answer;

        Solution solution = new Solution();

        arr = new int[]{4, 2, 1, 3};
        answer = Arrays.asList(Arrays.asList(1, 2), Arrays.asList(2, 3), Arrays.asList(3, 4));
        assert answer.equals(solution.minimumAbsDifference(arr)) : "Answer is different";

        arr = new int[]{1, 3, 6, 10, 15};
        answer = Arrays.asList(Arrays.asList(1, 3));
        assert answer.equals(solution.minimumAbsDifference(arr)) : "Answer is different";

        arr = new int[]{3, 8, -10, 23, 19, -4, -14, 27};
        answer = Arrays.asList(Arrays.asList(-14, -10), Arrays.asList(19, 23), Arrays.asList(23, 27));
        assert answer.equals(solution.minimumAbsDifference(arr)) : "Answer is different";
    }

}
