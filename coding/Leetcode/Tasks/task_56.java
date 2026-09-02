//https://leetcode.com/problems/merge-intervals/description/
package leetcode.tasks;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.Map;

public class task_56 {
    class Solution {
        public int[][] merge(int[][] intervals) {
            ArrayList<ArrayList<Integer>> answer = new ArrayList<>();

            Arrays.sort(
                    intervals,
                    new Comparator<int[]>() {
                        @Override
                        public int compare(int[] o1, int[] o2) {
                            if (o1[0] != o2[0]) {
                                return o1[0] - o2[0];
                            } else {
                                return o1[1] - o2[1];
                            }
                        }
                    }
            );

            int[] item = intervals[0];
            int n = intervals.length;
            int[] current;
            int l1, l2, r1, r2;
            for (int i = 1; i < n; ++i) {
                current = intervals[i];
                r1 = item[1];
                l1 = item[0];
                r2 = current[1];
                l2 = current[0];
                if (r1 >= l2) {
                    item[1] = Math.max(r1, r2);
                } else {
                    answer.add(new ArrayList<>(Arrays.asList(item[0], item[1])));
                    item = current;
                }
            }
            answer.add(new ArrayList<>(Arrays.asList(item[0], item[1])));

            return answer.stream().map(
                    row -> row
                            .stream()
                            .mapToInt(Integer::intValue)
                            .toArray()
            ).toArray(int[][]::new);
        }
    }

    public void main(String[] args) {
        int[][] intervals;
        int[][] answer;

        Solution solution = new Solution();

        intervals = new int[][]{{1, 4}, {2, 3}};
        answer = new int[][]{{1, 4}};
        assert Arrays.deepEquals(answer, solution.merge(intervals)) : "Answer is different";

        intervals = new int[][]{{1, 4}, {4, 5}};
        answer = new int[][]{{1, 5}};
        assert Arrays.deepEquals(answer, solution.merge(intervals)) : "Answer is different";

        intervals = new int[][]{{1, 3}, {2, 6}, {8, 10}, {15, 18}};
        answer = new int[][]{{1, 6}, {8, 10}, {15, 18}};
        assert Arrays.deepEquals(answer, solution.merge(intervals)) : "Answer is different";

        intervals = new int[][]{{4, 7}, {1, 4}};
        answer = new int[][]{{1, 7}};
        assert Arrays.deepEquals(answer, solution.merge(intervals)) : "Answer is different";


        intervals = new int[][]{{4, 7}, {1, 5}, {4, 6}};
        answer = new int[][]{{1, 7}};
        assert Arrays.deepEquals(answer, solution.merge(intervals)) : "Answer is different";


    }


}
