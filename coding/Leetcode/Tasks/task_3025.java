package leetcode.tasks;

import java.util.Arrays;
import java.util.Comparator;

public class task_3025 {
    class Solution {
        public int numberOfPairs(int[][] points) {
            int answer = 0;
            Arrays.sort(
                    points,
                    new Comparator<int[]>() {
                        @Override
                        public int compare(int[] o1, int[] o2) {
                            if (o1[0] != o2[0]) {
                                return Integer.compare(o1[0], o2[0]);
                            } else {
                                return Integer.compare(o2[1], o1[1]);
                            }
                        }
                    }
            );

            int n = points.length;
            int a_x, a_y, b_x, b_y, z_x, z_y;
            for (int i = 0; i < n - 1; i++) {
                a_x = points[i][0];
                a_y = points[i][1];
                for (int j = i + 1; j < n; j++) {
                    b_x = points[j][0];
                    b_y = points[j][1];
                    if (!(a_x <= b_x && a_y >= b_y)) {
                        continue;
                    }
                    boolean label = true;
                    for (int k = i + 1; k < j; k++) {
                        z_x = points[k][0];
                        z_y = points[k][1];
                        if (a_x <= z_x && z_x <= b_x && b_y <= z_y && z_y <= a_y) {
                            label = false;
                            break;
                        }
                    }
                    if (label) {
                        ++answer;
                    }
                }
            }

            return answer;
        }

    }

    public void main(String[] args) {
        int[][] points;
        int answer;

        Solution solution = new Solution();

        points = new int[][]{{0, 1}, {1, 3}, {6, 1}};
        answer = 2;
        assert answer == solution.numberOfPairs(points) : "Answer is different";

        points = new int[][]{{6, 2}, {4, 4}, {2, 6}};
        answer = 2;
        assert answer == solution.numberOfPairs(points) : "Answer is different";

        points = new int[][]{{1, 1}, {2, 2}, {3, 3}};
        answer = 0;
        assert answer == solution.numberOfPairs(points) : "Answer is different";

        points = new int[][]{{3, 1}, {1, 3}, {1, 1}};
        answer = 2;
        assert answer == solution.numberOfPairs(points) : "Answer is different";


    }

}
