package leetcode.tasks;

import java.util.Arrays;
import java.util.HashSet;

public class task_73 {
    class Solution {
        public void setZeroes(int[][] matrix) {
            HashSet<Integer> rows = new HashSet<>();
            HashSet<Integer> cols = new HashSet<>();
            int m = matrix.length;
            int n = matrix[0].length;
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if (matrix[i][j] == 0) {
                        rows.add(i);
                        cols.add(j);
                    }
                }
            }
            for (Integer row : rows) {
                for (int j = 0; j < n; j++) {
                    matrix[row][j] = 0;
                }
            }
            for (Integer col : cols) {
                for (int i = 0; i < m; i++) {
                    matrix[i][col] = 0;
                }
            }
        }

    }

    public static void main(String[] args) {
        int[][] matrix;
        int[][] answer;

        Solution solution = new task_73().new Solution();

        matrix = new int[][]{{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
        answer = new int[][]{{1, 0, 1}, {0, 0, 0}, {1, 0, 1}};
        solution.setZeroes(matrix);
        assert Arrays.deepEquals(answer, matrix) : "Answer is different";

        matrix = new int[][]{{0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}};
        answer = new int[][]{{0, 0, 0, 0}, {0, 4, 5, 0}, {0, 3, 1, 0}};
        solution.setZeroes(matrix);
        assert Arrays.deepEquals(answer, matrix) : "Answer is different";

    }
}
