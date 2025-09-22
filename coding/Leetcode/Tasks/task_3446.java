package leetcode.tasks;

import java.util.Arrays;
import java.util.Collection;
import java.util.Collections;

public class task_3446 {
    class Solution {
        public int[][] sortMatrix(int[][] grid) {
            int n = grid.length;
            // bottom-left triangle
            for (int numDiag = 0; numDiag < n - 1; ++numDiag) {
                int len = n - numDiag;
                Integer[] tmp = new Integer[len];
                int j;
                for (int i = numDiag; i < numDiag + len; ++i) {
                    j = i - numDiag;
                    tmp[i - numDiag] = grid[i][j];
                }
                Arrays.sort(tmp, Collections.reverseOrder());
                for (int i = numDiag; i < numDiag + len; ++i) {
                    j = i - numDiag;
                    grid[i][j] = tmp[i - numDiag];
                }

            }

            // top-right triangle
            for (int numDiag = 1; numDiag < n - 1; ++numDiag) {
                int len = n - numDiag;
                int[] tmp = new int[len];
                int i;
                for (int j = numDiag; j < numDiag + len; ++j) {
                    i = j - numDiag;
                    tmp[j - numDiag] = grid[i][j];
                }
                Arrays.sort(tmp);
                for (int j = numDiag; j < numDiag + len; ++j) {
                    i = j - numDiag;
                    grid[i][j] = tmp[j - numDiag];
                }

            }

            return grid;
        }

    }

    public void main(String[] args) {
        int[][] grid;
        int[][] answer;

        Solution solution = new Solution();

        grid = new int[][]{{1, 7, 3}, {9, 8, 2}, {4, 5, 6}};
        answer = new int[][]{{8, 2, 3}, {9, 6, 7}, {4, 5, 1}};
        assert Arrays.deepEquals(answer, solution.sortMatrix(grid)) : "Answer is different";

        grid = new int[][]{{0, 1}, {1, 2}};
        answer = new int[][]{{2, 1}, {1, 0}};
        assert Arrays.deepEquals(answer, solution.sortMatrix(grid)) : "Answer is different";

        grid = new int[][]{{1}};
        answer = new int[][]{{1}};
        assert Arrays.deepEquals(answer, solution.sortMatrix(grid)) : "Answer is different";

    }

}
