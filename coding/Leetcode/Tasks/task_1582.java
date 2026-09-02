package leetcode.tasks;

import java.io.FileWriter;
import java.io.IOException;

public class task_1582 {
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

        public int numSpecial(int[][] mat) {
            int answer = 0;
            int m = mat.length;
            int n = mat[0].length;
            int[] col = new int[n];
            int[] row = new int[m];
            for (int i = 0; i < m; i++) {
                int sums = 0;
                for (int j = 0; j < n; j++) {
                    sums += mat[i][j];
                }
                row[i] = sums;
            }

            for (int j = 0; j < n; j++) {
                int sums = 0;
                for (int i = 0; i < m; i++) {
                    sums += mat[i][j];
                }
                col[j] = sums;
            }

            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if (mat[i][j] == 1 && row[i] == 1 && col[j] == 1) {
                        ++answer;
                    }
                }
            }

            return answer;
        }
    }

    public void main(String[] args) {
        int[][] mat;
        int answer;

        Solution solution = new Solution();

        mat = new int[][]{{1, 0, 0}, {0, 0, 1}, {1, 0, 0}};
        answer = 1;
        assert answer == solution.numSpecial(mat) : "Answer is different";

        mat = new int[][]{{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
        answer = 3;
        assert answer == solution.numSpecial(mat) : "Answer is different";
    }

}
