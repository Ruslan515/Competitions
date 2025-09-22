package leetcode.tasks;

public class task_1504 {
    class Solution {
        public int countSquares(int[][] matrix) {
            int row = matrix.length, col = matrix[0].length;
            int[][] dp = new int[row + 1][col + 1];
            int ans = 0;
            for (int i = 0; i < row; i++) {
                for (int j = 0; j < col; j++) {
                    if (matrix[i][j] == 1) {
                        dp[i + 1][j + 1] =
                                Math.min(
                                        Math.min(dp[i][j + 1], dp[i + 1][j]),
                                        dp[i][j]
                                ) + 1;
                        if (dp[i + 1][j + 1] != 1) {
                            ans += dp[i + 1][j + 1];
                        }
                    }
                }
            }
            return ans;
        }

        public int countRectRows(int[][] matrix) {
            int row = matrix.length, col = matrix[0].length;
            int[][] dp = new int[row + 1][col + 1];
            int ans = 0;
            for (int i = 0; i < row; i++) {
                for (int j = 0; j < col; j++) {
                    if (matrix[i][j] == 1) {
                        dp[i + 1][j + 1] = dp[i + 1][j] + 1;
                        if (dp[i + 1][j + 1] != 1) {
                            ans += dp[i + 1][j + 1];
                        }
                    }
                }
            }
            return ans;
        }

        public int countRectCols(int[][] matrix) {
            int row = matrix.length, col = matrix[0].length;
            int[][] dp = new int[row + 1][col + 1];
            int ans = 0;
            for (int j = 0; j < col; j++) {
                for (int i = 0; i < row; i++) {
                    if (matrix[i][j] == 1) {
                        dp[i + 1][j + 1] = dp[i][j + 1] + 1;
                        if (dp[i + 1][j + 1] != 1) {
                            ans += dp[i + 1][j + 1];
                        }
                    }
                }
            }
            return ans;
        }

        public int numSubmat(int[][] mat) {
            int answer = 0;
            int cntSquare = this.countSquares(mat);
            int cntRectRows = this.countRectCols(mat);
            int cntRectCols = this.countRectRows(mat);
            answer += cntSquare + cntRectRows + cntRectCols;

            return answer;
        }
    }

    public void main(String[] args) {
        int[][] mat;
        int answer;

        Solution solution = new Solution();

        mat = new int[][]{{0, 1, 1, 0}, {0, 1, 1, 1}, {1, 1, 1, 0}};
        answer = 24;
        assert answer == solution.numSubmat(mat) : "Answer is different";

        mat = new int[][]{{1, 0, 1}, {1, 1, 0}, {1, 1, 0}};
        answer = 13;
        assert answer == solution.numSubmat(mat) : "Answer is different";
    }

}
