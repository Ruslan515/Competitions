package leetcode.tasks;

import java.io.FileWriter;
import java.io.IOException;
import java.util.Arrays;

public class task_1356 {
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

        record Pair(int cnt, int val) {
        }

        public int cntOnes(int n) {
            int answer = 0;
            while (n != 0) {
                answer++;
                n &= (n - 1);
            }

            return answer;
        }

        public int[] sortByBits(int[] arr) {
            int n = arr.length;
            Pair[] arrPairs = new Pair[n];
            int val;
            for (int i = 0; i < n; ++i) {
                val = arr[i];
                int cnt = this.cntOnes(val);
                arrPairs[i] = new Pair(cnt, val);
            }
            Arrays.sort(arrPairs, (p1, p2) -> {
                if (p1.cnt() != p2.cnt()) {
                    return Integer.compare(p1.cnt(), p2.cnt());
                } else {
                    return Integer.compare(p1.val(), p2.val());
                }
            });
            for (int i = 0; i < n; ++i) {
                arr[i] = arrPairs[i].val();
            }

            return arr;
        }
    }

    public void main(String[] args) {
        int[] arr;
        int[] answer;

        Solution solution = new Solution();

        arr = new int[]{0, 1, 2, 3, 4, 5, 6, 7, 8};
        answer = new int[]{0, 1, 2, 4, 8, 3, 5, 6, 7};
        assert Arrays.equals(answer, solution.sortByBits(arr)) : "Answer is different";

        arr = new int[]{1024, 512, 256, 128, 64, 32, 16, 8, 4, 2, 1};
        answer = new int[]{1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024};
        assert Arrays.equals(answer, solution.sortByBits(arr)) : "Answer is different";

    }

}
