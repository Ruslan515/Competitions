//https://leetcode.com/problems/increment-submatrices-by-one/description/?envType=daily-question&envId=2025-11-14
package leetcode.tasks;


import java.util.Arrays;

public class task_2536 {
    class Solution {
        public int[][] rangeAddQueries(int n, int[][] queries) {
            int[][] answer = new int[n][n];
            int row1, col1, row2, col2;
            for (int[] query : queries) {
                row1 = query[0];
                col1 = query[1];
                row2 = query[2];
                col2 = query[3];
                for (int i = row1; i <= row2; i++) {
                    for (int j = col1; j <= col2; j++) {
                        answer[i][j]++;
                    }
                }

            }

            return answer;
        }
    }

    public void main(String[] args) {
        int n;
        int[][] queries;
        int[][] answer;

        Solution solution = new Solution();

        n = 3;
        queries = new int[][]{{1, 1, 2, 2}, {0, 0, 1, 1}};
        answer = new int[][]{{1, 1, 0}, {1, 2, 1}, {0, 1, 1}};
        assert Arrays.deepEquals(answer, solution.rangeAddQueries(n, queries)) : "Answer is different";

        n = 2;
        queries = new int[][]{{0, 0, 1, 1}};
        answer = new int[][]{{1, 1}, {1, 1}};
        assert Arrays.deepEquals(answer, solution.rangeAddQueries(n, queries)) : "Answer is different";

    }

}
