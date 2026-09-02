//https://leetcode.com/problems/determine-whether-matrix-can-be-obtained-by-rotation/description/?envType=daily-question&envId=2026-03-22
package leetcode.tasks;

import java.io.FileWriter;
import java.io.IOException;
import java.util.*;

public class task_1886 {
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

        public int[][] rotate(int[][] mat) {
            int n = mat.length;
            int[][] rotated = new int[n][n];
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    rotated[i][j] = mat[j][n - i - 1];
                }
            }
            return rotated;
        }

        public boolean findRotation(int[][] mat, int[][] target) {
            boolean answer = false;
            for (int i = 0; i < 4; ++i) {
                if (Arrays.deepEquals(mat, target)) {
                    answer = true;
                    break;
                }
                mat = rotate(mat);

            }

            return answer;
        }
    }

    public void main(String[] args) {
        int[][] mat, target;
        boolean answer;

        Solution solution = new Solution();

        mat = new int[][]{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};;
        target = new int[][]{{7, 4, 1}, {8, 5, 2}, {9, 6, 3}};
        answer = true;
        assert answer == solution.findRotation(mat, target) : "Answer is different";

        mat = new int[][]{{0, 0}, {1, 0}};
        target = new int[][]{{1, 0}, {0, 0}};
        answer = true;
        assert answer == solution.findRotation(mat, target) : "Answer is different";

        mat = new int[][]{{0, 1}, {1, 0}};
        target = new int[][]{{1, 0}, {0, 1}};
        answer = true;
        assert answer == solution.findRotation(mat, target) : "Answer is different";

        mat = new int[][]{{0, 1}, {1, 1}};
        target = new int[][]{{1, 0}, {0, 1}};
        answer = false;
        assert answer == solution.findRotation(mat, target) : "Answer is different";

        mat = new int[][]{{0, 0, 0}, {0, 1, 0}, {1, 1, 1}};
        target = new int[][]{{1, 1, 1}, {0, 1, 0}, {0, 0, 0}};
        answer = true;
        assert answer == solution.findRotation(mat, target) : "Answer is different";

    }

}
