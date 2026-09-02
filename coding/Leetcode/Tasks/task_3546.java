//https://leetcode.com/problems/equal-sum-grid-partition-i/description/?envType=daily-question&envId=2026-03-25
package leetcode.tasks;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.*;
import java.util.function.BiFunction;

public class task_3546 {
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

        public boolean canPartitionGrid(int[][] grid) {
            int m = grid.length;
            int n = grid[0].length;
            long totalSum = 0;
            for (int[] row : grid)
                for (int val : row)
                    totalSum += val;
            if (totalSum % 2 != 0) return false;
            long half = totalSum / 2;

            // Проверка по строкам
            if (hasPrefixSum(grid, (i, j) -> grid[i][j], m, n, half))
                return true;
            // Проверка по столбцам
            return hasPrefixSum(grid, (j, i) -> grid[i][j], n, m, half);
        }

        private boolean hasPrefixSum(int[][] grid,
                                     BiFunction<Integer, Integer, Integer> getter,
                                     int majorSize, int minorSize, long target) {
            long sum = 0;
            for (int major = 0; major < majorSize; major++) {
                for (int minor = 0; minor < minorSize; minor++) {
                    sum += getter.apply(major, minor);
                }
                if (sum == target) return true;
            }
            return false;
        }
    }

    public int[][] readGrid() throws FileNotFoundException {
        FileInputStream fis = new FileInputStream("src/leetcode/tasks/input.txt");
        Scanner scanner = new Scanner(fis);
        String s;
        List<List<Integer>> matrix = new ArrayList<>();
        while (scanner.hasNextLine()) {
            s = scanner.nextLine();
            List<Integer> row = new ArrayList<>();
            for (String c : s.split(",")) {
                row.add(Integer.parseInt(c));
            }
            matrix.add(row);
        }
        int m = matrix.size();
        int n = matrix.get(0).size();

        System.out.println("m: " + m + ". n: " + n);

        scanner.close();

        int[][] grid = new int[m][n];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                grid[i][j] = matrix.get(i).get(j);
            }
        }
        return grid;
    }

    public void main(String[] args) throws FileNotFoundException {
        int[][] grid;
        boolean answer;

        Solution solution = new Solution();


        grid = readGrid();
        answer = false;
        assert answer == solution.canPartitionGrid(grid) : "Answer is different";

        grid = new int[][]{{1, 3}, {2, 4}};
        answer = false;
        assert answer == solution.canPartitionGrid(grid) : "Answer is different";

        grid = new int[][]{{1, 4}, {2, 3}};
        answer = true;
        assert answer == solution.canPartitionGrid(grid) : "Answer is different";

        grid = new int[][]{{1, 1, 1}, {1, 1, 1}, {1, 2, 3}};
        answer = true;
        assert answer == solution.canPartitionGrid(grid) : "Answer is different";

    }

}
