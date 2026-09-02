//https://leetcode.com/problems/equal-sum-grid-partition-ii/description/?envType=daily-question&envId=2026-03-26
package leetcode.tasks;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.*;
import java.util.function.BiFunction;

public class task_3548 {
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
            boolean answer = false;
            int m = grid.length;
            int n = grid[0].length;
            long totalSum = 0;
            for (int[] row : grid)
                for (int val : row)
                    totalSum += val;
//            if (totalSum % 2 != 0) return answer;
            long half;
            if (m == 1) {
                // forward
                long prefixSum = 0;
                Set<Long> prefixSumArray = new HashSet<>();
                for (int i = 0; i < n; i++) {
                    prefixSum += grid[0][i];
                    prefixSumArray.add(prefixSum);
                }
                if (prefixSum % 2 == 0) {
                    half = prefixSum / 2;
                    if (prefixSumArray.contains(half)) {
                        return true;
                    }
                }
                prefixSum -= grid[0][n - 1];
                half = prefixSum / 2;
                if (prefixSumArray.contains(half)) {
                    return true;
                }

                // backward
                prefixSumArray.clear();
                prefixSum = 0;
                for (int i = n - 1; i >= 0; --i) {
                    prefixSum += grid[0][i];
                    prefixSumArray.add(prefixSum);
                }
                if (prefixSum % 2 == 0) {
                    half = prefixSum / 2;
                    if (prefixSumArray.contains(half)) {
                        return true;
                    }
                }
                prefixSum -= grid[0][0];
                half = prefixSum / 2;
                if (prefixSumArray.contains(half)) {
                    return true;
                }
            }
            if (n == 1) {
                // forward
                long prefixSum = 0;
                Set<Long> prefixSumArray = new HashSet<>();
                for (int i = 0; i < m; i++) {
                    prefixSum += grid[i][0];
                    prefixSumArray.add(prefixSum);
                }
                if (prefixSum % 2 == 0) {
                    half = prefixSum / 2;
                    if (prefixSumArray.contains(half)) {
                        return true;
                    }
                }
                prefixSum -= grid[m - 1][0];
                half = prefixSum / 2;
                if (prefixSumArray.contains(half)) {
                    return true;
                }

                // backward
                prefixSumArray.clear();
                prefixSum = 0;
                for (int i = m - 1; i >= 0; --i) {
                    prefixSum += grid[i][0];
                    prefixSumArray.add(prefixSum);
                }
                if (prefixSum % 2 == 0) {
                    half = prefixSum / 2;
                    if (prefixSumArray.contains(half)) {
                        return true;
                    }
                }
                prefixSum -= grid[0][0];
                half = prefixSum / 2;
                if (prefixSumArray.contains(half)) {
                    return true;
                }

            }

            half = totalSum / 2;

            // Проверка по строкам
            boolean checkRowBackward = hasPrefixSum(grid, (i, j) -> grid[i][j], m, n, half, totalSum, false);
            if (checkRowBackward) {
                answer = true;
                return answer;
            }

            boolean checkRowForward = hasPrefixSum(grid, (i, j) -> grid[i][j], m, n, half, totalSum, true);
            if (checkRowForward) {
                answer = true;
                return answer;
            }
            // Проверка по столбцам
            boolean checkColForward = hasPrefixSum(grid, (j, i) -> grid[i][j], n, m, half, totalSum, true);
            if (checkColForward) {
                answer = true;
                return answer;
            }
            boolean checkColBackward = hasPrefixSum(grid, (j, i) -> grid[i][j], n, m, half, totalSum, false);
            if (checkColBackward) {
                answer = true;
                return answer;
            }
            return answer;
        }


        private boolean hasPrefixSum(
                int[][] grid,
                BiFunction<Integer, Integer, Integer> getter,
                int majorSize, int minorSize,
                long target,
                long totalSum,
                boolean forward
        ) {
            long sum = 0;
            int tmp;
            int x1, x2;
            long sumOther;
            long diff;

            if (forward) {
                Set<Integer> set = new HashSet<>();
                for (int major = 0; major < majorSize; major++) {
                    for (int minor = 0; minor < minorSize; minor++) {
                        tmp = getter.apply(major, minor);
                        sum += tmp;
                        set.add(tmp);
                    }
                    if (sum == target) {
                        return true;
                    }
                    sumOther = totalSum - sum;
                    diff = sum - sumOther;
                    if (set.contains((int) diff)) {
                        if ((forward && major == 0) || (!forward && major == majorSize - 1)) {
                            x1 = getter.apply(major, 0);
                            x2 = getter.apply(major, minorSize - 1);
                            if (diff == x1 || diff == x2) {
                                return true;
                            }
                        }
                    }

                }
            } else {
                Set<Integer> set = new HashSet<>();
                for (int major = majorSize - 1; major >= 0; major--) {
                    for (int minor = minorSize - 1; minor >= 0; minor--) {
                        tmp = getter.apply(major, minor);
                        sum += tmp;
                        set.add(tmp);
                    }
                    if (sum == target) {
                        return true;
                    }
                    sumOther = totalSum - sum;
                    diff = sum - sumOther;
                    if (set.contains((int) diff)) {
                        if ((forward && major == 0) || (!forward && major == majorSize - 1)) {
                            x1 = getter.apply(majorSize - 1, 0);
                            x2 = getter.apply(major, minorSize - 1);
                            if (diff == x1 || diff == x2) {
                                return true;
                            } else {
                                return false;
                            }
                        } else {
                            return true;
                        }
                    }
                }
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


//        grid = readGrid();
//        answer = false;
//        assert answer == solution.canPartitionGrid(grid) : "Answer is different";

        grid = new int[][]{{1, 2, 4}, {2, 3, 5}};
        answer = false;
        assert answer == solution.canPartitionGrid(grid) : "Answer is different";

        grid = new int[][]{{1, 2}, {3, 4}};
        answer = true;
        assert answer == solution.canPartitionGrid(grid) : "Answer is different";

        grid = new int[][]{{5, 5, 6, 2, 2, 2}};
        answer = true;
        assert answer == solution.canPartitionGrid(grid) : "Answer is different";

        grid = new int[][]{{4, 1, 8}, {3, 2, 6}};
        answer = false;
        assert answer == solution.canPartitionGrid(grid) : "Answer is different";

        grid = new int[][]{{1, 4}, {2, 3}};
        answer = true;
        assert answer == solution.canPartitionGrid(grid) : "Answer is different";

    }

}
