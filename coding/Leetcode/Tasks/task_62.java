//https://leetcode.com/problems/unique-paths/description/
package leetcode.tasks;

public class task_62 {    class Solution {
    public int uniquePaths(int m, int n) {
        int answer = 0;
        int[][] dp = new int[m][n];
        for (int i = 0; i < m; i++) {
            dp[i][0] = 1;
        }
        for (int j = 0; j < n; j++) {
            dp[0][j] = 1;
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        answer = dp[m - 1][n - 1];

        return answer;
    }
}

    public void main(String[] args) {
        int m, n;
        int answer;

        Solution solution = new Solution();

        m = 3;
        n = 7;
        answer = 28;
        assert answer == solution.uniquePaths(m, n) : "Answer is different";

        m = 3;
        n = 2;
        answer = 3;
        assert answer == solution.uniquePaths(m, n) : "Answer is different";
    }


}
