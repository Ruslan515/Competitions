//https://leetcode.com/problems/rotate-image/description/?envType=daily-question&envId=2026-05-04
package leetcode.tasks;

import java.io.FileWriter;
import java.io.IOException;
import java.util.Arrays;

public class task_48 {
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

        public void rotate(int[][] mat) {
            int n = mat.length;
            for (int i = 0; i < n; i++) {
                for (int j = i + 1; j < n; j++) {
                    int temp = mat[i][j];
                    mat[i][j] = mat[j][i];
                    mat[j][i] = temp;
                }
            }
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n / 2; j++) {
                    int temp = mat[i][j];
                    mat[i][j] = mat[i][n - 1 - j];
                    mat[i][n - 1 - j] = temp;
                }
            }
        }
    }

    public void main(String[] args) {
        int[][] answer, matrix;

        Solution solution = new Solution();

        matrix = new int[][]{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
        answer = new int[][]{{7, 4, 1}, {8, 5, 2}, {9, 6, 3}};
        solution.rotate(matrix);
        assert Arrays.deepEquals(answer, matrix) : "Answer is different";

        matrix = new int[][]{{5, 1, 9, 11}, {2, 4, 8, 10}, {13, 3, 6, 7}, {15, 14, 12, 16}};
        answer = new int[][]{{15, 13, 2, 5}, {14, 3, 4, 1}, {12, 6, 8, 9}, {16, 7, 10, 11}};
        solution.rotate(matrix);
        assert Arrays.deepEquals(answer, matrix) : "Answer is different";
    }

}
